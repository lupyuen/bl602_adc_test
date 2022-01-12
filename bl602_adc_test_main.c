/****************************************************************************
 * apps/examples/bl602_adc_test/bl602_adc_test_main.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

//  Demo Program for BL602 ADC on NuttX
#include <nuttx/config.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "../libs/libbl602_adc/bl602_adc.h"
#include "../libs/libbl602_adc/bl602_glb.h"

static int get_tsen_adc(float *temp, uint8_t log_flag);

int main(int argc, FAR char *argv[]) {
    //  Test 10 times
    for (int i = 0; i < 10; i++) {
        //  Read the Internal Temperature Sensor
        float temp;
        int rc = get_tsen_adc(&temp, 1);
        assert(rc == 0);

        //  Show the temperature
        printf("Internal Temperature: %f deg C\n", temp);

        //  Sleep 5 seconds
        sleep(5);
    }
    return 0;
}

/// Read the Internal Temperature Sensor as Float. Returns 0 if successful.
/// Based on bl_tsen_adc_get in https://github.com/lupyuen/bl_iot_sdk/blob/tsen/components/hal_drv/bl602_hal/bl_adc.c#L224-L282
static int get_tsen_adc(
    float *temp,      //  Pointer to float to store the temperature
    uint8_t log_flag  //  0 to disable logging, 1 to enable logging
) {
    assert(temp != NULL);
    static uint16_t tsen_offset = 0xFFFF;
    float val = 0.0;

    //  If the offset has not been fetched...
    if (0xFFFF == tsen_offset) {
        //  Define the ADC configuration
        tsen_offset = 0;
        ADC_CFG_Type adcCfg = {
            .v18Sel=ADC_V18_SEL_1P82V,                /*!< ADC 1.8V select */
            .v11Sel=ADC_V11_SEL_1P1V,                 /*!< ADC 1.1V select */
            .clkDiv=ADC_CLK_DIV_32,                   /*!< Clock divider */
            .gain1=ADC_PGA_GAIN_1,                    /*!< PGA gain 1 */
            .gain2=ADC_PGA_GAIN_1,                    /*!< PGA gain 2 */
            .chopMode=ADC_CHOP_MOD_AZ_PGA_ON,         /*!< ADC chop mode select */
            .biasSel=ADC_BIAS_SEL_MAIN_BANDGAP,       /*!< ADC current form main bandgap or aon bandgap */
            .vcm=ADC_PGA_VCM_1V,                      /*!< ADC VCM value */
            .vref=ADC_VREF_2V,                        /*!< ADC voltage reference */
            .inputMode=ADC_INPUT_SINGLE_END,          /*!< ADC input signal type */
            .resWidth=ADC_DATA_WIDTH_16_WITH_256_AVERAGE,  /*!< ADC resolution and oversample rate */
            .offsetCalibEn=0,                         /*!< Offset calibration enable */
            .offsetCalibVal=0,                        /*!< Offset calibration value */
        };
        ADC_FIFO_Cfg_Type adcFifoCfg = {
            .fifoThreshold = ADC_FIFO_THRESHOLD_1,
            .dmaEn = DISABLE,
        };

        //  Enable and reset the ADC
        GLB_Set_ADC_CLK(ENABLE,GLB_ADC_CLK_96M, 7);
        ADC_Disable();
        ADC_Enable();
        ADC_Reset();

        //  Configure the ADC and Internal Temperature Sensor
        ADC_Init(&adcCfg);
        ADC_Channel_Config(ADC_CHAN_TSEN_P, ADC_CHAN_GND, 0);
        ADC_Tsen_Init(ADC_TSEN_MOD_INTERNAL_DIODE);
        ADC_FIFO_Cfg(&adcFifoCfg);

        //  Fetch the offset
        BL_Err_Type rc = ADC_Trim_TSEN(&tsen_offset);
        assert(rc != BL_ERROR);  //  Read efuse data failed

        //  Must wait 100 milliseconds or returned temperature will be negative
        usleep(100 * 1000);
    }
    //  Read the temperature based on the offset
    val = TSEN_Get_Temp(tsen_offset);
    if (log_flag) {
        printf("offset = %d\r\n", tsen_offset);
        printf("temperature = %f Celsius\r\n", val);
    }
    //  Return the temperature
    *temp = val;
    return 0;
}
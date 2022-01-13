# Test App for BL602 ADC and Temperature Sensor Library for Apache NuttX OS

This repo depends on...

-   [lupyuen/bl602_adc](https://github.com/lupyuen/bl602_adc)

To add this repo to your NuttX project...

```bash
cd nuttx/apps/examples
git submodule add https://github.com/lupyuen/bl602_adc_test
```

Then update the NuttX Build Config...

```bash
## TODO: Change this to the path of our "incubator-nuttx" folder
cd nuttx/nuttx

## Preserve the Build Config
cp .config ../config

## Erase the Build Config
make distclean

## For BL602: Configure the build for BL602
./tools/configure.sh bl602evb:nsh

## For ESP32: Configure the build for ESP32.
## TODO: Change "esp32-devkitc" to our ESP32 board.
./tools/configure.sh esp32-devkitc:nsh

## Restore the Build Config
cp ../config .config

## Edit the Build Config
make menuconfig 
```

In menuconfig, enable the BL602 ADC Test App under "Application Configuration" → "Examples".

In NuttX Shell, enter this to run the app...

```bash
bl602_adc_test
```

# Output Log

```text
nsh> bl602_adc_test
offset = 2209
temperature = 14.317039 Celsius
Internal Temperature: 14.317039 deg C
offset = 2209
temperature = 14.575004 Celsius
Internal Temperature: 14.575004 deg C
offset = 2209
temperature = 14.832968 Celsius
Internal Temperature: 14.832968 deg C
offset = 2209
temperature = 15.993809 Celsius
Internal Temperature: 15.993809 deg C
offset = 2209
temperature = 14.317039 Celsius
Internal Temperature: 14.317039 deg C
offset = 2209
temperature = 15.090933 Celsius
Internal Temperature: 15.090933 deg C
offset = 2209
temperature = 16.509739 Celsius
Internal Temperature: 16.509739 deg C
offset = 2209
temperature = 13.672127 Celsius
Internal Temperature: 13.672127 deg C
offset = 2209
temperature = 13.414163 Celsius
Internal Temperature: 13.414163 deg C
offset = 2209
temperature = 15.348897 Celsius
Internal Temperature: 15.348897 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 15.606862 Celsius
Internal Temperature: 15.606862 deg C
offset = 2209
temperature = 15.477880 Celsius
Internal Temperature: 15.477880 deg C
offset = 2209
temperature = 15.606862 Celsius
Internal Temperature: 15.606862 deg C
offset = 2209
temperature = 13.672127 Celsius
Internal Temperature: 13.672127 deg C
offset = 2209
temperature = 13.930092 Celsius
Internal Temperature: 13.930092 deg C
offset = 2209
temperature = 14.317039 Celsius
Internal Temperature: 14.317039 deg C
offset = 2209
temperature = 15.219914 Celsius
Internal Temperature: 15.219914 deg C
offset = 2209
temperature = 15.477880 Celsius
Internal Temperature: 15.477880 deg C
offset = 2209
temperature = 14.961950 Celsius
Internal Temperature: 14.961950 deg C
offset = 2209
temperature = 15.477880 Celsius
Internal Temperature: 15.477880 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 15.864826 Celsius
Internal Temperature: 15.864826 deg C
offset = 2209
temperature = 17.412615 Celsius
Internal Temperature: 17.412615 deg C
offset = 2209
temperature = 16.509739 Celsius
Internal Temperature: 16.509739 deg C
offset = 2209
temperature = 19.476332 Celsius
Internal Temperature: 19.476332 deg C
offset = 2209
temperature = 16.638720 Celsius
Internal Temperature: 16.638720 deg C
offset = 2209
temperature = 18.057526 Celsius
Internal Temperature: 18.057526 deg C
offset = 2209
temperature = 18.315491 Celsius
Internal Temperature: 18.315491 deg C
offset = 2209
temperature = 15.348897 Celsius
Internal Temperature: 15.348897 deg C
offset = 2209
temperature = 15.735845 Celsius
Internal Temperature: 15.735845 deg C
offset = 2209
temperature = 18.186508 Celsius
Internal Temperature: 18.186508 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 17.025667 Celsius
Internal Temperature: 17.025667 deg C
offset = 2209
temperature = 20.379208 Celsius
Internal Temperature: 20.379208 deg C
offset = 2209
temperature = 15.735845 Celsius
Internal Temperature: 15.735845 deg C
offset = 2209
temperature = 15.735845 Celsius
Internal Temperature: 15.735845 deg C
offset = 2209
temperature = 17.928543 Celsius
Internal Temperature: 17.928543 deg C
offset = 2209
temperature = 17.799561 Celsius
Internal Temperature: 17.799561 deg C
offset = 2209
temperature = 16.896685 Celsius
Internal Temperature: 16.896685 deg C
offset = 2209
temperature = 16.380756 Celsius
Internal Temperature: 16.380756 deg C
offset = 2209
temperature = 15.606862 Celsius
Internal Temperature: 15.606862 deg C
offset = 2209
temperature = 16.380756 Celsius
Internal Temperature: 16.380756 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 17.670580 Celsius
Internal Temperature: 17.670580 deg C
offset = 2209
temperature = 18.057526 Celsius
Internal Temperature: 18.057526 deg C
offset = 2209
temperature = 18.702438 Celsius
Internal Temperature: 18.702438 deg C
offset = 2209
temperature = 16.638720 Celsius
Internal Temperature: 16.638720 deg C
offset = 2209
temperature = 17.283632 Celsius
Internal Temperature: 17.283632 deg C
offset = 2209
temperature = 16.896685 Celsius
Internal Temperature: 16.896685 deg C
offset = 2209
temperature = 16.122791 Celsius
Internal Temperature: 16.122791 deg C
offset = 2209
temperature = 17.541597 Celsius
Internal Temperature: 17.541597 deg C
offset = 2209
temperature = 17.283632 Celsius
Internal Temperature: 17.283632 deg C
offset = 2209
temperature = 19.347349 Celsius
Internal Temperature: 19.347349 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 16.896685 Celsius
Internal Temperature: 16.896685 deg C
offset = 2209
temperature = 17.025667 Celsius
Internal Temperature: 17.025667 deg C
offset = 2209
temperature = 15.735845 Celsius
Internal Temperature: 15.735845 deg C
offset = 2209
temperature = 16.122791 Celsius
Internal Temperature: 16.122791 deg C
offset = 2209
temperature = 18.831421 Celsius
Internal Temperature: 18.831421 deg C
offset = 2209
temperature = 17.412615 Celsius
Internal Temperature: 17.412615 deg C
offset = 2209
temperature = 19.476332 Celsius
Internal Temperature: 19.476332 deg C
offset = 2209
temperature = 20.121243 Celsius
Internal Temperature: 20.121243 deg C
offset = 2209
temperature = 17.541597 Celsius
Internal Temperature: 17.541597 deg C
offset = 2209
temperature = 17.283632 Celsius
Internal Temperature: 17.283632 deg C
nsh> bl602_adc_test
offset = 2209
temperature = 14.317039 Celsius
Internal Temperature: 14.317039 deg C
offset = 2209
temperature = 18.960402 Celsius
Internal Temperature: 18.960402 deg C
offset = 2209
temperature = 16.767702 Celsius
Internal Temperature: 16.767702 deg C
offset = 2209
temperature = 17.154650 Celsius
Internal Temperature: 17.154650 deg C
offset = 2209
temperature = 17.283632 Celsius
Internal Temperature: 17.283632 deg C
offset = 2209
temperature = 16.896685 Celsius
Internal Temperature: 16.896685 deg C
offset = 2209
temperature = 16.380756 Celsius
Internal Temperature: 16.380756 deg C
offset = 2209
temperature = 16.896685 Celsius
Internal Temperature: 16.896685 deg C
offset = 2209
temperature = 16.767702 Celsius
Internal Temperature: 16.767702 deg C
offset = 2209
temperature = 16.509739 Celsius
Internal Temperature: 16.509739 deg C
nsh>
```

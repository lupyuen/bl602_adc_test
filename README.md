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

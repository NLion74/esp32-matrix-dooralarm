# Overview

This project utilizes and esp32 and to send an message over matrix if a door or window opens/closes.
It works with detecting if a connected reed-switch is closed or not,and then sends a message acordingly.

## Credit

This project was originally created and designed by [Sigeband][https://github.com/Sigeband]. This is just a fork to make it work with matrix.

## Pinout:

![image](https://user-images.githubusercontent.com/114338337/215847824-6a8d162c-2f7a-4fb1-961a-24563dd50137.png)

## Materials:

```
1x ESP-32 NMCU (Can be any esp32)
1x 10K resitor
1x reedswitch
4x M2x12 flathead screws (for the case)
```

## Steps

```
1. Host and configure a Matrix-Notifier instance
2. Set all values needed in the esp32-matrix-dooralarm/esp32-telegram-dooralarm.ino
3. Wire everything according to the "Pinout" section.
4. Flash the code.
5. Connect to the AP and enter your wifi credentials.
6. It Works!

7. if it doesnt, check the serial monitor and the code to see whats wrong / where its getting stuck.

8. Still doesnt work? reach out to me, or ideally Sigeband who has more experience with the esp32 than me.
```

## 3D-Printing / Recommended Settings 

The case is designed to keep the esp32 safe, while still allowing a usb connection.
On the left side of the design you can see a small "tunnel" for the wires to pass through.
The case is designed to fit an nmcuesp32 with headers and the pulldownresistor.

*Recommended settings:*

```
0.28 layer height
40% infill 
3 walls
PLA/PETG/ABS (NO TPU)
Textured PEI sheet (for the looks)
```


# Memories

Here I'm trying to create a header for the Mojo development board that allows
to have the basic minimal peripherals for a running system:

 - Flash
 - SDRAM
 - VGA
 - PS2

In this directory there are the KiCAD files and this is the hand soldered version 1.0

![](boardv1.0.jpg)

## Flash

The flash memory under experimentation is the NAND512W3A2C, with 512 Mbit and x8 of bus width.

 - [Datasheet](https://4donline.ihs.com/images/VipMasterIC/IC/SGST/SGSTS20436/SGSTS20436-1.pdf)

## SRAM

The SDRAM used here is the MT48LC32M8A2.

 - [Datasheet](256Mb_sdr.pdf)
 - [Tutorial](https://embeddedmicro.com/blogs/tutorials/sdram-verilog) about writing a SDRAM controller in Verilog

## VGA

It's a VGA with 3 bits for color channel using a resistor ladder.

## Todo

 - UART
 - SPI
 - I2C
 - LCD controller
 - SDCard

probably are needed only as explicit routed pinout.

## Design errors

 - The pad of the ``AMS1117`` is the ``vout`` not ground (Fixed)
 - enlarge the pad so to make it more hand-solderable
 - add mask to the Open Hardware logo (fixed)
 - reverse voltage protection
 - overvoltage protection
 - enlarge holes for VGA and PS/2 (fixed)
 - fix R-2R ladder

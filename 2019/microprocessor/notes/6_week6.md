---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "sbe403a"
title: "Overview of Raspberry Pi zero "
year: "2019"
by: "Eslam"
---
* TOC
{:toc}

# Introduction to Raspberry PI

Raspberry Pi is a mini computer. It is basically a cheap PC for learning purposes and practising programming.

Raspberry is just like apple a name of fruit, Pi stands for python interpreter which is provided. 
Price  of PI 3 about $35, PI zero W $5

## Raspberry PI zero W specs

* Size : 65mm x 30mm 
* 1GHz single core processor
* 512 MB RAM
* Wireless
* 40 GPIO Pins
* mini HDMI port
* mini USB Port
* SD card area
* Camera Connector

## Installing The OS 

1. Head to download page and download the image of raspbian image 
2. Format the SD Card (min 8G SD card)
3. Burn the image on the SD card 
   for linux 
   ```bash
   sudo dd if=file.img of=/dev/sdx 
   ```
4. Add SD card to the board
5. Connect Mouse/Keyboard
6. Connect the display 
7. Connect the power 

[setting up your Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)

## Controlling Pi remotely 
Actually you don't have to connect the display, mouse and keyboard every time. You can enable ssh and access pi through any other computer.

1. Open the terminal 
2. Type 
   ```bash
    sudo raspi-config
    ```
    You can set new password for your Pi. Default password is raspberry
3. Use arrows to open Interfacing options and enable SSH (Remote command line access)


To access raspberry pi from your computer install ssh

```bash
sudo apt-get install ssh 
ssh pi@192.168.1.200 # Or the IP of your PI
```

For windows users you can use PuTTY. Check this [link](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-6-using-ssh/ssh-under-windows) for more help

## Basic linux commands

Command | Meaning
|---|---|
|ls| List files in current directory|
|cd |Change directory|
pwd |print working directory
rm filename |remove filename
mkdir directoryname |Make directory named directoryname
rmdir directoryname| remove empty directory
mv oldfile newfile | Move (rename) oldfile to newfile
cp oldfile newfile | Copy oldfile to newfile
man command | Display manual of command
date | read system date/time
sudo perform as|  root user
./program | run program
exit | Quit terminal session


## Getting started with python

Physical computing with python tutorial [link](https://projects.raspberrypi.org/en/projects/physical-computing)
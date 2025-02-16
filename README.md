# Music-Player

# Project Overview

This project is an ESP32-based music player that stores seven songs for seven days on an SD card, plays them on time using a Real-Time Clock (RTC) module, and supports mobile Bluetooth connectivity for streaming. An integrated PAM8403D audio amplifier enhances sound output.

 # Features

ESP32 Microcontroller – Handles audio playback, Bluetooth communication, and control logic.
Micro SD Card Module – Stores and retrieves audio files.
PCF8563T RTC Module – Manages real-time scheduling for playing specific songs each day.
PAM8403D Amplifier – Provides high-quality stereo audio output.
Bluetooth Connectivity – Enables wireless control and streaming via mobile devices.

# Hardware Components

ESP32-DevKitC-32D
Micro SD Card Module
PCF8563T RTC Module
PAM8403D Audio Amplifier
OLED Display (DM-OLED096-636) for song and time display
Battery Cell for power supply
Speaker (Left and Right Channels)

# Schematic and PCB Design

Designed using KiCad with all components integrated into a single PCB layout.
The full KiCad project files, including schematic, PCB layout, and component libraries, are provided in this repository.

# Wiring Connections

# ESP32 to SD Card Module:
CMD → GPIO 15
CLK → GPIO 14
DAT0 → GPIO 2
VDD → 3.3V
VSS → GND

# ESP32 to RTC (PCF8563T):

SDA → GPIO 21
SCL → GPIO 22
VDD → 3.3V
VSS → GND

# ESP32 to PAM8403D Amplifier:

INR (Right Audio Input) → GPIO 26
INL (Left Audio Input) → GPIO 25
VDD → 5V
GND → GND
LOUT+/- and ROUT+/- connected to respective Left and Right speakers.

# Software and Code

Programmed in Arduino IDE with ESP32 board libraries.
Code handles SD card file operations, RTC scheduling, and Bluetooth audio streaming.
PAM8403D controlled via GPIO pins for audio output.
Full source code and libraries are included in this repository.

# How to Build

Clone this repository.
Open the KiCad project for the schematic and PCB layout.
Flash the Arduino code to the ESP32 using Arduino IDE.
Assemble the hardware according to the wiring diagram.
Power on the device and enjoy scheduled music playback with Bluetooth control.

# Future Enhancements

Integration of OLED display for song names and clock display.
Dynamic playlist updates via Bluetooth.
Multi-frequency audio control.

# Author

Developed by 
Narasingarao K.

# For any questions, feel free to reach out!
+917075025629
knrkondapalli123@gmail.com

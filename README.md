# Light-Sensing Clock with Servo Control

This Arduino project creates a unique clock that uses a light sensor to determine the time of day and displays it using a servo motor. The servo positions an arrow to point at "Morning," "Day," or "Night" based on the ambient light level.

## Features

- Real-time light sensing using a photocell
- Servo motor control for visual time indication
- Automatic adjustment to changing light conditions

## Hardware Requirements

- Arduino Uno
- Servo Motor
- Photocell (Light-Dependent Resistor)
- Jumper wires
- Breadboard

## Usage

Once powered on, the clock will automatically start sensing light levels and adjusting the servo position. The arrow attached to the servo will point to the appropriate time of day based on the ambient light.

## Customization

You can adjust the sensitivity of the light sensor by modifying the `LIGHT_MIN_VALUE` and `LIGHT_MAX_VALUE` constants in the code.

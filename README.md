# Arduino Ultrasonic Radar & Proximity Alarm

This project uses an **HC-SR04 Ultrasonic Sensor** and a **Buzzer** to create a proximity-based alarm system. It measures the distance to an object and triggers an audible alert that increases in frequency as the object gets closer—similar to a car's parking sensor.

## Features
- Real-time distance measurement in centimeters.
- Dynamic audio feedback (Beep frequency increases as distance decreases).
- Serial Monitor integration for debugging and data logging.

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **HC-SR04 VCC** | 5V | Power Supply |
| **HC-SR04 GND** | GND | Ground |
| **HC-SR04 Trig** | Pin 12 | Trigger Signal (Output) |
| **HC-SR04 Echo** | Pin 13 | Echo Signal (Input) |
| **Buzzer (+)** | Pin 8 | Audio Output |
| **Buzzer (-)** | GND | Ground |

## How it Works
The sensor sends an ultrasonic pulse (40kHz) which travels through the air. If there is an object or obstacle in its path, it will bounce back to the sensor. By calculating the travel time and the speed of sound, the distance is determined using the formula:
$$Distance = \frac{Time \times Speed\ of\ Sound}{2}$$

## Setup
1. Connect the components as shown in the wiring table.
2. Upload the "proximity_alarm.ino" code to your Arduino Uno.
3. Open the Serial Monitor (9600 baud) to see live distance data.

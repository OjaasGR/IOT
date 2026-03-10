🔥 Smart Fire Detection and Risk Prediction System using ESP32
📌 Project Overview

This project implements an IoT-based fire detection and prevention system for industrial environments.
The system monitors environmental conditions using gas and flame sensors, displays real-time readings on an OLED display, and uploads data to ThingSpeak cloud for remote monitoring and analysis.

The system also includes a risk prediction logic that analyzes sensor values to classify the fire risk level.

🎯 Objectives

Detect potential fire hazards using sensors

Display real-time readings locally

Upload environmental data to the cloud

Provide risk prediction based on sensor data

Improve industrial workplace safety

🧰 Hardware Components
Component	Description
ESP32	Microcontroller with built-in WiFi
MQ135 Gas Sensor	Detects smoke and harmful gases
Flame Sensor	Detects fire/flame presence
OLED Display (128x64)	Displays sensor readings
Jumper Wires	Hardware connections
Breadboard	Circuit assembly
🔌 Hardware Connections
MQ135 Gas Sensor
MQ135 Pin	ESP32 Pin
VCC	5V
GND	GND
AO	GPIO 35
Flame Sensor
Flame Pin	ESP32 Pin
VCC	3.3V
GND	GND
DO	GPIO 34
OLED Display (I2C)
OLED Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO 21
SCL	GPIO 22
☁ Cloud Platform

The system uses ThingSpeak for IoT data monitoring.

ThingSpeak Channel Fields
Field	Parameter
Field 1	Gas Level
Field 2	Flame Status
Field 3	Risk Level
⚠ Risk Prediction Logic

The system predicts fire risk using simple threshold analysis.

Condition	Risk Level	Value Sent to Cloud
Gas < 250	LOW	1
Gas 250–400	MEDIUM	2
Gas > 400	HIGH	3
Flame Detected	CRITICAL	4
📟 OLED Display Output

Example output:

Smart Fire System
------------------
Gas: 380
Flame: NO
Risk: MEDIUM

If fire is detected:

Smart Fire System
------------------
Gas: 420
Flame: YES
Risk: CRITICAL
🔄 System Workflow

Sensors detect environmental conditions

ESP32 reads sensor data

Risk level is calculated

Data is displayed on OLED

Sensor values are uploaded to ThingSpeak

Cloud dashboard visualizes the data

📊 ThingSpeak Dashboard

The cloud dashboard displays:

Gas concentration graph

Flame detection status

Risk level prediction trends

This allows remote monitoring of industrial safety conditions.

🧪 Applications

Industrial safety monitoring

Chemical plants

Warehouses

Manufacturing facilities

Smart factories

🚀 Future Improvements

Add temperature sensors (DHT11 / DHT22)

Implement SMS or Email alerts

Integrate machine learning for predictive analytics

Add automatic fire suppression system

👨‍💻 Technologies Used

Arduino IDE

ESP32

Embedded C

IoT Cloud (ThingSpeak)

I2C Communication

Sensor Data Analytics

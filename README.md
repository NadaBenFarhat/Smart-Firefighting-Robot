# 🤖 Smart Autonomous & Remote-Controlled Firefighting Robot

<p align="center">
  <b>An Embedded Robotics System for Fire Detection, Autonomous Navigation, and Fire Suppression</b>
</p>

<p align="center">
  <img src="assets/firefighting_robot_banner.gif" width="900">
</p>

<p align="center">
🔥 Detect → 📍 Localize → 🚗 Navigate → 💧 Extinguish
</p>

---

# 📌 Project Overview

The **Smart Autonomous & Remote-Controlled Firefighting Robot** is an embedded robotics project designed to detect, locate, and suppress fire hazards autonomously while also providing a manual remote-control mode.

The system combines:

- 🔥 Flame sensing for fire detection
- 🌫️ Gas monitoring for safety analysis
- 📡 Bluetooth communication for remote control
- 📏 Ultrasonic sensing for obstacle avoidance
- 🚗 Differential drive navigation
- 💧 Automatic water-based fire suppression

The robot is based on an **ESP32/Arduino embedded platform** and focuses on real-time decision-making, sensor integration, and autonomous robotic control.

---

# 🎯 Key Objectives

The main objectives of this project are:

✅ Detect fire sources using multiple flame sensors  
✅ Determine fire direction using sensor localization  
✅ Monitor hazardous gas presence  
✅ Navigate safely while avoiding obstacles  
✅ Allow manual control through Bluetooth  
✅ Automatically activate the water pump for extinguishing  
✅ Provide real-time status feedback to the user  

---

# ⚙️ System Features

## 🔥 Fire Detection & Localization

The robot uses three flame sensors:

- Left sensor
- Center sensor
- Right sensor

The sensor combination allows the robot to determine the approximate fire direction and adjust its movement accordingly.

Example:

Left Flame Detection ↓ Turn Left

Center Flame Detection ↓ Move Forward

Right Flame Detection ↓ Turn Right

---

## 🌫️ Gas Monitoring

A gas sensor is integrated to monitor hazardous gas levels.

The system continuously checks environmental conditions and prioritizes safety-related events during operation.

---

## 🚗 Autonomous Navigation

In autonomous mode, the robot performs:

Fire Detection ↓ Fire Localization ↓ Obstacle Checking ↓ Navigation Toward Source ↓ Safe Distance Stop (~12 cm) ↓ Water Pump Activation ↓ Return To Monitoring

---

# 🧠 Intelligent Priority Management

The robot follows a priority-based decision system:

| Priority | Task |
|----------|------|
| 1 | Gas Detection |
| 2 | Obstacle Avoidance |
| 3 | Fire Localization |
| 4 | Manual Commands |

This hierarchy allows the robot to handle critical situations before normal navigation tasks.

---

# 🚗 Motion Control & Differential Drive

The robot uses a differential drive mechanism.

Features:

- Independent motor control
- Forward and backward movement
- Left and right rotation
- Precise direction correction

Implemented movement functions include:

```cpp
moveForward();
moveBackward();
turnLeft();
turnRight();
stopMotors();
```

---

🎮 Operating Modes

🟢 Autonomous Mode

The robot independently performs the emergency response mission.

Workflow:

1. Sensors continuously monitor the environment.


2. Flame sensors detect fire presence.


3. The robot determines the fire direction.


4. The robot approaches while avoiding obstacles.


5. At approximately 12 cm, the robot stops.


6. The water pump activates for fire suppression.


7. The system returns to monitoring mode.




---

🔵 Manual Mode (Bluetooth Control)

The user can remotely control the robot.

Command	Action

F	Move Forward
B	Move Backward
L	Turn Left
R	Turn Right
P	Pump ON
C	Pump OFF



---

🎬 Robot Demonstration

<p align="center">
  <img src="assets/robot_demo.gif" width="750">
</p>
---

🛡️ Fire Suppression Scenario

Example mission:

1. Environmental monitoring starts

2. Fire detected by flame sensors

3. Robot identifies fire direction

4. Robot moves toward the source

5. Ultrasonic sensor prevents collision

6. Robot stops at safe distance (~12 cm)

7. Water pump activates

8. Fire suppression completed

9. Robot resumes monitoring


---

🏗️ System Architecture

Sensors
                 |
                 |
                 ↓
          ESP32 Controller
                 |
    ┌────────────┼────────────┐
    ↓            ↓            ↓
 Motors      Water Pump   Bluetooth
    ↓            ↓            ↓
Movement   Fire Control  Remote Mode


Sensors:
- Flame Sensors
- Gas Sensor
- Ultrasonic Sensor


---

📂 Repository Structure

Smart-Autonomous-Firefighting-Robot/

├── assets/
│   ├── firefighting_robot_banner.gif
│   └── robot_demo.gif
│
├── docs/
│   ├── Autonomous_Firefighting_Robot_Report.docx
│   └── Autonomous_Firefighting_Robot_Presentation.pptx
│
├── src/
│   └── Firefighting_Robot_Main.ino
│
└── README.md


---

📚 Documentation

Complete project documentation:

📄 Project Report

📊 Project Presentation


---

🏆 Results & Achievements

The prototype successfully demonstrates:

✅ Autonomous fire detection
✅ Fire localization using multiple sensors
✅ Gas monitoring capability
✅ Obstacle avoidance
✅ Bluetooth remote operation
✅ Automatic water suppression
✅ Real-time embedded control


---

🔮 Future Improvements

Possible improvements:

📷 AI-based fire detection using computer vision

🌡️ Thermal camera integration

🗺️ Autonomous mapping and navigation

📱 Mobile application interface

☁️ IoT-based remote monitoring

🤖 Advanced robotics algorithms



---

🛠️ Technologies Used

Hardware

ESP32 / Arduino

Flame Sensors

Gas Sensor

Ultrasonic Sensor

DC Motors

Motor Driver

Bluetooth Communication Module

Water Pump

Buzzer


Software

Embedded C/C++

Arduino IDE

Sensor Integration

Robotics Control

Real-Time Embedded Programming



---

👩‍💻 Author

Nada Ben Farhat

Embedded Systems Engineering Student
ISSAT Sousse

GitHub:

https://github.com/NadaBenFarhat

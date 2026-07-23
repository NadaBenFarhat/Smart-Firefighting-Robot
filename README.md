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

The robot combines multiple sensing and control technologies:

- 🔥 Flame sensors for fire detection
- 🌫️ Gas sensor for hazardous gas monitoring
- 📏 Ultrasonic sensor for obstacle avoidance
- 📡 Bluetooth communication for remote control
- 🚗 Differential drive navigation
- 💧 Automatic water pump fire suppression

The system is developed using an **ESP32/Arduino embedded platform**, focusing on real-time sensor processing, decision-making, and robotic control.

---

# 🎯 Key Objectives

The main objectives of this project are:

- ✅ Detect fire sources using flame sensors
- ✅ Determine fire direction using multiple sensors
- ✅ Monitor hazardous gas levels
- ✅ Navigate safely while avoiding obstacles
- ✅ Provide Bluetooth-based manual control
- ✅ Automatically activate the water pump
- ✅ Send status feedback during operation

---

# ⚙️ Firmware Features & Logic

The firmware is developed using **Embedded C/C++** and focuses on real-time task management and hardware synchronization.

---

# 🚗 Motion Control & Differential Drive

The robot uses a **differential drive mechanism** that allows independent control of the left and right motors.

### Features:

- Independent motor control
- Forward and backward movement
- Left and right rotation
- Precise direction correction
- Smooth navigation

The movement system is controlled through dedicated functions:

```cpp
moveForward();
moveBackward();
turnLeft();
turnRight();
stopMotors();
```

These functions allow the controller to manage robot movement according to sensor feedback and user commands.

---

# 🧠 Intelligent Priority Management

The robot follows a priority-based decision system:

| Priority | Task |
|---|---|
| 1 | Gas Detection |
| 2 | Obstacle Avoidance |
| 3 | Fire Localization |
| 4 | Manual Bluetooth Commands |

This hierarchy ensures that critical safety events are handled first.

---

# 🔥 Fire Detection & Localization

The robot uses three flame sensors:

- Left flame sensor
- Center flame sensor
- Right flame sensor

The sensors allow the robot to estimate the fire direction.

Example:

```
Left Sensor Detection
        ↓
Turn Left

Center Sensor Detection
        ↓
Move Forward

Right Sensor Detection
        ↓
Turn Right
```

---

# 🌫️ Gas Monitoring

A gas sensor is integrated to monitor hazardous gas presence.

The robot continuously checks environmental conditions and includes gas detection as a high-priority safety task.

---

# 📏 Obstacle Avoidance

The ultrasonic sensor provides distance measurement to detect obstacles.

Functions:

- Measure distance
- Prevent collisions
- Improve navigation safety

---

# 🎮 Operating Modes

The robot supports two operation modes:

---

## 🟢 Autonomous Mode

In autonomous mode, the robot performs the firefighting mission without human intervention.

Workflow:

```
Environmental Monitoring
          ↓
Fire Detection
          ↓
Fire Localization
          ↓
Obstacle Checking
          ↓
Navigation Toward Fire Source
          ↓
Safe Distance Stop (~12 cm)
          ↓
Water Pump Activation
          ↓
Return To Monitoring
```

### Autonomous Process:

1. Sensors continuously monitor the environment.
2. Flame sensors detect fire.
3. The robot identifies the fire direction.
4. The robot moves toward the fire source.
5. Ultrasonic sensing avoids obstacles.
6. Robot stops at approximately 12 cm.
7. Water pump activates for suppression.
8. Robot returns to monitoring mode.

---

## 🔵 Manual Mode (Bluetooth Control)

The user can control the robot remotely using Bluetooth commands.

| Command | Action |
|---|---|
| F | Move Forward |
| B | Move Backward |
| L | Turn Left |
| R | Turn Right |
| P | Pump ON |
| C | Pump OFF |

---

# 🛡️ Fire Suppression Scenario

Example mission:

```
1. Robot monitors environment

2. Fire detected by flame sensors

3. Fire direction calculated

4. Robot navigates toward the source

5. Obstacles avoided using ultrasonic sensor

6. Robot stops at safe distance (~12 cm)

7. Water pump activated

8. Fire suppression completed

9. Robot resumes monitoring
```

---

# 🏗️ System Architecture

```
                 Sensors
                    |
                    ↓
             ESP32 Controller
                    |
       ┌────────────┼────────────┐
       ↓            ↓            ↓
    Motors     Water Pump   Bluetooth
       ↓            ↓            ↓
  Movement    Suppression  Remote Control


Sensors:
- Flame Sensors
- Gas Sensor
- Ultrasonic Sensor
```

---

# 📂 Repository Structure

```
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
```

---

# 📚 Documentation

Complete project documentation:

- 📄 Project Report  
  `docs/Autonomous_Firefighting_Robot_Report.docx`

- 📊 Project Presentation  
  `docs/Autonomous_Firefighting_Robot_Presentation.pptx`

---

# 🏆 Results & Achievements

The prototype successfully demonstrates:

- ✅ Autonomous fire detection
- ✅ Fire localization
- ✅ Gas monitoring
- ✅ Obstacle avoidance
- ✅ Bluetooth remote control
- ✅ Automatic water suppression
- ✅ Embedded real-time control

---

# 🔮 Future Improvements

Possible improvements:

- 📷 AI-based fire detection using computer vision
- 🌡️ Thermal camera integration
- 🗺️ Autonomous mapping
- 📱 Mobile application monitoring
- ☁️ IoT remote supervision
- 🤖 Advanced navigation algorithms

---

# 🛠️ Technologies Used

## Hardware

- ESP32 / Arduino
- Flame Sensors
- Gas Sensor
- Ultrasonic Sensor
- DC Motors
- Motor Driver
- Bluetooth Communication Module
- Water Pump
- Buzzer

## Software

- Embedded C/C++
- Arduino IDE
- Sensor Integration
- Robotics Control
- Real-Time Embedded Systems

---

# 👩‍💻 Author

**Nada Ben Farhat**

Embedded Systems Engineering Student  
ISSAT Sousse

GitHub:

https://github.com/NadaBenFarhat

# 🤖 Smart Autonomous & Remote-Controlled Firefighting Robot

## 🎯 Project Overview
This project aims to design and implement an intelligent robot capable of detecting, locating, and extinguishing fires. It operates in two modes: **Autonomous** for emergency response and **Manual** for remote navigation via Bluetooth.

### Key Objectives:
* **Manual Navigation:** Full control via Bluetooth.
* **Obstacle Avoidance:** Real-time distance sensing to prevent collisions.
* **Safety Alerts:** Immediate sound alarms (Buzzer) and Bluetooth notifications upon danger detection.
* **Fire & Gas Sensing:** Continuous monitoring for flames and hazardous gas leaks.
* **Automated Response:** Precision movement toward heat sources and automated fire suppression using a water pump.

---

## 💻 Firmware Features & Logic
The system is built on an **Arduino-based firmware** with a focus on real-time task management and hardware synchronization.

### 1. Motion & Differential Drive
* Independent control of rear drive wheels.
* Smooth maneuvering using velocity differential for precise turns.
* Modular movement functions: `moveForward(duration)`, `turnRight(duration)`, etc.

### 2. Intelligent Priority Management
The robot follows a strict safety hierarchy to ensure the most critical threat is handled first:
1.  **Gas Detection** (Highest Priority)
2.  **Obstacle Avoidance**
3.  **Fire Localisation**
4.  **Manual Bluetooth Commands** (Lowest Priority)

### 3. Sensing & Localization
* **Triple Flame Sensors:** Strategically placed for precise fire localization (Left/Center/Right).
* **Ultrasonic Sensor:** High-precision distance measurement for safe navigation.

---

## ⚙️ Operational Modes

### 🟢 Autonomous Mode
The robot scans the environment continuously. Once a fire is detected:
1.  **Localization:** It calculates the direction and aligns itself with the flame.
2.  **Approach:** Moves toward the fire, stopping at a safe distance (12 cm).
3.  **Suppression:** Activates the water pump for 5 seconds.
4.  **Feedback:** Sends "EXTINCTION IN PROGRESS / COMPLETED" via Bluetooth.

### 🔵 Manual Mode (Bluetooth Control)
The user can take full control using the following commands:
* `F`: Forward | `B`: Backward | `L/R`: Turn Left/Right.
* `P`: Pump ON | `C`: Pump OFF.

---

## 🛡️ Fire Suppression Scenario (Example)
1.  **Detection:** Fire identified at 50 cm.
2.  **Navigation:** Progressive approach in 10 cm steps with real-time direction adjustments.
3.  **Action:** Stops at 12 cm; activates the pump for 5 seconds.
4.  **Completion:** Resumes surveillance mode automatically after extinction.

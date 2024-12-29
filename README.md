# Drone_using_Arduino

## Overview
This project demonstrates how to build a quadcopter drone using an Arduino Nano, integrating various components to achieve stable flight and intelligent control. The goal is to explore the mechanical, electronic, and software aspects of drone systems. The drone is controlled using a mobile app, with real-time adjustments made using feedback control mechanisms.

We have also created a YouTube video explaining the entire process of building and programming our drone. You can watch it here: [Making of the drone](https://www.youtube.com/watch?v=GkrDY8fI6IA).

## Key Components

| **Component**                | **Description**                                                                                                      | **Function**                                                                                                     |
|------------------------------|----------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| **Brushless DC Motors (BLDC)**| High power density, low maintenance motors used to drive the propellers.                                             | Provides lift and thrust for stable flight.                                                                    |
| **Electronic Speed Controllers (ESCs)**| Regulates motor speed by converting PWM signals into motor control commands.                                         | Controls the speed of motors for stable flight dynamics.                                                      |
| **Battery (LiPo)**           | Lightweight Lithium Polymer battery with high power-to-weight ratio.                                                 | Supplies energy to all components.                                                                             |
| **Inertial Measurement Unit (IMU)** | Combination of accelerometers and gyroscopes measuring real-time orientation and angular velocity.                    | Provides real-time data for stabilization and navigation.                                                      |
| **Microcontroller (Arduino Nano)**| Central controller managing motor speeds and interfacing with sensors.                                               | Controls flight dynamics and sensor readings, sending PWM signals to ESCs.                                      |
| **Wi-Fi Module (NodeMCU ESP32)** | Facilitates wireless communication between drone and remote controller.                                             | Sends joystick data from the user via the RemoteXY app to control the drone.                                   |
| **Propellers & Structural Components** | Four propellers (two clockwise, two counterclockwise) providing lift and stability, lightweight frame construction. | Ensures drone stability and weight efficiency.                                                                 |

## Control Logic

### User Input via RemoteXY App:
- **Left Joystick**: Controls throttle (up/down) and yaw (left/right).
- **Right Joystick**: Controls pitch (up/down) and roll (left/right).
  
### Signal Flow:
- Joystick inputs from the mobile app are sent to the NodeMCU, which packages and forwards the data to the Arduino Nano.
- The Arduino Nano processes the flight data and outputs PWM signals to the ESCs to control motor speed.

### Motor Control:
- The ESCs use the PWM signals to manage the brushless motors, ensuring smooth and stable rotation for lift and movement.

## Feedback and Stability

### Closed-Loop Feedback System:
- The drone uses a **PID (Proportional-Integral-Derivative)** controller to adjust motor speeds based on discrepancies between the desired and actual angles of orientation. This continuous correction ensures stable flight, compensating for disturbances like wind or minor errors in sensor data.

### Calibration:
- The IMU is calibrated to account for initial tilt and aligns the system frame with the gravitational force to ensure accurate readings during flight.

## Repository Structure

| **File Name**                       | **Description**                                                                                          |
|-------------------------------------|----------------------------------------------------------------------------------------------------------|
| **Drone-design.pdf**                | Overview of drone design, including propulsion, sensor integration, flight control, and wireless communication. |
| **YMFC-AL_Flight_controller.ino**   | Core flight controller code implementing PID stabilization for roll, pitch, and yaw using gyro and ESC control. |
| **Sensor-Interface.pdf**            | Explains how the MPU-6050 IMU is interfaced with Arduino via I2C for real-time orientation and angular velocity data. |
| **Al_setup.ino**                    | Initial setup code for the drone. Configures I2C clock, validates receiver signals, and maps input channels. |
| **ESC_calibrate.ino**               | Calibrates the ESCs by sending consistent PWM signals for proper motor synchronization and operation.      |
| **dual_joystick.ino**               | Code for controlling the drone via two virtual joysticks in the RemoteXY app. Maps joystick inputs to PWM signals for the ESCs. |
| **slider.ino**                      | An alternative RemoteXY configuration using sliders for control. Maps slider positions to PWM signals for motor control. |
| **User-Interface.pdf**              | Details the user interface setup using RemoteXY, including Wi-Fi connection, joystick configuration, and motor testing. |
| **RemoteXY Configuration**          | Configurations for GUI-based drone control using Wi-Fi connection via the ESP8266 module. Included in joystick and slider codes. |

## Challenges and Solutions

- **Environmental Factors**: 
  - The PID controller helps correct errors in real-time, maintaining stability despite external disturbances.
  
- **Corrupted or Missing Data**: 
  - The drone relies on onboard sensors and the closed-loop feedback system to handle situations where communication errors or sensor malfunctions might occur.

## YouTube Video
We have created a detailed YouTube video explaining the process of building and programming the drone. You can watch it here: [Making of the drone](https://www.youtube.com/watch?v=GkrDY8fI6IA).


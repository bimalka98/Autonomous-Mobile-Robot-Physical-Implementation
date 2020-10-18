<h1 align="center"> Building a Task-Specific Autonomous Mobile Robot  </h1>

[![BCH compliance](https://bettercodehub.com/edge/badge/bimalka98/Autonomous-Mobile-Robot?branch=master)](https://bettercodehub.com/)

<h2 align="center"> Contents </h2>

<!-- number.[Title](link)-->
1. [Introduction](#introduction)
2. [Current Status of the Project](#current-status-of-the-project)

---

## *Introduction*

This repository includes all the project files related to the development of an `Arduino based autonomous mobile robot`. The project is being done by a team of 5 undergraduates at the Department of Electronic and Telecommunication Engineering, University of Moratuwa, Sri Lanka. The following figure illustrates the `initial prototype` of the planned mobile robot design and it may be subjected to various changes during the actual robot implementing stage due to possible reasons.


![Initial prototype Of the Mobile Robot](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/robot.PNG)*Version 1*

![Updated Version](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/robotV2.JPG)*Version 2*

---

## *Current Status of the Project*

* Algorithms were developed.
* Working on coding.
* Physical Robot building stage was initialized.

---

## *Brief introduction about the files in repository*

### LatestStable
This folder contains the latest stable version of the Arduino code tested and debugged by the team.

### Arduino Sketches
This folder contains the most fundamental Arduino sketches for various sub-tasks encountered while designing the robot. Ex:
* Drive a Servo motor
* Drive a DC motor through L298N motor driver
* Drive a DC motor through VNH5019A Motor Driver-POLOLU
* Measuring distances using SharpIR

### SolidWorksModels
This folder contains all the SolidWorks models of the robot prototype.

### Laser Cut parts
DXF files of the parts which were laser cut to build the robot.

### 3D Print
STL files of the parts which were 3D printed to build the robot.

### ModifiedLibraries
Arduino libraries which were modified(or not modified) to suit to the given task.

### Documentation
`Documentation` folder includes some of the important documents related to the design of a mobile robot.

**ArduinoMega2560.pdf** : Information about `peripheral circuitry` of the ArduinoMega2560(Rev3).

**How to choose the correct servo.pdf** : Calculations to choose the correct servo motors for the given task.

**L298N Motor Driver Logical Functionality.pdf** : Underlying logical Functionality of the L2968N motor driver is shown by a truth table.

**Motor_selection.pdf** : Calculations required to determine the motor for the mobile robot are explained in this document.

**Power_source_selection.pdf** : Calculations required to choose the proper power source for the mobile robot are described in the document.

**Robot Mechanical Design.pdf** : The initial prototype of the mobile robot and the mechanical parts of the robot are explained in this document.

**Robot Sensors.pdf** : Sensors used in building the robot is described in this document in descriptive manner and drawbacks of other Sensors are also included.

**Subsumption Architecture.pdf** : A summary on the `Subsumption Architecture` is given in this document. It is a very robust  Control system Architecture which was introduced by R. A. Brooks of MIT in 1985.

---

# *Nothing Happens Over Night* 😈

Some of the moments of actual robot implementation...

![](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/1.jpg)*IR sensor Panel: before mounting*

![](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/2.jpg)*Mounting the robot brain: ArduinoMega2560*

![](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/3.jpg)*Drilling holes to mount motors*

![](https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/4.jpg)*Checking the power distribution unit*

---

## *Team*

#### *Team leader*
Thalagala B.P. https://bimalka98.github.io/

#### *Team members*
1. Sandeepa H.K.C.A https://github.com/AvishkaSandeepa
2. Hewavitharana D.R. https://github.com/Hevidra
3. Nagasinghe K.R.Y. https://github.com/Ravindu-Yasas-Nagasinghe
4. Kumarasinghe H.A.N.H. https://github.com/nikeshi99

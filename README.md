<h1 align="center"> Building a Task-Specific Autonomous Mobile Robot  </h1>

[![BCH compliance](https://bettercodehub.com/edge/badge/bimalka98/Autonomous-Mobile-Robot?branch=master)](https://bettercodehub.com/)

<h2 align="center"> Contents </h2>

<!-- number.[Title](link)-->
1. [Introduction](#introduction)
2. [Current Status of the Project](#current-status-of-the-project)
3. [Brief introduction about the files in repository](#brief-introduction-about-the-files-in-repository)
4. [Physical Robot Implementation](#nothing-happens-over-night-)
5. [Our team](#team)

---

## *Introduction*

This repository includes all the project files related to the development of an `Arduino based autonomous mobile robot`. The project is being done by a team of 5 undergraduates at the Department of Electronic and Telecommunication Engineering, University of Moratuwa, Sri Lanka. The following figure illustrates the `initial prototype` of the planned mobile robot design and it may be subjected to various changes during the actual robot implementing stage due to possible reasons.

|*Version 1*|*Version 2*|
|:----:|:----:|
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/robot.PNG" width="500" />| <img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/robotV2.JPG" width="500" /> |


---

## *Current Status of the Project*

* Algorithms were developed.
* Working on coding.
* Physical Robot building stage was initialized.
* Robot arm's basic motion was implemented.
* Line following algirithm is being debugged.

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

> Great things are not done by impulse, but by a series of small things brought together. ~ Vincent Van Gogh

**Some of the moments of actual robot implementation...**

|Image| Description/ Comments|
|:----:|:----|
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/1.jpg"  width="450" />| *IR sensor Panel: 'Raykha S8' before mounting* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/3.jpg"  width="450" />| *Drilling holes to mount motors* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/4.jpg"  width="450" />| *Checking the power distribution unit* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/5.jpg"  width="450" />| *Mounting the motor driver: 'Dagaya 2.0'* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/6.jpg"  width="450" />| *Mounting the power distribution unit* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/8.jpg"  width="450" />| *Powering up the IR sensor panels* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/9.jpg"  width="450" />| *Powering up the IR sensor panels. Side View* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/10.jpg" width="450" />|  *Mounting the robot brain. ArduinoMega2560* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/11.jpg" width="450" />|  *Back view* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/12.jpg" width="450" />|  *Making the robot arm* |
|<img src="https://github.com/bimalka98/Autonomous-Mobile-Robot/blob/master/Figures/13.jpg" width="450" />|  *Robot up to now* |



---

## *Team*

> *Individual commitment to a group effort* --that is what makes a team work, a company work, a society work, a civilization work. ~ Vince Lombardi

#### *Team leader*
[Thalagala B.P.](https://bimalka98.github.io/)

#### *Team members*
1. [Sandeepa H.K.C.A](https://github.com/AvishkaSandeepa)
2. [Hewavitharana D.R.](https://github.com/Hevidra)
3. [Nagasinghe K.R.Y.](https://github.com/Ravindu-Yasas-Nagasinghe)
4. [Kumarasinghe H.A.N.H.](https://github.com/nikeshi99)

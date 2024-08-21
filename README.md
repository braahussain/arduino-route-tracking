# arduino-route-tracking
This is an arduino software application that tracks the location of an 4WD car starting from a relative point, using esp32 board. 
Using this application will allow you to monitor the movement of a car module starting from an initial point.

# Requirements for this application:
  1 - 4WD car module.
  2 - microcontroller to be a medium between the esp32 and DC motor drivers.
  3 - Software application for the DC motor movement.
  4 - Serial communication between the esp32 and a control unit like a Bluetooth module.

I am glad to share with you another aspect of my work to develop a "V2X" system for the graduation project.
In this post, I will show you the concept and the result of developing a system that updates you with the current coordinates of a moving vehicle relative to a defined point on the ground, which allows you to track this vehicle and other vehicles relative to that point.
Dependency of the system:
The system is based only on a software application that can be written using any programming language and on any development board. In my case, I was working with an "ESP32" module. 
- The concept is completely independent on using any kind of sensor, since in my case, it was hard to implement any kind of sensor like a "compass" that contains magnets due to the use of DC motors that its fields will interfere with the compass. This why this system compensates the use of these sensors.

Benefits of the system:
 - Like I mentioned before, the whole system is based on a software application so that there is no need to use any sensors.
- And also, it is an excellent solution for the drawbacks of using a GPS module like the "Neo Series," which only works in very tight conditions, not to mention the limited range of these modules that makes them not suitable to use in applications with small car modules like, in my case, a 30x15 cm car module. 
Applications using this system:
 The system allows you to have periodically updated information about the position of vehicles, which can be used in many graduation project applications like:
1- Vehicle to everything (V2X). 
2- Advanced Drivers Assistance Systems (ADAS). 
3- Autonomous Parking System. 
4- Frameware Over The Air (FOTA). 
5- Driver Fatigue Detection System. 
(The third post will talk about the use of this system in a V2X system).




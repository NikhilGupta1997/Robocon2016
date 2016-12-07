# Robocon2016

## Overview
**ABU ROBOCON** (Asia-Pacific Robot Contest) is an annual robotics competition held among several countries in the Asia Pacific demographic.  
In the competition robots compete to complete a task within a set period of time. To build the robots, contestants, who are restricted to be *undergraduate students*, must possess rich knowledge in **programming**, **mechanical design** and **electronic circuit design**.  
ROBOCON 2016 was held at Bangkok, Thailand. The theme was "Clean Energy Recharging the World". The concept behind the theme is the utilization of renewable energy sources.

## Problem Statement
The [problem statement](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Rulebook.pdf) has been added to the git repository. It required the construction of two different robots:  
**Eco Bot**  
This is a small bot that has no actuators of its own. Its job to to transport a propeller from one end of the field to the other by traversing a path simulating hills, rivers and slopes. The path consists of many sharp turns and steep sloped which make it difficult for the eco bot to manoeuvre. As the eco bot has no motor or piston to provide thrust, it must rely on the second bot to power it along the path.  
**Hybrid Bot**  
This is a much larger bot that has two basic tasks. The first is to provide means to power the eco bot through the terrain with the catch that the hybrid bot is not allowed to physically touch the eco bot at any time. The second task is to obtain the propeller from the eco bot when the eco bot has traversed the terrain and then must climb a pole to attach the propeller on the pole at a height of 2 meters above the ground. This proved to be a difficult task provided that the hybrid bot weights close to 15 kg.

## Technical Details
**Eco Bot**  
Decided to use wind energy to drive the eco bot along the terrain. We added a large sail to a lightweight base. The ecobot would only be able to steer itself using a single wheel in the front. The steering was based on line following along the terrain. The line following was done using two different technologies.
+ **OPT Sensors**  
These small sensors would measure the amount of light intensity around them. Based on the different colors on the track the bot was able to locate itself by noticing changes in the measurements provided by the OPT Sensors. The [OPT Sensors code](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/optReading.ino) is located in the repository.
+ **Cameras**  
Another method we adopted was to use a camera to figure out the location of the bot and manoeuvre along the marked path. The camera input was processed using openCV and proved to be more reliable than the OPT sensors.  

**Hybrid Bot**  
The Hybrid bot had many technical speciafications to it. 
+ **The Drive**  
The differntial drive was implemented using **sabertooths** equiped with a **Kangaroo** using **maxom motors**, inorder to control ramping and give us better control on the robots actions. Also the ramping weights were learned by intensive testing to ensure the bot traveled in a straight line. The [kangaroo ramping code](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/Kangaroo_motor_driver.ino) has been included in the repository along with a basic [PS3 controller](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/PS3.ino) code used to control the drive.
+ **Propulsion System**  
The Hybrid used **wind power** to push the eco bot along the track. This wind force was provided by custom made fans imported from Japan which provided a great amount of thrust. The fan was attached to a moveable arm which could adjust to the change in height of the eco bot from the ground as it moved along the terrain.
+ **Automation**  
A great amount of the track required automation of the hybrid bot. In order to achieve this we used an **IMU sensor** to maintain its relative position and used [**PID tuning**](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/PID.ino) along with an array of OPT Sensors to maintain the bots motion along afixed line along the ground. The [Calibration](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/caliberation.ino) and the [Line Following](https://github.com/NikhilGupta1997/Robocon2016/blob/master/Arduino%20Code/Line_Follower_Combined_V2.4.ino) Code have been included in the repository.
+ **Pole Climbing**  
The 15 kg bot was required to traverse straight up a pole to attach the propellor. This was done using a high torque motor and a custom designed gripper which provided a large surface area on the pole to provide a larger possible frictional force to move the robot upwards.

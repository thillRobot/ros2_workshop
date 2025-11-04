# tutorial6 - turtlebot3-navigation - ros2_workshop

## Overview
ROS Assignment 6 - Complete Tutorial 6: Turtlebot3 Navigation 

## Tutorial
Follow the tutorial for using Turtlebot3 Simulations with ROS2 navigation in your Ubuntu 24 virtual machine and complete the turtlebot3 exercises including mapping and navigation.

This tutorial follows the ROBOTIS [Turtlebot3 Simulation](https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/) documentation. 

## Summary of commands

### Part 1 - Map generation with Cartographer SLAM

Start the turtlebot3 simulation in the house world
```
  ros2 launch turtlebot3_gazebo turtlebot3_house.launch.py
```
The Gazebo window should open and the walls of a house are shown.
![tutorial5-turtlebot3-simulations](images/tutorial5-figure1.png) 

Open a new terminal (or tab), start a SLAM node to localize and generate a map
```
  ros2 launch turtlebot3_cartographer cartographer.launch.py use_sim_time:=True
```

Open a new terminal (or tab), start a keyboard node to drive robot
```
  ros2 run turtlebot3_teleop teleop_keyboard
```

The SLAM node should show the map as it is created. Drive in a smooth path and cover as much of the house as possible. Use the  's' key to stop when needed to avoid collisions.

When the map is complete, run the following to save the map. The current directory of the terminal in which this command is run will determine the location of the map file.

```
  ros2 run nav2_map_server map_saver_cli -f ~/house_map0
``` 

Close all running processes and the map is now saved as two files: house_map0.pgm and house_map.yaml. Both files are required to use the map.

### Part 2 - Navigation with generated map

Start the turtlebot3 simulation in the house world
```
  ros2 launch turtlebot3_gazebo turtlebot3_house.launch.py
```

Open a new terminal and start the navigation node. Use the map name chosen aboven 
```
  ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=$HOME/house_map0.yaml
```

The rviz window will open, and the robot will be shown in the map. It may not be localized to begin. Before sending any goals, give the robot a good pose estimate with the pink arrow '2D pose estimate' near to top of rviz.

If the robot is localized, it should be ready to receive goals. Use the green arrow 'nav2 goal' near the top of rviz to send a goal. Click a goal location in the map and drag the arrow to choose a goal heading.

The robot should plan a path and begin navigating to the goal. Try at least one of two goals and take document screeshots for documentaion.

### Performance Settings
Depending on the system, the reponse to commands may be slow and the display may be difficult to adjust due to lag. To make the simulator run smoothly, consider using the following settings.

 - If using a VM and the screen is flashing, shutdown the VM and uncheck "accelerate 3D graphics" or similar setting in the VM display settings. Increase the VM RAM to max reccomended leaving enough to run the host machine.

 - When the Gazebo window first opens, expand 'physics' in menu to the right and adjust the step-size up. Try 0.005 or 0.01 instead of the default 0.001

 - In the entity tree to the bottom right, click on 'Sun' and expand the 'light' menu above. Scroll down in the menu or drag the split screen down and disable 'Cast shadows'.

![tutorial5-turtlebot3-simulations](images/tutorial5-figure2.png) 

## Deliverable 
Write a brief summary (1-2 paragraphs) on what you have accomplished and what you struggled with. Include screenshots showing the Gazebo and RVIZ windows for both part 1 and part 2, and the .pgm image of the map created in part 1. Submit your work as a single .pdf document.

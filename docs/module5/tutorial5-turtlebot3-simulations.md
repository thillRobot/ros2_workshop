# tutorial5 - turtlebot3-simultations - ros2_workshop

## Overview
ROS Assignment 5 - Complete Tutorial 5: Turtlebot3 Simulations 

## Tutorial
Follow the video tutorial for installing Gazebo Ionic and Turtlebot3 Simulations in your Ubuntu 24 virtual machine and complete the basic turtlebot3 exercises.

## Summary of commands
The following commands were entered in the video tutorial5 

Install Gazebo Ionic (recommended version for ROS Kilted) from osrf binaries
```
  sudo apt-get update
  sudo apt-get install curl lsb-release gnupg
  sudo curl https://packages.osrfoundation.org/gazebo.gpg --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
  echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] https://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null
  sudo apt-get update
  sudo apt-get install gz-ionic
```
Test the simulation program installed correctly
```
  gz sim
```

Install Turtlebot3 Simulations package from ros2 binaries
```
  sudo apt update
  sudo apt install ros-kilted-turtlebot3 ros-kilted-turtlebot3-msgs ros-kilted-turtlebot3-simulations
```

Test the turtlebot3 simulation 
```
  export TURTLEBOT3_MODEL=burger
  ros2 launch turtlebot3_gazebo empty_world.launch.py
```

Open a new terminal (or tab), start a keyboard node to drive robot
```
  export TURTLEBOT3_MODEL=burger
  ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py

```



## Deliverable 
Write a brief summary (1-2 paragraphs) on what you have accomplished and what you struggled with. Include an image that shows both talker and listener nodes running simultaneously. Submit your work as a single .pdf document

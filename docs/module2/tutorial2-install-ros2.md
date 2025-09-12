# tutorial2 - install ros2 - ros2_workshop

## Overview
ROS Assignment 2 - Complete Tutorial 2: Install ROS2

## Tutorial
Follow the video tutorial for installing ROS2 Kilted in your Ubuntu 24 virtual machine and complete the Try Some Examples talker and listener example to test the installation.

## Summary of commands
The following commands were entered in the video tutorial1 - install ros2

Update package list and upgrade package (also checks connection to ubuntu servers)
```
sudo apt update
sudo apt upgrade
```

Follow instructions for [Ubuntu (deb packages) Installation](https://docs.ros.org/en/kilted/Installation/Ubuntu-Install-Debs.html)

### System Setup
Set Locale
```
locale  # check for UTF-8

sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

locale  # verify settings
```

Enable required repositories
```
sudo apt install software-properties-common
sudo add-apt-repository universe
```
```
sudo apt update && sudo apt install curl -y
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo $VERSION_CODENAME)_all.deb" # If using Ubuntu derivates use $UBUNTU_CODENAME
sudo dpkg -i /tmp/ros2-apt-source.deb
```

install dev tool
```
sudo apt update && sudo apt install ros-dev-tools
```

install ros2
```
sudo apt update
sudo apt upgrade
sudo apt install ros-kilted-desktop
source /opt/ros/kilted/setup.bash
ros2 run demo_nodes_cpp talker
```

try the tutorials
run in a new termial
```
source /opt/ros/kilted/setup.bash
ros2 run demo_nodes_cpp talker
```
run in another new termial
```
source /opt/ros/kilted/setup.bash
ros2 run demo_nodes_py listener
```




## Deliverable 
Write a brief summary (1-2 paragraphs) on what you have accomplished and what you struggled with. Include an image that shows both talker and listener nodes running simultaneously. Submit your work as a single .pdf document

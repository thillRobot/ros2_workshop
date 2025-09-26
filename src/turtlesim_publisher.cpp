// turtlesim_publisher.cpp - creates a ros2 node and publishes a twist cmd_vel topic
// Tristan Hill, ros2_workshop
// September 25, 2025
// run with the following:
// ` ros2 run ros2_workshop turtlesim_publisher --remap /cmd_vel:=/turtle1/cmd_vel `
 
#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"


int main(int argc, char * argv[])
{
  // initialize ros2 node		
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("turtlesim_publisher", options);

  // initialize publisher 
  auto pub = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  geometry_msgs::msg::Twist msg; // msg object to publish 
  std::stringstream str;     

  int cnt=0;
  rclcpp::WallRate loop_rate(50);
  while (rclcpp::ok()) {
	

	// format string with stringstream	  
  	str<<"main() loop cnt: "<<cnt<<std::endl;
	//str<<"Twist x:	<<
	std::cout<<str.str(); // print string to terminal
	msg.linear.x=1;   // put string into msg data
	msg.angular.z=0.5;  
	pub->publish(msg);    // publish message

	rclcpp::spin_some(node); // spin ros2
	cnt++; // increment loop counter 
 	str.str(""); // empty string for next iteration
  }

  return 0;
} 

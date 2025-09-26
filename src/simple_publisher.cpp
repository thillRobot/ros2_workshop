// simple_publisher.cpp - creates a ros2 node and publishes a std_msgs string topic
// Tristan Hill, ros2_workshop
// September 25, 2025
 
#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


int main(int argc, char * argv[])
{
  // initialize ros2 node		
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("simple_publisher", options);

  // initialize publisher 
  auto pub = node->create_publisher<std_msgs::msg::String>("simple_topic", 10);
  std_msgs::msg::String msg; // msg object to publish 
  std::stringstream str;     

  int cnt=0;
  rclcpp::WallRate loop_rate(50);
  while (rclcpp::ok()) {
	
	// format string with stringstream	  
  	str<<"main() loop cnt: "<<cnt<<std::endl;
	std::cout<<str.str(); // print string to terminal
	msg.data=str.str();   // put string into msg data
	pub->publish(msg);    // publish message

	rclcpp::spin_some(node); // spin ros2
	cnt++; // increment loop counter 
 	str.str(""); // empty string for next iteration
  }

  return 0;
} 

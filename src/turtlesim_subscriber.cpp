// turtlesim_subscriber.cpp - creates a ros2 node and subscribes to a geometry_msgs pose topic
// Tristan Hill, ros2_workshop
// October 2, 2025
 
#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "turtlesim_msgs/msg/pose.hpp"

//subscriber callback function
void pose_callback(const turtlesim_msgs::msg::Pose::ConstSharedPtr & msg)
{
  std::cout<<"pose_callback exectuted, message contains: "<<std::endl;
  std::cout<<"x: "<< msg->x <<", y: "<< msg->y <<", theta: "<< msg->theta <<std::endl;
  std::cout<<"linear_velocity: "<< msg->linear_velocity <<std::endl;
  std::cout<<"angular_velicity: "<< msg->angular_velocity <<std::endl<<std::endl;
}


int main(int argc, char * argv[])
{
  // initialize ros2 node		
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  rclcpp::Node::SharedPtr node = rclcpp::Node::make_shared("turtlesim_subscriber", options);

  // initialize subscriber
  rclcpp::Subscription<turtlesim_msgs::msg::Pose>::SharedPtr subscription = 
	  node->create_subscription<turtlesim_msgs::msg::Pose>("/turtle1/pose", 10, pose_callback);
  
  std::stringstream str;     

  int cnt=0;
  rclcpp::WallRate loop_rate(50);
  while (rclcpp::ok()) {
	
	rclcpp::spin_some(node); // spin ros2
	cnt++; // increment loop counter 
  
  }

  return 0;
} 

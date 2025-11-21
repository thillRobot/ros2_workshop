cmake_minimum_required(VERSION 3.8)
project(ros2_workshop)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# add_executable and target_link_libraries for each c++ node to compile
add_executable(hello_world src/hello_world.cpp)
target_link_libraries(hello_world PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(simple_publisher src/simple_publisher.cpp)
target_link_libraries(simple_publisher PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS})

add_executable(turtlesim_publisher src/turtlesim_publisher.cpp)
target_link_libraries(turtlesim_publisher PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} 
	                                                        ${geometry_msgs_TARGETS})
add_executable(turtlesim_subscriber src/turtlesim_subscriber.cpp)
target_link_libraries(turtlesim_subscriber PUBLIC rclcpp::rclcpp ${std_msgs_TARGETS} 
								 ${geometry_msgs_TARGETS}
								 ${turtlesim_msgs_TARGETS})

# add name of each executable to list of targets
install(TARGETS 
	hello_world
	simple_publisher
	turtlesim_publisher
	turtlesim_subscriber	
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

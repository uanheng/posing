cmake_minimum_required(VERSION 3.0.2)
project(posing)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  sensor_msgs
  pcl_conversions
  pcl_ros
  laser_geometry
)

find_package(PCL 1.8 REQUIRED)

catkin_package()

include_directories(
  include
  include/posing
  ${catkin_INCLUDE_DIRS}
)

add_executable( POSE
  src/pose_node.cpp 
  src/reflector.cpp 
  src/globalmap.cpp
)

target_link_libraries( POSE ${catkin_LIBRARIES} ${PCL_LIBRARIES})


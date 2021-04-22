/**
 * @file pose_node.cpp
 * @uanheng (uanheng@foxmail.com)
 * @brief posing node
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ros/ros.h"
#include "reflector.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "FILTER");

  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  std::shared_ptr<Reflector> reflector_ptr = std::make_shared<Reflector>(nh, "/scan", 1000);

  while (ros::ok())
  {
    if (!reflector_ptr->split())
    {
      ROS_INFO("laser scan error!!!");
    }
    
    loop_rate.sleep();
    ros::spinOnce();
  }
  

  return 0;
}
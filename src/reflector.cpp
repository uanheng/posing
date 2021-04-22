/**
 * @file reflector.cpp
 * @uanheng (uanheng@foxmail.com)
 * @brief reflector class, Split point cloud， Fitting center of circle， Reflector matching
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "reflector.hpp"

Reflector::Reflector(ros::NodeHandle& nh, std::string topic_name, size_t buff_size):nh_(nh)
{
  std::cout << "topic name is " << topic_name << std::endl << "buff size is " << buff_size << std::endl;
  subscriber_ = nh_.subscribe(topic_name, buff_size, &Reflector::laserpoints_callback, this);

}

Reflector::~Reflector()
{
}

void Reflector::laserpoints_callback(const sensor_msgs::LaserScan::ConstPtr& laser_msg_ptr)
{
  std::cout << "i heared message!" << std::endl;
  new_laser_data_.push_back(*laser_msg_ptr);
}

bool Reflector::split()
{
  if (!new_laser_data_.empty())
  {
    laserpoints = new_laser_data_.front();
    new_laser_data_.pop_front();
  }
  else
  {
    return false;
  }
  

  const uint16_t THRESHOLD = 800;
  uint16_t laser_size = laserpoints.intensities.size();
  POSE pose_temp;
  std::vector<uint16_t> laser_num;
  for(uint16_t i = 1; i < laser_size; i ++)
  {
    if(laserpoints.intensities[i] < THRESHOLD || laserpoints.ranges[i] > 100)
    {
      laserpoints.intensities[i] = 0;
      laserpoints.ranges[i] = 0;
    }
    else
    {
      laser_num.push_back(i);
      pose_temp.i = laserpoints.intensities[i];
      pose_temp.x = laserpoints.ranges[i] * cos(laserpoints.angle_increment * i);    // laser_scan from -PI to PI
      pose_temp.y = laserpoints.ranges[i] * sin(laserpoints.angle_increment * i);
      pose_temp.rho = laserpoints.ranges[i];
      pose_temp.theta = laserpoints.angle_increment * i + laserpoints.angle_min;
      single_reflector_points.push_back(pose_temp);
    }
  }

  std::vector<POSE> temp;
  for(uint16_t i = 0; i < laser_num.size(); i ++)
  {
    temp.push_back(single_reflector_points[i]);
    if(1 != (laser_num[(i+1)%laser_num.size()] - laser_num[i]))
    {
      multi_reflector_points.push_back(temp);
      temp.clear();
    }
  }

  for(uint16_t i = 0; i < multi_reflector_points.size(); i ++)
  {
    std::cout << "multi_reflector_points" << " [" << i << "]" << std::endl;
    for(uint16_t ii = 0; ii < multi_reflector_points[i].size(); ii ++)
    {
      // std::cout << "multi_reflector_points" << " [" << i << "]";
      // std::cout << "[" << ii << "]" << std::endl;
      std::cout 
      << multi_reflector_points[i][ii].i << "\t" 
      << multi_reflector_points[i][ii].x << "\t" 
      << multi_reflector_points[i][ii].y << std::endl;
    }
  }

  single_reflector_points.clear();
  multi_reflector_points.clear();

  return true;
}
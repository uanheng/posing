/**
 * @file reflector.hpp
 * @uanheng (uanheng@foxmail.com)
 * @brief reflector class, Split point cloud， Fitting center of circle， Reflector matching
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef REFLECTOR_FITILE_H
#define REFLECTOR_FITILE_H

#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <laser_geometry/laser_geometry.h>
#include <deque>

/**
 * @brief point struct
 * 
 */
typedef struct
{
  double i;       /// point intensity
  double x;       /// x
  double y;       /// y
  double theta;   /// Polar coordinate system angle
  double rho;     /// Polar coordinate system length
} POSE;

class Reflector
{
private:

  /**
   * @brief node name
   * 
   */
  ros::NodeHandle nh_;

  /**
   * @brief node subscriber
   * 
   */
  ros::Subscriber subscriber_;

  /**
   * @brief buffer deque or synchronization laser data in future(todo)
   * 
   */
  std::deque<sensor_msgs::LaserScan> new_laser_data_;

  /**
   * @brief laserpoints callback
   * 
   */
  void laserpoints_callback(const sensor_msgs::LaserScan::ConstPtr& laser_msg_ptr);

public:

  /**
   * @brief laser points
   * 
   */
  sensor_msgs::LaserScan laserpoints;

  /**
   * @brief splited Reflector pointclouds
   * 
   */
  sensor_msgs::PointCloud2 laserpoints_pcl2;

  /**
   * @brief single reflector points
   * 
   */
  std::vector<POSE> single_reflector_points;

  /**
   * @brief multi reflector points
   * 
   */
  std::vector<std::vector<POSE>> multi_reflector_points;

  /**
   * @brief 
   * 
   */
  Reflector(/* args */);

  Reflector(ros::NodeHandle& nh, std::string topic_name, size_t buff_size);

  /**
   * @brief Destroy the Reflector object
   * 
   */
  ~Reflector();

  /**
   * @brief split Reflector pointcloud
   * 
   * @return true 
   * @return false 
   */
  bool split();

  /**
   * @brief fit circle center
   * 
   * @return true 
   * @return false 
   */
  bool fit();

  /**
   * @brief match Reflector number
   * 
   * @return true 
   * @return false 
   */
  bool match();

};

#endif
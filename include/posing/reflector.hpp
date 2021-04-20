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

class reflector
{
private:
  /* data */
public:

  /**
   * @brief 
   * 
   */
  reflector(/* args */);

  /**
   * @brief Destroy the reflector object
   * 
   */
  ~reflector();

  /**
   * @brief split reflector pointcloud
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
   * @brief match reflector number
   * 
   * @return true 
   * @return false 
   */
  bool match();
};

/**
 * @file globalmap.hpp
 * @uanheng (uanheng@foxmail.com)
 * @brief global map generation，loading
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class globalmap
{
private:
  /* data */
public:
  /**
   * @brief 
   * 
   */
  globalmap(/* args */);

  /**
   * @brief Destroy the globalmap object
   * 
   */
  ~globalmap();

  /**
   * @brief generate 
   * 
   * @return true 
   * @return false 
   */
  bool generate();

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  bool load();
};

#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>
#include <cstdlib>
#include <sstream>

void resp(const sensor_msgs::Temperature::ConstPtr& dato) //const
{
  ROS_INFO("Temperatura: %f °C", dato->temperature); //%5.2f °C
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "temp");
  ros::NodeHandle N;
  ros::Subscriber sub = N.subscribe("mavros/imu/temperature", 100, resp);
  ros::spin();
  return 0;
}

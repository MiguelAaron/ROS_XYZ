#include <ros/ros.h>
#include <xyz_pkg/msj_vel.h>

void respuesta(const xyz_pkg::msj_vel::ConstPtr& msj)
{
  ROS_INFO("Escucho: [%d] [%d] [%d] [%d]", msj->A, msj->B, msj->C, msj->D);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rec_velocidad");
  ros::NodeHandle N;
  ros::Subscriber Sub = N.subscribe("velocidades", 100, respuesta);
  ros::spin();
  return 0;
}

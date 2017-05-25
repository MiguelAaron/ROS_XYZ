#include<ros/ros.h>
#include<xyz_pkg/msj_vel.h>
#include<sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub_velocidad");
  ros::NodeHandle N;
  ros::Publisher pub = N.advertise<xyz_pkg::msj_vel>("velocidades", 100);
  ros::Rate R(5);

  xyz_pkg::msj_vel vel;

  if(argc != 5)
  {
    ROS_INFO("Usar: pub_velocidad A B C D");
    return 0;
  }

  vel.A = atoll(argv[1]);
  vel.B = atoll(argv[2]);
  vel.C = atoll(argv[3]);
  vel.D = atoll(argv[4]);

  while(ros::ok())
  {
    pub.publish(vel);
    ROS_INFO("Publico: A = %d, B = %d, C = %d, D = %d", vel.A, vel.B, vel.C, vel.D);
    ros::spinOnce();
    R.sleep();
  }
  return 0;
}

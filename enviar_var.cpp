#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv)
{
  int X = 0;
  int Y = 0;
  int Z = 0;

  ros::init(argc, argv, "enviar_var");
  ros::NodeHandle n_1;
  ros::Publisher Pub_1 = n_1.advertise<std_msgs::String>("msj_1", 1000);
  ros::NodeHandle n_2;
  ros::Publisher Pub_2 = n_2.advertise<std_msgs::String>("msj_2", 1000);
  ros::NodeHandle n_3;
  ros::Publisher Pub_3 = n_3.advertise<std_msgs::String>("msj_3", 1000);
  ros::Rate R(5);

  while(ros::ok())
  {
    std_msgs::String m_1;
    std::stringstream s_1;
    s_1 << "Mensaje 1: " << X;
    m_1.data = s_1.str();

    std_msgs::String m_2;
    std::stringstream s_2;
    s_2 << "Mensaje 2: " << Y;
    m_2.data = s_2.str();

    std_msgs::String m_3;
    std::stringstream s_3;
    s_3 << "Mensaje 3: " << Z;
    m_3.data = s_3.str();

    ROS_INFO("%s", m_1.data.c_str());
    Pub_1.publish(m_1);

    if((X%2) == 0)
    {
      ROS_INFO("%s", m_2.data.c_str());
      Pub_2.publish(m_2);
      Y++;
    }

    if((X%5) == 0)
    {
      ROS_INFO("%s", m_3.data.c_str());
      Pub_3.publish(m_3);
      Z++;
    }

    ros::spinOnce();
    X++;
    R.sleep();
  }
  return 0;
}

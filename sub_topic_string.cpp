#include<ros/ros.h>
#include<std_msgs/String.h>
#include<cstdlib>

void resp(const std_msgs::String::ConstPtr& dato)
{
  ROS_INFO("Escucho: %s", dato->data.c_str());
}

int main(int argc, char **argv)
{
  std_msgs::String topico;

  if(argc == 2)
  {
    topico.data = argv[1];
    ROS_INFO("%s", topico.data.c_str());
  }
  else
  {
    ROS_INFO("Usar: suscribirse_topico topico");
    return 0;
  }

  ros::init(argc, argv, "suscribirse_topico");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe(topico.data.c_str(), 1000, resp);
  ros::spin();
  return 0;
}

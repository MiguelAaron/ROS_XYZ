#include<ros/ros.h>
#include<std_msgs/String.h>
#include<cstdlib>

void resp(const std_msgs::String::ConstPtr& dato)
{
  ROS_INFO("Escucho: %s", dato->data.c_str());
}

int main(int argc, char **argv)
{
  int num = 1;
  std::stringstream m;
  std_msgs::String topico;

  if(argc == 2)
  {
    num = atoll(argv[1]);
  }
  else
  {
    ROS_INFO("Usar:  recibir_msj num  num = 1, 2 o 3");
    return 0;
  }

  m << "msj_" << num;
  topico.data = m.str();

  ros::init(argc, argv, "recibir_msj");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe(topico.data.c_str(), 1000, resp);
  ros::spin();
  return 0;
}

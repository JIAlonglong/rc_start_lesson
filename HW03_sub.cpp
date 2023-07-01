#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

void domsg(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("���յ���: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL,"");
  // ��ʼ���ڵ�
  ros::init(argc, argv, "yaml_subscriber");
  // �����ڵ���
  ros::NodeHandle nh;
  
  ros::Subscriber sub = nh.subscribe("yaml_param", 10, domsg);
  
  ros::spin();
  return 0;
}

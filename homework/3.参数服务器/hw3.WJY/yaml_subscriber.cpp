#include <ros/ros.h>
#include <std_msgs/String.h>

void callback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: %s", msg->data.c_str());
}

int main(int argc, char** argv) {
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "yaml_subscriber");
    ros::NodeHandle nh;

    // �������ⶩ����
    ros::Subscriber sub = nh.subscribe("yaml_param", 10, callback);

    // �����¼�ѭ��
    ros::spin();

    return 0;
}

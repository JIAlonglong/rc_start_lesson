#include <ros/ros.h>
#include <std_msgs/String.h>
#include <yaml-cpp/yaml.h>

int main(int argc, char** argv) {
    // ��ʼ��ROS�ڵ�
    ros::init(argc, argv, "yaml_publisher");
    ros::NodeHandle nh;

    // ��yaml�ļ��ж�ȡ����
    YAML::Node params = YAML::LoadFile("/path/to/my_yaml.yaml");
    std::string my_param = params["my_param"].as<std::string>();

    // �������ⷢ����
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param", 10);

    // ��������ֵ
    ros::Rate rate(10); // 10 Hz
    while (ros::ok()) {
        std_msgs::String msg;
        msg.data = my_param;
        pub.publish(msg);
        rate.sleep();
    }

    return 0;
}

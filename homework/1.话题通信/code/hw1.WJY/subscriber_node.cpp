#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

void stringCallback(const std_msgs::String::ConstPtr& msg)
{
	// ����Ϣת��Ϊ��д
	std::string upper_str = msg->data;
	std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);

	// ����ת�������Ϣ
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("output_topic", 1000);
	std_msgs::String output_msg;
	output_msg.data = upper_str;
	pub.publish(output_msg);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "string_converter_subscriber");

	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("input_topic", 1000, stringCallback);

	ros::spin();

	return 0;
}

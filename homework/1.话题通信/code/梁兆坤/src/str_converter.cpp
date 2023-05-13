#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ctype.h"
#include "algorithm"


//ros::NodeHandle nh;//�����������߶����߶���
static ros::Subscriber sub;
static ros::Publisher pub;

void deal(const std_msgs::String::ConstPtr& msg_p) {
    std::string msg = msg_p->data.c_str();//�����ַ���
    std::transform(msg.begin(), msg.end(), msg.begin(), toupper);//ת����д
    std_msgs::String finalmsg;//������Ϣ
    finalmsg.data = msg;//��ֵ
    pub.publish(finalmsg);//����



}

int main(int argc, char* argv[]) {

    ros::init(argc, argv, "str_converter");
    ros::NodeHandle nh;//�����������߶����߶���
    pub = nh.advertise<std_msgs::String>("out_put", 10);//ʵ����
    sub = nh.subscribe<std_msgs::String>("inpu", 10, deal);
    ros::spin();
    return 0;
}
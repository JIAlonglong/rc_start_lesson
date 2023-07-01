#include "ros/ros.h"
#include "std_msgs/String.h"
#include "string"

int main(int argc,char* argv[]){
    setlocale(LC_ALL,"");
    //�ڵ� yaml_publisher
    ros::init(argc,argv,"yaml_publisher");
    ros::NodeHandle nh;
    //���� yaml_param ����MAX10
    ros::Publisher pub = nh.advertise<std_msgs::String>("yaml_param",10);
    //�½���Ϣ���� ����
    std_msgs::String msg;
    //�����
    std::string param;

    nh.param<std::string>("my_param",param,"�Ҳ�������");

    msg.data = param;

    ros::Rate rate(10);
    ROS_INFO("���ڷ�����Ϣ");

    while(ros::ok()){
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();

    }
return 0;
}

    

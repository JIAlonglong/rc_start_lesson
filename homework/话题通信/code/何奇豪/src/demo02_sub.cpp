#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p){
    std_msgs::String message;
    message.data = msg_p->data;
    int i = 0;
    for(i=0; message.data[i]!='\0';i++){
        if(isupper(message.data[i])){
            message.data[i] = tolower(message.data[i]);
        }else if(islower(message.data[i])){
            message.data[i] = toupper(message.data[i]);
        }else{
            continue;
        }
    }
    ROS_INFO("%s",message.data.c_str());
    // ROS_INFO("我听见:%s.data",(*msg_p).data.c_str());
}
int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"DaMi");
    //3.实例化 ROS 句柄
    ros::NodeHandle string_converter;

    //4.实例化 订阅者 对象
    ros::Subscriber sub = string_converter.subscribe<std_msgs::String>("input_topic",10,doMsg);
    //5.处理订阅的消息(回调函数)

    //6.设置循环调用回调函数
    ros::spin();//循环读取接收的数据，并调用回调函数处理

    return 0;
}
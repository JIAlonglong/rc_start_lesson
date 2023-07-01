#include "ros/ros.h"
#include "std_msgs/String.h"
//�ص�����
void doMsg(const std_msgs::String::ConstPtr &msg){
	
	std_msgs::String new_msg;
    std::string original_msg = msg->data;
    //��Сдת�� 
    std::transform(original_msg.begin(),original_msg.end(),original_msg.begin(),::toupper);
    new_msg.data = original_msg;
    ROS_INFO("�����������ǣ�%s",new_msg.data.c_str());
    ros::NodeHandle nh2;
    ros::Publisher pub = nh2.advertise< std_msgs::String>("output_topic", 10);
    pub.publish(new_msg);

}
   
    
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    //��ʼ���ڵ� ������������
    ros::init(argc,argv,"input_topic");
    //�����ڵ���
    ros::NodeHandle nh;
    //���������߶��� ���г��� �Զ�����������ȵ�
    ros::Subscriber sub = nh.subscribe("string_converter",10,doMsg);
    //�����ĵ�������
    ros::spin();

    return 0;
}

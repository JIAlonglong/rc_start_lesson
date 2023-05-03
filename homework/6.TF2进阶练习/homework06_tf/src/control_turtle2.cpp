#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

/*
       ����1: ����� turtle1 ����� turtle2 �Ĺ�ϵ
       ����2: ������ٶȺ����ٶȲ�����
 */

int main(int argc, char* argv[])
{
    //�����������  ��ʼ��  NodeHandle
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "follow");
    ros::NodeHandle nh;
    //����buffer����,���������ĵ����ݴ���buffer����
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener lister(buffer);

    //��������߼�
    //������������
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);
    ros::Rate rate(10);
    while (ros::ok()) {

        try
        {
            //�������ڹ����Թ�ϵ
            geometry_msgs::TransformStamped T1toT2 = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0));
            //�������λ�ü��㲢��֯�ٶ���Ϣ
            geometry_msgs::Twist twist;
            //z = ϵ�� * ������(�Ա�,�ڱ�)
            twist.angular.z = 4 * atan2(T1toT2.transform.translation.y, T1toT2.transform.translation.x);
            // x = ϵ�� * ����(y^2 + x^2)
            twist.linear.x = 0.5 * sqrt(pow(T1toT2.transform.translation.x, 2) + pow(T1toT2.transform.translation.y, 2));
            //C.����
            pub.publish(twist);
        }
        catch (const std::exception& e)
        {
            ROS_INFO("������ʾ: %s", e.what());
        }

        rate.sleep();
        ros::spinOnce();

    }


    return 0;
}


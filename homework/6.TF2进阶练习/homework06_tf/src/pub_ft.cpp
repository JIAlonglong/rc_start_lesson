#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
   ������:��Ҫ�����ڹ��λ����Ϣ,ת��������ڴ���������ϵ,������
   ׼��:
      ����:   /turtle1/pose
      ��Ϣ:   turtlesim/Pose

       ����:
       1.����ͷ�ļ�
       2.���ñ���,��ʼ��,NodeHandle;
       3.�������Ķ���,����  /turtle1/pose
       4.�ص����������ĵ���Ϣ:��λ����Ϣת����������Թ�ϵ������(��ע)
       5.spin()
 */
 //���������������
static std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose) {
    //��ȡλ����Ϣ,ת������Թ�ϵ,������
    //������������
    static tf2_ros::TransformBroadcaster pub;
    //��֯����������Ϣ
    geometry_msgs::TransformStamped ts;
    ts.child_frame_id = turtle_name;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    //����ϵƫ����  �ڹ���������������
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;  //ƽ������ϵ��z��
    //����ϵ��Ԫ��
         /*
            λ����Ϣ��û����Ԫ��,�����и�ƫ���Ƕ�,����֪�ڹ���2D,û�з����͸����Ƕ�,���Կ��Եó��ڹ�
            ��ŷ����: 0 0 theta
          */
          //��ŷ����ת��Ϊ��Ԫ��
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    //������Ԫ��
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //����
    pub.sendTransform(ts);
}

int main(int argc, char* argv[])
{
    //���ñ���,��ʼ��,NodeHandle
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;
    // ͨ����������
    if (argc != 2) {
        ROS_ERROR("�봫��һ������!");
        return 1;
    }
    else {
        turtle_name = argv[1];
    }
    //�������Ķ���,���Ļ������ƴӲ�������
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 100, doPose);
    //�ص�����
    ros::spin();
    return 0;
}

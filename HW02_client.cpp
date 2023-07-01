#include "ros/ros.h"
#include "serve/AddTwoInts.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"kehu");

    ros::NodeHandle nh;
//����һ���ͻ��˶���
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");
//�ύ���󲢴�����Ӧ
    serve::AddTwoInts ai;
//��֯����
  ai.request.a = atoi(argv[1]);
  ai.request.b = atoi(argv[2]);
//������Ӧ
  bool flag = client.call(ai);
  if(flag){
    ROS_INFO("��Ӧ�ɹ�");
    ROS_INFO("��Ӧ��� = %d",ai.response.sum);
  } else{
    ROS_INFO("����ʧ��");
  }
    return 0;
}

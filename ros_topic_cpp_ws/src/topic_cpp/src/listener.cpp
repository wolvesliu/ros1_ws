#include "ros/ros.h"
#include "std_msgs/String.h"

//回调函数，当有新消息到达chatter话题时它就会被调用
//回调函数不能做太多事情，否则会一直运行，导致下一个触发始终不能再来运行，所以回调函数要高效
void chatterCallback(const std_msgs::String::ConstPtr& msg) //std_msgs::String是消息的结构，ConstPtr常指针，msg是以常指针的形式指向std_msgs::String
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());//打印 指针类型调用
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL,""); //打印中文的时候避免乱码
  ros::init(argc, argv, "listener");//初始化ROS,节点名称为talker 

  ros::NodeHandle n;//为这个进程的节点创建句柄

  //通过主节点订阅chatter话题.每当有新消息到达时，ROS将调用chatterCallback()函数.第二个参数是队列大小
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//创建订阅者

  //等待消息传来，消息没来就等待，消息来了就去执行回调函数。
  ros::spin();//启动了一个自循环，一直循环等待回调函数，不会到下面打return 0

  return 0;
}

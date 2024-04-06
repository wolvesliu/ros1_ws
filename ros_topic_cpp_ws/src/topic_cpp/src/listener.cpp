#include "ros/ros.h"
#include "std_msgs/String.h"

//回调函数，当有新消息到达chatter话题时它就会被调用
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");//初始化ROS,节点名称为talker 

  ros::NodeHandle n;//为这个进程的节点创建句柄

  //通过主节点订阅chatter话题.每当有新消息到达时，ROS将调用chatterCallback()函数.第二个参数是队列大小
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//创建订阅者

  ros::spin();//启动了一个自循环

  return 0;
}
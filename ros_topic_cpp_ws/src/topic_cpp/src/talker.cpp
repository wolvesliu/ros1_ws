#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker"); //初始化ROS节点,节点名称为talker 

  ros::NodeHandle n; //为这个进程的节点创建句柄

  //告诉主节点我们将要在chatter话题上发布一个类型为std_msgs/String的消息。
  //第1个参数话题名称. 第二个参数是发布队列的大小,它将最多缓存1000条消息，不然就会丢弃旧消息。
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//创建发布者

  //它会记录从上次调用Rate::sleep()到现在已经有多长时间，并休眠正确的时间。
  //以每秒10次的速率向chatter循环发布消息
  ros::Rate loop_rate(10); //指定循环的频率,以10Hz运行

  //ros::ok()在以下情况会返回false：收到SIGINT信号（Ctrl+C）...
  int count = 0;
  while (ros::ok())
  {
    //初始化消息数据
    std_msgs::String msg;//声明消息
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    //发布消息
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);//把这个信息广播给了任何已连接的节点。

    ros::spinOnce();
    //按照循环频率延时
    loop_rate.sleep();//使用ros::Rate在剩下的时间内睡眠，以让我们达到10Hz的发布速率
    ++count;
  }


  return 0;
}
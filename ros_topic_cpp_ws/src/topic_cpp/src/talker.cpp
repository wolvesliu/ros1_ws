#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  setlocale(LC_ALL,""); //打印中文的时候避免乱码
  
  ros::init(argc, argv, "talker"); //初始化ROS节点,节点名称为talker 

  ros::NodeHandle n; //为这个进程的节点创建句柄。管理ros相关的api等资源，创建发布者要用到

  //告诉主节点我们将要在chatter话题上发布一个类型为std_msgs/String的消息。
  //第1个参数话题名称. 第二个参数是发布队列的大小,它将最多缓存1000条消息，不然就会丢弃旧消息，保留新消息。
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//创建发布者

  //它会记录从上次调用Rate::sleep()到现在已经有多长时间，并休眠正确的时间。
  //以每秒10次的速率向chatter循环发布消息
  ros::Rate loop_rate(10); //指定循环的频率,以10Hz运行

  //设置编号，计数，看循环了多少次
  int count = 0;
  // 用来干：封装数据、发布消息
  while (ros::ok())//如果节点活着就一直循环，ros::ok()在以下情况会返回false：收到SIGINT信号（Ctrl+C）...
  {
    //初始化消息数据
    std_msgs::String msg;//声明消息
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    //发布消息
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);//把这个信息广播给了任何已连接的节点。    
    
    //按照循环频率延时
    loop_rate.sleep();//使用ros::Rate在剩下的时间内睡眠，以让我们达到10Hz的发布速率
    ++count; //count++ 都行，都是计数加1

    // 处理一次回调函数，然后继续执行后续代码，但是发布节点没有回调函数，所以可以不写，但是官方推荐写
    ros::spinOnce();
  }


  return 0;
}

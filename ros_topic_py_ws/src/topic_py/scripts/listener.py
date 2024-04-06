#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    
def listener():
    rospy.init_node('listener', anonymous=True)#创建订阅者节点; 第二个参数：为节点生成唯一的名称

    rospy.Subscriber("chatter", String, callback)#订阅了chatter话题,类型是std_msgs.msgs.String。当接收到新消息时，callback函数被调用

    rospy.spin() #只是不让你的节点退出，不影响订阅者回调函数，因为它们有自己的线程。

if __name__ == '__main__':
    listener()
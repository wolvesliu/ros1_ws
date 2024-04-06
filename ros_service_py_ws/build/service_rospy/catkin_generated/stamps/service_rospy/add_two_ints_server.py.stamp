#!/usr/bin/env python

from __future__ import print_function

from beginner_tutorials.srv import AddTwoInts,AddTwoIntsResponse

import rospy

def handle_add_two_ints(req):
    print("Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b)))
    return AddTwoIntsResponse(req.a + req.b)

def add_two_ints_server():
    rospy.init_node('add_two_ints_server_node') #创建服务端节点

    #创建服务。服务名为add_two_ints，服务类型为AddTwoInts，所有的请求（request）都传递给了handle_add_two_ints函数，响应函数
    s = rospy.Service('add_two_ints', AddTwoInts, handle_add_two_ints) 

    print("Ready to add two ints.")
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
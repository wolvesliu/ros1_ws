#!/usr/bin/env python

from __future__ import print_function

import sys
import rospy
from beginner_tutorials.srv import *

def add_two_ints_client(x, y):
    rospy.wait_for_service('add_two_ints')#等待服务上线。在add_two_ints服务可用之前一直阻塞

    try:
        add_two_ints = rospy.ServiceProxy('add_two_ints', AddTwoInts)#为服务的调用创建了一个句柄（handle）。服务类型：AddTwoInts

        resp1 = add_two_ints(x, y) #使用这个句柄，就像普通的函数一样调用它。
        return resp1.sum
    
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

def usage():
    return "%s [x y]"%sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting %s+%s"%(x, y))
    print("%s + %s = %s"%(x, y, add_two_ints_client(x, y)))
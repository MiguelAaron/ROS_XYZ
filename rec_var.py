#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def msg1(D):
  rospy.loginfo("Recibo: %s" % D.data)

def msg2(D):
  rospy.loginfo("Recibo: %s" % D.data)

def msg3(D):
  rospy.loginfo("Recibo: %s" % D.data)

def rec_var():
  rospy.init_node("rec_var", anonymous=False)
  rospy.Subscriber('mensaje1', String, msg1)
  rospy.Subscriber('mensaje2', String, msg2)
  rospy.Subscriber('mensaje3', String, msg3)
  rospy.spin()

if __name__ == '__main__':
 print "Esperando todos los mensajes..."
 rec_var()


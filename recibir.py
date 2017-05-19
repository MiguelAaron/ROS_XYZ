#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def Resp(D):
  rospy.loginfo("Escucho %s" % D.data)

def recibir():
  rospy.init_node('recibir', anonymous=True)
  rospy.Subscriber("mensaje", String, Resp)
  rospy.spin()

if __name__ == '__main__':
  print "Esperando datos..."
  recibir()

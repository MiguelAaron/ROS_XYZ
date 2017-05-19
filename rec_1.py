#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def mensaje(D):
  rospy.loginfo("Recibo: %s" % D.data)

def recibir():
  rospy.init_node("rec_1", anonymous=False)
  rospy.Subscriber('mensaje1', String, mensaje)
  rospy.spin()

if __name__ == '__main__':
  print "Espero mensaje 1..."
  recibir()
  

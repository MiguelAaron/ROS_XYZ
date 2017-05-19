#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def mensaje(D):
  rospy.loginfo("Escucho: %s" % D.data)

def recibir():
  rospy.init_node("rec_3", anonymous=False)
  rospy.Subscriber('mensaje3', String, mensaje)
  rospy.spin()

if __name__ == '__main__':
  print "Esperando mensaje 3..."
  recibir()

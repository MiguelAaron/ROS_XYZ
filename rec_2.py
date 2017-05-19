#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def mensaje(D):
  rospy.loginfo("Recibo: %s" % D.data)

def recibir():
  rospy.init_node("rec_2", anonymous=False)
  rospy.Subscriber('mensaje2', String, mensaje)
  rospy.spin()

if __name__ == '__main__':
  print "Espero mensaje 2..."
  recibir()

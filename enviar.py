#!/usr/bin/env python 

import rospy
from std_msgs.msg import String

def enviar():
  pub = rospy.Publisher('mensaje', String, queue_size=10)
  rospy.init_node("enviar", anonymous=True)
  rate = rospy.Rate(10)

  while not rospy.is_shutdown():
    M = "Hola mundo %s" % rospy.get_time()
    rospy.loginfo(M)
    #rospy.loginfo(open("/sys/class/therm/ther_zone0/temp"))
    pub.publish(M)
    rate.sleep()

if __name__ == '__main__':
  try:
    enviar()
  except rospy.ROSInterruptException:
    pass

#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def enviar():
  rospy.init_node("varios", anonymous=False)
  N_1 = rospy.Publisher('mensaje1', String, queue_size=10)
  N_2 = rospy.Publisher('mensaje2', String, queue_size=10)
  N_3 = rospy.Publisher('mensaje3', String, queue_size=10)
  T = rospy.Rate(5)

  m2 = 0
  m3 = 0
  c2 = 0
  c3 = 0
  
  while not rospy.is_shutdown():
    M_1 = "Mensaje 1: %s" % rospy.get_time()
    rospy.loginfo(M_1)
    N_1.publish(M_1)
    m2 += 1
    m3 += 1

    if m2 == 2:
      M_2 = "Mensaje 2: %s" % c2
      rospy.loginfo(M_2)
      N_2.publish(M_2)
      c2 += 1
      m2 = 0
    
    if m3 == 5:
      M_3 = "Mensaje 3: %s" % c3
      rospy.loginfo(M_3)
      N_3.publish(M_3)
      c3 += 1
      m3 = 0

    T.sleep()


if __name__ == '__main__':
  try:
    enviar()
  except rospy.ROSInterruptException:
    pass
    

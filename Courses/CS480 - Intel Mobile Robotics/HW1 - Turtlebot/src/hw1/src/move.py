#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute
PI = 3.1415926535897

def move():    
    
    rospy.wait_for_service('turtle1/teleport_absolute')
    turtle1_teleport_absolute = rospy.ServiceProxy('turtle1/teleport_absolute', TeleportAbsolute)
    resp1 = turtle1_teleport_absolute(3, 3, 0.5)

    rospy.init_node('robot_cleaner', anonymous=True)
    velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    vel_msg = Twist()

    speed = 3
    angle = 180

    #Converting from angles to radians
    angular_speed = 2
    relative_angle = angle*2*PI/360

    vel_msg.linear.x = abs(speed)
    vel_msg.linear.y = 0
    vel_msg.linear.z = 0
    vel_msg.angular.x = 0
    vel_msg.angular.y = 0
    vel_msg.angular.z = abs(2)


    # Setting the current time for distance calculus
    t0 = rospy.Time.now().to_sec()
    current_angle = 0

    #Move Robot in circle
    while(current_angle < relative_angle):
        velocity_publisher.publish(vel_msg)
        t1 = rospy.Time.now().to_sec()
        current_angle = angular_speed*(t1-t0)



    vel_msg.angular.z = -abs(2)


    # Setting the current time for distance calculus
    t0 = rospy.Time.now().to_sec()
    current_angle = 0
    
    #Move Robot in circle
    while(current_angle < relative_angle):
        velocity_publisher.publish(vel_msg)
        t1 = rospy.Time.now().to_sec()
        current_angle = angular_speed*(t1-t0)

    resp1 = turtle1_teleport_absolute(5, 7, 0.5)

     # Setting the current time for distance calculus
    t0 = rospy.Time.now().to_sec()
    current_angle = 0

    angle = 360

    #Converting from angles to radians
    relative_angle = angle*2*PI/360
    
    #Move Robot in circle
    while(current_angle < relative_angle):
        velocity_publisher.publish(vel_msg)
        t1 = rospy.Time.now().to_sec()
        current_angle = angular_speed*(t1-t0)
    
    vel_msg.linear.x = 0    
    vel_msg.angular.z = 0
    velocity_publisher.publish(vel_msg)

    rospy.spin()

if __name__ == "__main__":
    try:
        #Testing our function
        move()
    except rospy.ROSInterruptException: 
        pass

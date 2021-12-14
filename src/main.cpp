#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <iostream>

#define PI 3.14

int main(int argc, char **argv) {
  std::cout << "Hello World!\n";

  ros::init(argc, argv, "my_little_nod");

  ros::NodeHandle n;

  ros::Publisher left_back_leg_3 = n.advertise<std_msgs::Float64>(
      "left_back_leg_3_controller/command", 1000);
  ros::Publisher left_mid_leg_3 =
      n.advertise<std_msgs::Float64>("left_mid_leg_3_controller/command", 1000);
  ros::Publisher left_front_leg_3 = n.advertise<std_msgs::Float64>(
      "left_front_leg_3_controller/command", 1000);
  ros::Publisher right_back_leg_3 = n.advertise<std_msgs::Float64>(
      "right_back_leg_3_controller/command", 1000);
  ros::Publisher right_mid_leg_3 = n.advertise<std_msgs::Float64>(
      "right_mid_leg_3_controller/command", 1000);
  ros::Publisher right_front_leg_3 = n.advertise<std_msgs::Float64>(
      "right_front_leg_3_controller/command", 1000);

  std_msgs::Float64 position_msg;
  position_msg.data = -2 * PI / 3;


  while (ros::ok()) {

      left_back_leg_3.publish(position_msg);
  left_mid_leg_3.publish(position_msg);
  left_front_leg_3.publish(position_msg);
  //right_back_leg_3.publish(position_msg);
  //right_mid_leg_3.publish(position_msg);
  //right_front_leg_3.publish(position_msg);
  }

  return 0;
}
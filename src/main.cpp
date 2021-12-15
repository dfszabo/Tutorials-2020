#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <iostream>

#define PI 3.14

int main(int argc, char **argv) {
  std::cout << "Executing commands...\n";

  ros::init(argc, argv, "my_little_nod");

  ros::NodeHandle n;

  ros::Publisher left_back_leg_1 = n.advertise<std_msgs::Float64>(
      "left_back_leg_1_controller/command", 1000);
  ros::Publisher left_mid_leg_1 =
      n.advertise<std_msgs::Float64>("left_mid_leg_1_controller/command", 1000);
  ros::Publisher left_front_leg_1 = n.advertise<std_msgs::Float64>(
      "left_front_leg_1_controller/command", 1000);
  ros::Publisher right_back_leg_1 = n.advertise<std_msgs::Float64>(
      "right_back_leg_1_controller/command", 1000);
  ros::Publisher right_mid_leg_1 = n.advertise<std_msgs::Float64>(
      "right_mid_leg_1_controller/command", 1000);
  ros::Publisher right_front_leg_1 = n.advertise<std_msgs::Float64>(
      "right_front_leg_1_controller/command", 1000);

  ros::Publisher left_back_leg_2 = n.advertise<std_msgs::Float64>(
      "left_back_leg_2_controller/command", 1000);
  ros::Publisher left_mid_leg_2 =
      n.advertise<std_msgs::Float64>("left_mid_leg_2_controller/command", 1000);
  ros::Publisher left_front_leg_2 = n.advertise<std_msgs::Float64>(
      "left_front_leg_2_controller/command", 1000);
  ros::Publisher right_back_leg_2 = n.advertise<std_msgs::Float64>(
      "right_back_leg_2_controller/command", 1000);
  ros::Publisher right_mid_leg_2 = n.advertise<std_msgs::Float64>(
      "right_mid_leg_2_controller/command", 1000);
  ros::Publisher right_front_leg_2 = n.advertise<std_msgs::Float64>(
      "right_front_leg_2_controller/command", 1000);

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

  std_msgs::Float64 msg_left_back_1;
  std_msgs::Float64 msg_left_mid_1;
  std_msgs::Float64 msg_left_front_1;
  std_msgs::Float64 msg_right_back_1;
  std_msgs::Float64 msg_right_mid_1;
  std_msgs::Float64 msg_right_front_1;

  std_msgs::Float64 msg_left_back_2;
  std_msgs::Float64 msg_left_mid_2;
  std_msgs::Float64 msg_left_front_2;
  std_msgs::Float64 msg_right_back_2;
  std_msgs::Float64 msg_right_mid_2;
  std_msgs::Float64 msg_right_front_2;

  int state = -1;
  while (ros::ok()) {

    switch (state) {
    // pick up 3 leg 1-2
    case 0: {
      std::cout << "case 0\n";
      msg_left_back_2.data = PI / 12;
      msg_left_mid_2.data = PI / 12;
      msg_left_front_2.data = PI / 12;
      msg_right_back_2.data = -PI / 12;
      msg_right_mid_2.data = -PI / 12;
      msg_right_front_2.data = -PI / 12;

      left_back_leg_2.publish(msg_left_back_2);
      right_mid_leg_2.publish(msg_right_mid_2);
      left_front_leg_2.publish(msg_left_front_2);
      break;
    }
    // move backward the 3 leg which is in the air (preparing for propellation forward)
    case 1: {
      std::cout << "case 1\n";
      msg_left_back_1.data = -PI / 12;
      msg_left_front_1.data = -PI / 12;
      msg_right_mid_1.data = PI / 12;

      left_back_leg_1.publish(msg_left_back_1);
      right_mid_leg_1.publish(msg_right_mid_1);
      left_front_leg_1.publish(msg_left_front_1);
      break;
    }
    // put down 3 leg 1-2
    case -1: // 0th state, somewhy the first execution of the statemachine does not do anything
             // so this will became the first which basically doing nothing compared to the
             // base position of the robot
    case 4:
    case 2: {
      std::cout << "case 2,4\n";
      msg_left_back_2.data = 0;
      msg_left_front_2.data = 0;
      msg_right_mid_2.data = 0;

      left_back_leg_2.publish(msg_left_back_2);
      right_mid_leg_2.publish(msg_right_mid_2);
      left_front_leg_2.publish(msg_left_front_2);
      break;
    }
    // lift body by using these 3 legs
    case 3: {
      std::cout << "case 3\n";
      msg_left_back_2.data = -PI / 12;
      msg_left_front_2.data = -PI / 12;
      msg_right_mid_2.data = PI / 12;

      left_back_leg_2.publish(msg_left_back_2);
      right_mid_leg_2.publish(msg_right_mid_2);
      left_front_leg_2.publish(msg_left_front_2);
      
      // move forward up 3 leg 1-2
      msg_left_back_1.data = PI / 12;
      msg_left_front_1.data = PI / 12;
      msg_right_mid_1.data = -PI / 12;

      left_back_leg_1.publish(msg_left_back_1);
      right_mid_leg_1.publish(msg_right_mid_1);
      left_front_leg_1.publish(msg_left_front_1);
      break;
    }
    // move to original place the 3 leg 1-2
    case 5: {
      std::cout << "case 4\n";
      msg_left_back_1.data = 0;
      msg_left_front_1.data = 0;
      msg_right_mid_1.data = 0;

      left_back_leg_1.publish(msg_left_back_1);
      right_mid_leg_1.publish(msg_right_mid_1);
      left_front_leg_1.publish(msg_left_front_1);
      break;
    }
    default:
      state = -1;
      break;
    }

    state++;

    ros::Duration(1.5).sleep();
  }

  return 0;
}
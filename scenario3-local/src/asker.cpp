#include <iostream>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
using namespace std;

string answer = "Ah! Ah! Ah! You didn't say the magic word!";

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    string correct_answer = "mr. hacker";
    string flag = "Correct! Here's your password: 8yU-PL2fe8*B=&yu";
    if (msg->data.c_str() == correct_answer) {
        answer = flag;
    }
}

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
    
  ros::init(argc, argv, "node_rctf");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("user_answer", 1000, chatterCallback);
  ros::Publisher flag_pub = n.advertise<std_msgs::String>("flag", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok()){
    std_msgs::String msg;
    std::stringstream ss;
    ss << answer;
    msg.data = ss.str();
    flag_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

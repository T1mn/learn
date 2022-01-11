#include "ros/ros.h"

int main (int argv, char *argc[])
{
    setlocale(LC_ALL,"");
    ros::init(argv,argc,"onePlusOne");
    ROS_INFO("onePlusOneis Two");
    return 0;
}
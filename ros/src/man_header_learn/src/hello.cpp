#include "ros/ros.h"
#include "../include/man_header_learn/hello.h"

namespace hello_ns{
    void HelloPub::run(){
        ROS_INFO("Heeeelllloo!");
    }
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "man_header");
    hello_ns::HelloPub hello;
    hello.run();
    return 0;
}
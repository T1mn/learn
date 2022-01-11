#include "ros/ros.h"
#include "add_nums_service/add_int.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        ROS_ERROR("arg counts is not 3");
        return 1;
    }
    ros::init(argc, argv, "add_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<add_nums_service::add_int>("add_nums");
    ros::service::waitForService("add_nums");
    add_nums_service::add_int req;
    req.request.num1 = atoi(argv[1]);
    req.request.num2 = atoi(argv[2]);
    bool flag = client.call(req);
    if (flag)
        ROS_INFO("call success!");
    else
    {
        ROS_ERROR("somthing wrong!");
        return 1;
    }
    return 0;
}
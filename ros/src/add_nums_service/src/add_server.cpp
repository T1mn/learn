#include "ros/ros.h"
#include "add_nums_service/add_int.h"

bool handleTwoNums(add_nums_service::add_int::Request &req, add_nums_service::add_int::Response &resp)
{
    int32_t nums1 = req.num1;
    int32_t nums2 = req.num2;
    ROS_INFO("server get two nums");

    if (nums1 < 0 || nums2 < 0)
    {
        ROS_ERROR("something wrong");

        return false;
    }

    ROS_INFO("two nums are OK!");
    resp.sum = nums1 + nums2;
    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "add_server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("add_nums",handleTwoNums);
    ros::spin();
    return 0;
}
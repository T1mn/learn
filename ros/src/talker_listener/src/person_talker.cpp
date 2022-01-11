#include "ros/ros.h"
#include "talker_listener/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<talker_listener::Person>("chatter", 10);
    talker_listener::Person sunWuKong;
    sunWuKong.name = "MeiHouWang";
    sunWuKong.age = 5000;
    sunWuKong.height = 175.5;
    ros::Rate r(1);
    while (ros::ok)
    {
        ROS_INFO("my name is %s, my age is %d, my height is %.2f cm", sunWuKong.name.c_str(), sunWuKong.age, sunWuKong.height);
        pub.publish(sunWuKong);
        sunWuKong.age++;
        r.sleep();
        ros::spinOnce();
    }
    return 0;
}
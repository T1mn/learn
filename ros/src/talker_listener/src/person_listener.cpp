#include "ros/ros.h"
#include "talker_listener/Person.h"

void handlePerson(const talker_listener::Person::ConstPtr &pPerson)
{
    ROS_INFO("get Person, his name is %s, my age is %d, my height is %.2f cm", pPerson->name.c_str(), pPerson->age, pPerson->height);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<talker_listener::Person>("chatter", 10, handlePerson);
    ros::spin();
    return 0;
}
#include <ros/ros.h>
#include <stdio.h>
#include <dji_sdk/dji_drone.h>
#include <cstdlib>
#include "client.h"
#include <geometry_msgs/TransformStamped.h>

#define DEBUG

geometry_msgs::TransformStamped drone_1;
geometry_msgs::TransformStamped drone_2;
geometry_msgs::TransformStamped drone_3;
geometry_msgs::TransformStamped stick_1;
geometry_msgs::TransformStamped stick_2;

ros::Subscriber sub_drone_1;
ros::Subscriber sub_drone_2;
ros::Subscriber sub_drone_3;
ros::Subscriber sub_stick_1;
ros::Subscriber sub_stick_2;

ros::Publisher debug_pub;

void viconCallback1(const geometry_msgs::TransformStamped t)
{
	drone_1 = t;
};

void viconCallback2(const geometry_msgs::TransformStamped t)
{
	drone_2 = t;
};

void viconCallback3(const geometry_msgs::TransformStamped t)
{
	drone_3 = t;
};

void viconCallback4(const geometry_msgs::TransformStamped t)
{
	stick_1= t;
	debug_pub.publish(stick_1);
};

void viconCallback5(const geometry_msgs::TransformStamped t)
{
	stick_2 = t;
};

int main(int argc, char **argv)
{
	ros::init(argc,argv,"vicon_ros_bridge");

    ros::NodeHandle nh;
	//init the SDK part
    DJIDrone* drone = new DJIDrone(nh);

	
	//init the Vicon part
	 sub_drone_1 = nh.subscribe("vicon/drone_1/drone_1",1000, viconCallback1);
	 sub_drone_2 = nh.subscribe("vicon/drone_2/drone_2",1000, viconCallback2);
	 sub_drone_3 = nh.subscribe("vicon/drone_3/drone_3",1000, viconCallback3);
	 sub_stick_1 = nh.subscribe("vicon/stick_1/stick_1",1000, viconCallback4);
	 sub_stick_2 = nh.subscribe("vicon/stick_2/stick_2",1000, viconCallback5);

	 debug_pub = nh.advertise<geometry_msgs::TransformStamped>("wuyiyi/stick1", 1000);

	ros::spin();
    return 0;
}

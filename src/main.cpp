
#include <ros/ros.h>

#include <cstdio>
#include <timebug_msgs/TimeArray.h>


void handle_msg(const timebug_msgs::TimeArray::ConstPtr& msg)
{
	for (size_t i = 0; i < msg->foo.size(); ++i) {
		printf("Timestamp %li.%li\n", msg->foo[i].sec, msg->foo[i].nsec);
		//printf("Timestamp %u.%u\n", msg->foo[i].data.sec, msg->foo[i].data.nsec);
	}
}

int
main(int argc, char **argv)
{
	ros::init(argc, argv, "timebug");
	ros::NodeHandle n;

	ros::Subscriber sub =
	  n.subscribe<timebug_msgs::TimeArray>("/foo", 1, handle_msg);

	ros::spin();

  return 0;
}


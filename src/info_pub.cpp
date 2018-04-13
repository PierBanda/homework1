#include "ros/ros.h"
#include "std_msgs/String.h"
#include <homework1/info_msg.h>
#include "my_database.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/**
* This tutorial demonstrates simple receipt of messages over the ROS system.
*/
/**void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
ROS_INFO("I heard: [%s]", msg->data.c_str());
}
**/

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Info_pub");
	ros::NodeHandle n;
	
	ros::Publisher chatter_pub = n.advertise<homework1::info_msg>("info_persona", 1000);

  	ros::Rate loop_rate(1);
	
	srand (time(NULL));
	
	homework1::info_msg persona;

	while (ros::ok())
		{
		/**
		* This is a message object. You stuff it with data, and then publish it.
		*/
		
		persona.name=names[rand() % 5];
		persona.age=rand() % 20 +18;
		persona.corso=corsi[rand() % 5];
		
		/**std::stringstream ss;
		ss << "hello world " << count;
		homework1.data = ss.str();**/

		ROS_INFO("%s eta %i del corso di %s",persona.name.c_str() ,persona.age, persona.corso.c_str());

		/**
		* The publish() function is how you send messages. The parameter
		* is the message object. The type of this object must agree with the type
		* given as a template parameter to the advertise<>() call, as was done
		* in the constructor above.
		*/
		chatter_pub.publish(persona);

		ros::spinOnce();

		loop_rate.sleep();
		}

	
	return 0;
}

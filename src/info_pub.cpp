#include "ros/ros.h" /*ros library*/
#include <homework1/info_msg.h> /*custom message type*/
#include "my_database.h" /*header file whith informations abaut people*/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Info_pub"); /*inizialize ros node*/
	ros::NodeHandle n;
	
	ros::Publisher chatter_pub = n.advertise<homework1::info_msg>("info_persona", 1000); /*inizialize topic*/

  	ros::Rate loop_rate(1); /*1 Hz*/
	
	srand (time(NULL)); /*set random seed*/
	
	homework1::info_msg persona; /*create a message object */ 

	while (ros::ok()) 
		{ /*setting the info that will be pubblished*/
		persona.name=names[rand() % 5]; /*take a rand name from my_database.h*/
		persona.age=rand() % 20 +18; /*take a rand number between 18-38*/
		persona.corso=corsi[rand() % 5]; /*take a rand corso from my_database.h*/
		/* show the current data of persona
		ROS_INFO("%s eta %i del corso di %s",persona.name.c_str() ,persona.age, persona.corso.c_str());
		*/
		/**
		* The publish() function is how you send messages. The parameter
		* is the message object. The type of this object must agree with the type
		* given as a template parameter to the advertise<>() call, as was done
		* in the constructor above.
		*/
		chatter_pub.publish(persona); /*publishing the data*/

		ros::spinOnce(); 

		loop_rate.sleep();
		}

	
	return 0;
}

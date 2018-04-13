#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
/* the option node take a char from console, and if is valid, publish the char*/
int main(int argc, char **argv)
{
	ros::init(argc, argv, "options");/*inizialize ros node*/
	ros::NodeHandle n;

	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("viewOption", 2); /*inizialize topic*/

  ros::Rate loop_rate(1); /*1 Hz*/
  /*chow to the user the allowed options*/
  std::cout << "opzioni per la visualizzazione delle info:\n";
  std::cout << "(a) tutte le informazioni:\n";
  std::cout << "(n) stampa solo i nomi:\n";
  std::cout << "(e) stampa solo l'eta':\n";
  std::cout << "(c) stampa solo i nomi dei corsi:\n";
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::cin >> msg.data; /*wait for a user input*/
   
	/* show the current input
	ROS_INFO("%s", msg.data.c_str());
	*/


    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
	if( (*msg.data.c_str()== 'a') 
	 || (*msg.data.c_str()== 'n')
	 || (*msg.data.c_str()== 'e')
	 || (*msg.data.c_str()== 'c') )
	{
	    chatter_pub.publish(msg);
	}
	else 
 	    std::cout << "valore non valido!:\n"; /*error message if the input is not allowed*/

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

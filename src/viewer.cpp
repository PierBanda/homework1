#include "ros/ros.h"
#include "std_msgs/String.h"
#include <homework1/info_msg.h>
#include <iostream>
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
char  currentOption='a';
void changeViewOption(const std_msgs::String::ConstPtr& opt)
{

  currentOption = *opt->data.c_str();
  std::cout << "opzioni cambiate:";
  switch(currentOption) {
	case 'a' :
 		std::cout << "stampo tutti i dati" << "\n";
	break;
	case 'n' :
		std::cout << "stampo solo i nomi" << "\n";
	break;
	case 'e' :
		std::cout << "stampo solo l'età" << "\n";
	break;
	case 'c' :
		std::cout << "stampo solo i nomi dei corsi" << "\n";
	break;
	default :
		std::cout << "errore ricevo una opzione non valida" << "\n";
	}
}

void infoPersonaCallback(const homework1::info_msg persona)
{
	
  switch(currentOption) {
	case 'a' :
		ROS_INFO("%s, eta %i, del corso di %s",
		persona.name.c_str() ,persona.age, persona.corso.c_str()); 
	break;
	case 'n' :
		ROS_INFO("%s ",
		persona.name.c_str()); 
	break;
	case 'e' :
		ROS_INFO("eta %i",
		persona.age); 
	break;
	case 'c' :
		ROS_INFO("corso di %s",
		persona.corso.c_str());
	break;
	default :
		std::cout << "errore ricevo una opzione non valida" << "\n";
	}
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "viewer");


  ros::NodeHandle n;
  
  ros::Subscriber option = n.subscribe("viewOption", 1000, changeViewOption);
  ros::Subscriber data = n.subscribe("info_persona", 1000, infoPersonaCallback);
  
  ros::spin();
  return 0;
}

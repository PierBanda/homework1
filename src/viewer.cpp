#include "ros/ros.h" /*ros library*/
#include "std_msgs/String.h" /*message*/
#include <homework1/info_msg.h> /*custom message type*/
#include <iostream> /*cout cin*/
/*global variable for the current selected option 
 *it can be change by the option node
 *a -> all
 *n -> only names
 *e -> only ages
 *c -> only course
*/
char  currentOption='a';
void changeViewOption(const std_msgs::String::ConstPtr& opt) /*called when viewer recive a message from option*/
{
  currentOption = *opt->data.c_str();
  std::cout << "opzioni cambiate:" << "\n" ;
  switch(currentOption) { /*print in to the console if the current option was change*/
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
		std::cout << "errore ricevo una opzione non valida" << "\n"; /*error message if the option char is not valid*/
	}
}

void infoPersonaCallback(const homework1::info_msg persona) /*called when viewer recive a message from info_pub*/
{
  switch(currentOption) { /*print the recived info according the current option*/
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
		std::cout << "errore ricevo una opzione non valida" << "\n"; /*error message if the option char is not valid*/
	}
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "viewer");/*inizialize ros node*/
  ros::NodeHandle n;
  
  ros::Subscriber option = n.subscribe("viewOption", 1000, changeViewOption); /*subcribe to option's topic*/
  ros::Subscriber data = n.subscribe("info_persona", 1000, infoPersonaCallback); /*subcribe to info_pub's topic*/
  
  ros::spin();
  return 0;
}

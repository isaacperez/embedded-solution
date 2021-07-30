#include "utilsROS.h"

#include <sstream>
#include <iostream>

#include "ros/ros.h"

void utilsROS::mostrarInfoNodo(){
	
	std::stringstream ss;
	ss << "Lanzado nodo [" << ros::this_node::getNamespace() << ":" << ros::this_node::getName() << "]";
	
	ROS_INFO("%s", ss.str().c_str());

}


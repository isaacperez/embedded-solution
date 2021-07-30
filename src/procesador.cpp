#include "ros/ros.h"
#include "std_msgs/String.h"

#include "CONSTANTES.h"
#include "utilsROS.h"
#include "procesadorAux.h"

void camaraCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I recived: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "procesador");

	// Mostramos la información básica del nodo
	utilsROS::mostrarInfoNodo();

	// Código principal
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("imagen_camara", 1000, camaraCallback);

	ros::spin();

	return 0;
}

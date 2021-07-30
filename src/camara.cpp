#include "ros/ros.h"
#include "std_msgs/String.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <NVX/nvx.h>
#include <NVX/nvx_timer.hpp>
#include <NVX/Application.hpp>
#include <NVX/ConfigParser.hpp>
#include <OVX/FrameSourceOVX.hpp>
#include <OVX/RenderOVX.hpp>
#include <NVX/SyncTimer.hpp>
#include <OVX/UtilityOVX.hpp>

#include <sstream>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

#include "CONSTANTES.h"
#include "utilsROS.h"
#include "camaraAux.h"

int main(int argc, char **argv)
{

	// Inicializamos todo lo necesario en ROS
	ros::init(argc, argv, "camara");

	// Mostramos la información básica del nodo
	utilsROS::mostrarInfoNodo();
	
	// Mostramos información de las librerias a utilizar
	camaraAux::mostrarInfoLibreriasPorConsola();

	// CODIGO DE PRUEBA:CARGA IMAGEN Y LA VISUALIZA HASTA PULSACION DE TECLA [ELIMINAR]
	cv::Mat image;
    image = cv::imread("/home/nvidia/catkin_ws/src/peser/data/img/prueba.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.
    cv::imshow( "Display window", image );                   // Show our image inside it.

    cv::waitKey(0);                                          // Wait for a keystroke in the window


	// Código principal
	ros::NodeHandle n;

	ros::Publisher imagen_camara_pub = n.advertise<std_msgs::String>("imagen_camara", 1000);

	ros::Rate loop_rate(10);
	
	int count = 0;
	while(ros::ok())
	{
		std_msgs::String msg;

		std::stringstream ss;
		ss << "Imagen " << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		imagen_camara_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}


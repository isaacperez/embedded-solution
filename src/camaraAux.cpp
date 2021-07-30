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

#include <iostream>

#include "camaraAux.h"

void camaraAux::mostrarInfoLibreriasPorConsola()
{

	std::cout << "Info Libreria VisionWorks:" << std::endl;
	nvxio::Application &app = nvxio::Application::get();
    ovxio::printVersionInfo();
	
	std::cout << "Info Librería OpenCV:" << std::endl;
	std::cout << cv::getBuildInformation().c_str() << std::endl;

}

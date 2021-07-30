cmake_minimum_required(VERSION 2.8.3)

project(peser)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
 roscpp
 std_msgs)

# Añadimos las librerias necesarias
find_package(OpenCV 2.4.13.1 REQUIRED) # Es necesario poner 2.4.13.1 para que coja el OpenCV del sistema (Opencv4Tegra) en lugar del que trae ROS
find_package(Boost REQUIRED COMPONENTS system)

# Creamos nuestro paquete (SIN LA SIGUIENTE LINEA NO SE CREA EL PAQUETE!)
catkin_package(
   INCLUDE_DIRS headers)

# Añadimos los directorios necesarios
include_directories(
  /usr/share/visionworks/sources/nvxio/include
 ${OpenCV_INCLUDE_DIRS}
 ${catkin_INCLUDE_DIRS}
 headers)

link_directories(/usr/local/cuda/targets/aarch64-linux/lib /usr/share/visionworks/sources/libs/aarch64/linux/release) 

# Construimos camara
add_executable(camara src/utilsROS.cpp src/camaraAux.cpp src/camara.cpp)                            
target_link_libraries(camara pthread ${catkin_LIBRARIES} visionworks ovx nvx gstpbutils-1.0 gstapp-1.0 gstbase-1.0 gstreamer-1.0 gobject-2.0 glib-2.0 Xrandr Xi Xxf86vm ${OpenCV_LIBRARIES} X11 GL freetype /usr/share/visionworks/sources/3rdparty/glfw3/libs/libglfw3.a pthread X11 Xi Xrandr Xxf86vm GL freetype visionworks ovx nvx gstpbutils-1.0 gstapp-1.0 gstbase-1.0 gstreamer-1.0 gobject-2.0 glib-2.0)

# Construimos procesador
add_executable(procesador src/utilsROS.cpp src/procesadorAux.cpp src/procesador.cpp)
target_link_libraries(procesador ${catkin_LIBRARIES})

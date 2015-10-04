cmake_minimum_required(VERSION 2.6)
project(geomanager)
include_directories(${YOUR_DIRECTORY})
add_executable(geomanager main.cpp Drawable.cpp Object.cpp view.cpp Physical.cpp EventManager.cpp MapManager.cpp Window.cpp Mesh.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(
     geomanager
     -lsfml-graphics
     -lsfml-window
     -lsfml-system
     ${OPENGL_LIBRARIES})
install(TARGETS geomanager RUNTIME DESTINATION bin)

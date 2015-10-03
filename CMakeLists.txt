cmake_minimum_required(VERSION 2.6)
project(geomanager)

add_executable(geomanager main.cpp Drawable.cpp personne.cpp view.cpp Physical.cpp EventManager.cpp MapManager.cpp)

find_package(OpenGL REQUIRED)

target_link_libraries(
     geomanager
     -lsfml-graphics
     -lsfml-window
     -lsfml-system
     ${OPENGL_LIBRARIES})
install(TARGETS geomanager RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
project(ComputerGraphics_Lectures VERSION 0.1.0 LANGUAGES CXX)

find_package( OpenGL REQUIRED )
include_directories( ${OPENGL_INCLUDE_DIRS} )

option( GLFW-CMAKE-STARTER-USE-GLFW-GLAD "Use GLAD from GLFW" OFF )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_LOG_LEVEL ERROR)

#==============================================================================
set(IMGUI_DIR ./3rdparty/imgui)
include_directories(${IMGUI_DIR})

set(IMGUI_SOURCES
	${IMGUI_DIR}/imgui.cpp
	${IMGUI_DIR}/imgui_demo.cpp
	${IMGUI_DIR}/imgui_draw.cpp
	${IMGUI_DIR}/imgui_tables.cpp
	${IMGUI_DIR}/imgui_widgets.cpp
	${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
	${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

#==============================================================================
add_subdirectory(3rdparty/glew)
add_subdirectory(3rdparty/glfw)
add_subdirectory(3rdparty/glm)

#==============================================================================
add_subdirectory(Lectures)
add_subdirectory(LinearAlgebra)

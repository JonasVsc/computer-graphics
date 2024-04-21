####################################
cmake_minimum_required(VERSION 3.10)
##############
project(Teste)

###############
### WINDOWS ###
###############

###############
#### LINUX ####
###############


###########################################################################
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/glfw" build)


############################################
add_executable(${PROJECT_NAME} src/main.cpp)

############################################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../../thirdparty/glfw/include")

####################################################################
target_link_libraries(${PROJECT_NAME} PUBLIC glfw ${GLFW_LIBRARIES})


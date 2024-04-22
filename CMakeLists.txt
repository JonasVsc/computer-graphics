cmake_minimum_required(VERSION 3.10)
project(computer-graphics)

############################################
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)	

#################################
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/glew-cmake)
add_subdirectory(thirdparty/SDL)

#######################
add_subdirectory(Teste)
add_subdirectory(SnakeGame)
add_subdirectory(introduction-SDL)

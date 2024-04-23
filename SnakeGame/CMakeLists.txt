project(SnakeGame)

set(EXECUTABLE_OUTPUT_PATH bin)

add_executable(${PROJECT_NAME} 
	src/main.cpp 
	src/application.h 
	src/application.cpp

	# Shaders
	src/shader.h
)


target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} libglew_static)
target_link_libraries(${PROJECT_NAME} glm)


message(STATUS "BUILD ${PROJECT_NAME}!")
project(SnakeGame)

add_executable(${PROJECT_NAME} 
	src/main.cpp 
	src/core.h 
	src/core.cpp
)


target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} libglew_static)
target_link_libraries(${PROJECT_NAME} glm)

message(STATUS "BUILD ${PROJECT_NAME}!")
project(SnakeGame)





add_executable(${PROJECT_NAME} 
	src/main.cpp 
	src/core.h 
	src/core.cpp
)

message(STATUS "BUILD ${PROJECT_NAME}!")
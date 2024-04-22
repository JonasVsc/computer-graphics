project(introduction-SDL)

add_executable(${PROJECT_NAME} 
	# MAIN
	src/main.cpp

	# GAME
	
	)

target_link_libraries(${PROJECT_NAME} SDL3-static)
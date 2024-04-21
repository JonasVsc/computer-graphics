cmake_minimum_required(VERSION 3.10)
project(Teste)


add_executable(${PROJECT_NAME} src/main.cpp)
message(STATUS "BUILD ${PROJECT_NAME}!")

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} libglew_static)
target_link_libraries(${PROJECT_NAME} glm)



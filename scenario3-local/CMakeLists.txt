cmake_minimum_required(VERSION 3.5)
project(scenario3)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)


## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(asker src/asker.cpp)
target_link_libraries(asker ${catkin_LIBRARIES})

install(TARGETS asker
								RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

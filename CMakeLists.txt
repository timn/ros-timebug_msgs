cmake_minimum_required(VERSION 2.8.3)
project(timebug_msgs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)


## Generate messages in the 'msg' folder
add_message_files(
  FILES
    TimeArray.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

include_directories(${catkin_INCLUDE_DIRS})

add_compile_options(-Wall)


add_executable(timebug src/main.cpp)
add_dependencies(timebug ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
set_target_properties(timebug PROPERTIES LINK_LIBRARIES "${catkin_LIBRARIES}")

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)


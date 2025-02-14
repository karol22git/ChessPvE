cmake_minimum_required(VERSION 2.6.2)
project(chess)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}" )
include_directories(include)
file(GLOB dir1_sources "source_code/*.cpp")
add_executable(chess ${dir1_sources})

target_link_libraries(chess ${wxWidgets_LIBRARIES})
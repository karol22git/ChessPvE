cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(chess)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


set(wxWidgets_ROOT_DIR "C:/mylibs/wxWidgets-3.3.0")
set(wxWidgets_LIB_DIR "C:/mylibs/wxWidgets-3.3.0/lib/vc_x64_lib")
include_directories("C:/mylibs/libwebp-1.4.0/libwebp-1.4.0-windows-x64/include/webp")
link_directories("C:/mylibs/libwebp-1.4.0/libwebp-1.4.0-windows-x64/lib")

find_package(wxWidgets REQUIRED COMPONENTS core base)


include("${wxWidgets_USE_FILE}" )
include_directories(include resources)
file(GLOB dir1_sources "source_code/*.cpp")
add_executable(chess ${dir1_sources})
# Wymuś dynamiczne linkowanie CRT (zalecane przy wxWidgets)
foreach(flag_var
        CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
    string(REPLACE "/MT" "/MD" ${flag_var} "${${flag_var}}")
endforeach()

target_link_libraries(chess ${wxWidgets_LIBRARIES})
target_link_libraries(chess
    ${wxWidgets_LIBRARIES}
    libwebp
    libwebpmux
    libwebpdemux
)

set_target_properties(chess PROPERTIES WIN32_EXECUTABLE TRUE)
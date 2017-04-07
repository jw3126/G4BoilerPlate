cmake_minimum_required(VERSION 3.5)
project(APPNAME)
set(CMAKE_CXX_STANDARD 14)


find_package(Geant4 REQUIRED ui_all vis_all)
include_directories(${PROJECT_SOURCE_DIR}/include)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)

# copy macro file for visualization init
configure_file(${PROJECT_SOURCE_DIR}/init.mac
        ${PROJECT_BINARY_DIR}/init.mac
        COPYONLY
        )


add_executable(APPNAME main.cpp ${sources} ${headers})
target_link_libraries(APPNAME ${Geant4_LIBRARIES})

cmake_minimum_required(VERSION 3.5)
project(APPNAME)
set(CMAKE_CXX_STANDARD 14)


find_package(Geant4 REQUIRED ui_all vis_all)
include_directories(${PROJECT_SOURCE_DIR}/include)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

set(APPNAME_SCRIPTS
        init.mac
        geometry.gdml
        )

foreach(_script ${APPNAME_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()

add_executable(APPNAME main.cc ${sources} ${headers})
target_link_libraries(APPNAME ${Geant4_LIBRARIES})

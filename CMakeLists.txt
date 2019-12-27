cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(MultiImageFilter
  VERSION 0.0.1
  DESCRIPTION "Multiple Image Filter"
  LANGUAGES C CXX)
set(TARGET_NAME "MultiImageFilter")
set(DEFAULT_BUILD_TYPE "Release")

#stNDARD STUFF
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS_COMMON}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt5Core_DIR /home/gmatczak/qtbase/lib/cmake/Qt5Core  )
set(Qt5Network_DIR  /home/gmatczak/Qt/5.12.5/gcc_64/lib/cmake/Qt5Core/)
set(OpenCV_DIR /home/gmatczak/opencv/build/inclulde )
set(CMAKE_PREFIX_PATH /home/gmatczak/opencv/build  /home/gmatczak/Qt/5.12.5/gcc_64/lib/cmake/Qt5Core/)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(OpenCV REQUIRED)
#include fix for OpenCV
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

set(SRC
    src/main.cc
    src/filters/basefilter.h
    src/filters/basefilter.cc
    src/filters/gaussianblur.cc
    src/filters/gaussianblur.h
    src/filters/color.cc
    src/filters/color.h
    src/multiimagefilter.cc
    src/filter.h
    src/filters/resize.cc
    src/filters/resize.h
    src/filters/medianblur.cc
    src/filters/medianblur.h
    src/filters/morphologyoperation.cc
    src/filters/morphologyoperation.h
    src/filters/none.cc
    src/filters/none.h
    src/filters/threshold.cc
    src/filters/threshold.h
    src/filters/bilateralfilter.cc
    src/filters/bilateralfilter.h
    src/filters/blur.cc
    src/filters/blur.h
    ../../IncludeSpdlog/spdlog.cc
)

set(HEADERS
    src/multiimagefilter.h
    ../../IncludeSpdlog/spdlog.h
)

add_executable(${TARGET_NAME}
    ${SRC}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core ${OpenCV_LIBS} Threads::Threads )

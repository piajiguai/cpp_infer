project(ppocr CXX C)
cmake_minimum_required(VERSION 3.14)

option(WITH_MKL        "Compile demo with MKL/OpenBlas support, default use MKL."       ON)
option(WITH_GPU        "Compile demo with GPU/CPU, default use CPU."                    OFF)
option(WITH_STATIC_LIB "Compile demo with static/shared library, default use static."   OFF)
option(WITH_TENSORRT "Compile demo with TensorRT."   OFF)

SET(PADDLE_LIB "" CACHE PATH "Location of libraries")
SET(OPENCV_DIR "" CACHE PATH "Location of libraries")
SET(CUDA_LIB "" CACHE PATH "Location of libraries")
SET(CUDNN_LIB "" CACHE PATH "Location of libraries")
SET(TENSORRT_DIR "" CACHE PATH "Compile demo with TensorRT")

set(DEMO_NAME "ppocr")


macro(safe_set_static_flag)
    foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
endmacro()

ADD_DEFINITIONS(-DUSE_MKL)


set(OpenCV_DIR /home/zjl/opt/opencv/opencv-4.5.4/build)
find_package( OpenCV  REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories("${PADDLE_LIB}/paddle/include")
link_directories("${PADDLE_LIB}/paddle/lib")


set(FLAG_OPENMP "-fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 ${FLAG_OPENMP} -std=c++11")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
message("cmake cxx flags" ${CMAKE_CXX_FLAGS})


include_directories("${PADDLE_LIB}/third_party/install/protobuf/include")
include_directories("${PADDLE_LIB}/third_party/install/glog/include")
include_directories("${PADDLE_LIB}/third_party/install/gflags/include")
include_directories("${PADDLE_LIB}/third_party/install/xxhash/include")
include_directories("${PADDLE_LIB}/third_party/install/zlib/include")
include_directories("${PADDLE_LIB}/third_party/install/onnxruntime/include")
include_directories("${PADDLE_LIB}/third_party/install/paddle2onnx/include")
include_directories("${PADDLE_LIB}/third_party/boost")
include_directories("${PADDLE_LIB}/third_party/eigen3")
include_directories("${CMAKE_SOURCE_DIR}/")

link_directories("${PADDLE_LIB}/third_party/install/zlib/lib")
link_directories("${PADDLE_LIB}/third_party/install/protobuf/lib")
link_directories("${PADDLE_LIB}/third_party/install/glog/lib")
link_directories("${PADDLE_LIB}/third_party/install/gflags/lib")
link_directories("${PADDLE_LIB}/third_party/install/xxhash/lib")
link_directories("${PADDLE_LIB}/third_party/install/onnxruntime/lib")
link_directories("${PADDLE_LIB}/third_party/install/paddle2onnx/lib")
link_directories("${PADDLE_LIB}/paddle/lib")


include_directories("${PADDLE_LIB}/third_party/install/mklml/include")
set(MATH_LIB ${PADDLE_LIB}/third_party/install/mklml/lib/libmklml_intel${CMAKE_SHARED_LIBRARY_SUFFIX}
        ${PADDLE_LIB}/third_party/install/mklml/lib/libiomp5${CMAKE_SHARED_LIBRARY_SUFFIX})
execute_process(COMMAND cp -r ${PADDLE_LIB}/third_party/install/mklml/lib/libmklml_intel${CMAKE_SHARED_LIBRARY_SUFFIX} /usr/lib)
set(MKLDNN_PATH "${PADDLE_LIB}/third_party/install/mkldnn")
include_directories("${MKLDNN_PATH}/include")
set(MKLDNN_LIB ${MKLDNN_PATH}/lib/libmkldnn.so.0)


# Note: libpaddle_inference_api.so/a must put before libpaddle_inference.so/a
set(DEPS ${PADDLE_LIB}/paddle/lib/libpaddle_inference${CMAKE_SHARED_LIBRARY_SUFFIX})

set(DEPS ${DEPS}
    ${MATH_LIB} ${MKLDNN_LIB}
    glog gflags protobuf z xxhash
    )

set(EXTERNAL_LIB "-ldl -lrt -lgomp -lz -lm -lpthread")
set(DEPS ${DEPS} ${EXTERNAL_LIB})
set(DEPS ${DEPS} ${OpenCV_LIBS} )
# MESSAGE( STATUS "The DEPS is : ${PADDLE_LIB}/paddle/lib/paddle_inference${CMAKE_SHARED_LIBRARY_SUFFIX}.")

include(FetchContent)
include(external-cmake/auto-log.cmake)
include_directories(${FETCHCONTENT_BASE_DIR}/extern_autolog-src)

AUX_SOURCE_DIRECTORY(./src SRCS)
add_executable(${DEMO_NAME} ${SRCS})
target_link_libraries(${DEMO_NAME} ${DEPS} )



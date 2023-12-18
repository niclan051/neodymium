cmake_minimum_required(VERSION 3.27)
project(neodymium)

include_directories(D:/_1_Miha/boost_1_83_0)

set(CMAKE_CXX_STANDARD 23)


file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")
file(GLOB_RECURSE BOOST CONFIGURE_DEPENDS "boost_*/*.h" "boost_*/*.cpp")

add_executable(neodymium ${SOURCE_FILES} ${BOOST})

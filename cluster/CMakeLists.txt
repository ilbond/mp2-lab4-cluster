cmake_minimum_required(VERSION 2.8)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

include_directories(cluster gtest)

# BUILD
add_subdirectory(cluster)
add_subdirectory(ClusterTest)
add_subdirectory(gtest)

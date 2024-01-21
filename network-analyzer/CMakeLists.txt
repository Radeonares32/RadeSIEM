cmake_minimum_required(VERSION 3.12)
project(Network-Analyzer)

# Set C++20
set(CMAKE_CXX_STANDARD 20)
# popen()/pclose() are not C++ standards
set(CMAKE_CXX_EXTENSIONS ON)

add_executable("${PROJECT_NAME}" 
  ./network/network.cpp
  ./service/network.service.cpp
  ./main.cpp
  )


find_package(protobuf CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC protobuf::libprotobuf)

if(NOT TARGET PcapPlusPlus::Pcap++)
  message("Compiling Tutorial out of project")
  find_package(PcapPlusPlus REQUIRED)
  set_target_properties("${PROJECT_NAME}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
else()
  set_target_properties("${PROJECT_NAME}" PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PCAPPP_BINARY_TUTORIAL_DIR}")
endif()

target_link_libraries("${PROJECT_NAME}" PUBLIC PcapPlusPlus::Pcap++)

set(PROJ_NAME zmq_environmentrequester)
project(${PROJ_NAME})

add_library(${PROJ_NAME} STATIC "")
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_11)
set_target_properties(${PROJ_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_sources(${PROJ_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/environmentrequester.h
        ${CMAKE_CURRENT_SOURCE_DIR}/environmentrequester.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/heartbeater.cpp
        )
target_link_libraries(${PROJ_NAME} PUBLIC re_common_proto_control)
target_link_libraries(${PROJ_NAME} PUBLIC zmq_protorequester)
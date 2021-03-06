set(PROJ_NAME re_common_proto_control)
project(${PROJ_NAME})

find_package(Protobuf REQUIRED)
# Generate .proto file
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/controlmessage.proto)

add_library(${PROJ_NAME} STATIC "")
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_11)
target_compile_definitions(${PROJ_NAME} PUBLIC PROTOBUF_USE_DLLS)
set_target_properties(${PROJ_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_sources(${PROJ_NAME} PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/helper.cpp
		${PROTO_HDRS}
		${PROTO_SRCS}
		)
target_include_directories(${PROJ_NAME} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
target_include_directories(${PROJ_NAME} PUBLIC ${RE_COMMON_SOURCE_DIR})
target_include_directories(${PROJ_NAME} PUBLIC ${RE_COMMON_BINARY_DIR})
target_link_libraries(${PROJ_NAME} PUBLIC ${PROTOBUF_LIBRARIES})
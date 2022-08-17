aux_source_directory(${PROJECT_SOURCE_DIR}/example/service SERVICE_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/example/client CLIENT_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/example/protos PROTO_SRC)

add_library(message ${PROTO_SRC})
target_link_libraries(message protobuf)

# 服务提供者
add_executable(server ${SERVICE_SRC})
target_link_libraries(server mpzrpc message zookeeper_mt)

# # 服务调用者
add_executable(client ${CLIENT_SRC})
target_link_libraries(client mpzrpc message zookeeper_mt)


add_executable(sandbox src/main.cpp)
target_link_libraries(sandbox PUBLIC turtle)

target_include_directories(
    sandbox
    PUBLIC
    "${PROJECT_SOURCE_DIR}/sandbox/src"
    "${PROJECT_SOURCE_DIR}/turtle/src"
)

add_custom_command(
    TARGET sandbox PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:sandbox>/resources
)
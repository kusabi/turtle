add_executable(sandbox src/main.cpp)
target_link_libraries(sandbox PUBLIC turtle)

target_include_directories(
    sandbox
    PUBLIC
    "${PROJECT_BINARY_DIR}/sandbox/include"
    "${PROJECT_SOURCE_DIR}/turtle/include"
)

add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:sandbox>/resources)
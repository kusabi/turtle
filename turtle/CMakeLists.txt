# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw ${CMAKE_CURRENT_BINARY_DIR}/vendor/glfw EXCLUDE_FROM_ALL)

# GLAD
set(GLAD_INSTALL ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad ${CMAKE_CURRENT_BINARY_DIR}/vendor/glad EXCLUDE_FROM_ALL)

add_library(
    turtle
    src/Program.cpp
    src/Renderer.cpp
    src/Window.cpp
    src/Vector2.cpp
    src/Vector3.cpp
    src/Math.cpp
)

target_link_libraries(turtle glad glfw)

target_include_directories(
    turtle
    PUBLIC
    ${PROJECT_SOURCE_DIR}/turtle/vendor/glad/include
)
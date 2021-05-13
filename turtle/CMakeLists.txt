include(FetchContent)

# GLFW
FetchContent_Declare(extern_glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG 3.3.4)
FetchContent_GetProperties(extern_glfw)
if(NOT extern_glfw_POPULATED)
    FetchContent_Populate(extern_glfw)
    set(GLAD_INSTALL ON)
    add_subdirectory(${extern_glfw_SOURCE_DIR} ${extern_glfw_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# GLAD
FetchContent_Declare(extern_glad GIT_REPOSITORY https://github.com/Dav1dde/glad.git GIT_TAG v0.1.27)
FetchContent_GetProperties(extern_glad)
if(NOT extern_glad_POPULATED)
    FetchContent_Populate(extern_glad)
    set(GLAD_INSTALL ON)
    add_subdirectory(${extern_glad_SOURCE_DIR} ${extern_glad_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# GLFW vendor build
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

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
    ${extern_glad_SOURCE_DIR}/include
)

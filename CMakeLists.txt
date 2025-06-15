cmake_minimum_required(VERSION 4.0)

project(remove_node_modules VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(SOURCES remove_node_modules.cpp)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
)
FetchContent_MakeAvailable(Catch2)

# For library
add_library(remove_node_modules_lib ${SOURCES})
target_include_directories(remove_node_modules_lib 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# For executable/CLI
add_executable(remove_node_modules main.cpp)
target_link_libraries(remove_node_modules 
  PRIVATE 
    remove_node_modules_lib
)
target_compile_options(remove_node_modules 
  PRIVATE 
    -Wall -Wextra -Wpedantic
)

# For testing
enable_testing()
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests 
  PRIVATE 
    remove_node_modules_lib
    Catch2::Catch2WithMain
)
target_compile_options(tests 
  PRIVATE 
    -Wall -Wextra -Wpedantic
)
add_test(NAME tests COMMAND tests --colour-mode ansi --success)

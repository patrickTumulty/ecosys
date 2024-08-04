cmake_minimum_required(VERSION 3.22)

project(ecosys)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

set(
    ECOSYS_SOURCES
    src/component.cpp
    src/entity.cpp
    src/entity_manager.cpp
    src/systems_runner.cpp
)

add_library(${PROJECT_NAME} STATIC ${ECOSYS_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(
    ECOSYS_TEST_SOURCES
    tests/entity_manager_tests.cpp
    tests/entity_tests.cpp
)

add_executable(${PROJECT_NAME}_test ${ECOSYS_TEST_SOURCES})

target_link_libraries(${PROJECT_NAME}_test GTest::gtest_main ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC tests)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_test)


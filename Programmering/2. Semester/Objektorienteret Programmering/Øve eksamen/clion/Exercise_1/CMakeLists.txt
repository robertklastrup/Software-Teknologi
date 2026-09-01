add_executable(Exercise_1 src/program.cpp
        include/int_array.h
        src/int_array.cpp)

target_include_directories(Exercise_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
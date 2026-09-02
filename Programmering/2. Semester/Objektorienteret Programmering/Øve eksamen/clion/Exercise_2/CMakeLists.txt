add_executable(Exercise_2
        src/program.cpp
        src/cat.cpp
        src/cat_array.cpp
)

target_include_directories(Exercise_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
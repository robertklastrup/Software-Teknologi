add_executable(Exercise_3
        src/program.cpp
        src/cat.cpp
        src/link.cpp
        src/linked_list.cpp
)

target_include_directories(Exercise_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
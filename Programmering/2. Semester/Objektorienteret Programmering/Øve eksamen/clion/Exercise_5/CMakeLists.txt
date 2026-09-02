add_executable(Exercise_5
        src/program.cpp
        src/cat.cpp
        src/link.cpp
        src/linked_list.cpp
)

target_include_directories(Exercise_5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
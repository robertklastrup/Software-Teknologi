add_executable(Opgave_3 src/opgave_3.cpp
        src/Tests.cpp
        src/Combiner.cpp
        src/Point.cpp
        src/Rotation.cpp
        src/Translation.cpp)

target_include_directories(Opgave_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(Opgave_2 src/opgave_2.cpp src/Tests.cpp src/RandomHelper.cpp src/TimeSeries.cpp src/vector.cpp)

target_include_directories(Opgave_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
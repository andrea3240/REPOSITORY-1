cmake_minimum_required(VERSION 3.20)
project(esercitazione5) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_test_sorts timecounter.cpp main5.cpp)
add_executable(measure_sort measure_sort.cpp timecounter.cpp)
add_executable(main5 main5.cpp timecounter.cpp)

add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quick_sort COMMAND test_quicksort)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME merge_sort COMMAND test_mergesort)


enable_testing()
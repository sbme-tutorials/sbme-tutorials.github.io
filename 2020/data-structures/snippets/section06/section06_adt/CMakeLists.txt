cmake_minimum_required(VERSION 2.8)
project(section06_adt)
add_executable(stack_array stack_array.cpp StackArray.hpp)
add_executable(stack_ll stack_ll.cpp  StackSLL.hpp)
add_executable(queue_array queue_array.cpp QueueArray.hpp)
add_executable(queue_dll queue_dll.cpp QueueDLL.hpp)


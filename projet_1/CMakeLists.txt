cmake_minimum_required(VERSION 3.16)
project(projet_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_1 source/philosopher_problem.c source/producer_consumer.c source/writer_reader.c source/my_semaphore.c source/test_test_set_lib.h source/philosopher_problem_mod.c source/writer_reader_mod.c source/producer_consumer_mod.c source/my_semaphore.h source/test_test_set_performance.c source/posix.c source/test_set_lib.h source/test_set_performance.c)

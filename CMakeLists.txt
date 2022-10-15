cmake_minimum_required(VERSION 3.6)

project(Main_automata)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        FSM/include
        FSM/include/math)

add_executable(run
        main.cpp
        FSM/src/NFSM.cpp
        FSM/src/DFSM.cpp
        FSM/src/MDFSM.cpp
        FSM/src/math_func/utility.cpp
        FSM/src/RegularFSM.cpp
        FSM/src/State.cpp
        )

add_subdirectory(tests)

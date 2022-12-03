cmake_minimum_required(VERSION 3.6)
project(gtest)

enable_testing()

include_directories(
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        basic_tests/my_tests
        ../FSM/include
        ../FSM/include/math
        )

add_subdirectory(
        lib/googletest
        )

set(TEST_SOURCE
        basic_tests/word_rec_tests/NFSM_tests/AnyNFSM_tests/nfsm1_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/AnyNFSM_tests/nfsm2_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/AnyNFSM_tests/nfsm3_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/AnyNFSM_tests/nfsm4_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/AnyNFSM_tests/nfsm5_test.cpp

        basic_tests/word_rec_tests/NFSM_tests/NoEpsNFSM_test/NoEpsnfsm1_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/NoEpsNFSM_test/NoEpsnfsm2_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/NoEpsNFSM_test/NoEpsnfsm3_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/NoEpsNFSM_test/NoEpsnfsm4_test.cpp
        basic_tests/word_rec_tests/NFSM_tests/NoEpsNFSM_test/NoEpsnfsm5_test.cpp

        basic_tests/converts_test/NFSM_to_DFSM_convert_tests/dfsm1_convert_test.cpp
        basic_tests/converts_test/NFSM_to_DFSM_convert_tests/dfsm2_convert_test.cpp
        basic_tests/converts_test/NFSM_to_DFSM_convert_tests/dfsm3_convert_test.cpp
        basic_tests/converts_test/NFSM_to_DFSM_convert_tests/dfsm4_convert_test.cpp
        basic_tests/converts_test/NFSM_to_DFSM_convert_tests/dfsm5_convert_test.cpp

        basic_tests/converts_test/DFSM_to_MDFSM_convert_tests/mdfsm1_convert_test.cpp
        basic_tests/converts_test/DFSM_to_MDFSM_convert_tests/mdfsm2_convert_test.cpp
        basic_tests/converts_test/DFSM_to_MDFSM_convert_tests/mdfsm3_convert_test.cpp
        basic_tests/converts_test/DFSM_to_MDFSM_convert_tests/mdfsm4_convert_test.cpp
        basic_tests/converts_test/DFSM_to_MDFSM_convert_tests/mdfsm5_convert_test.cpp

        basic_tests/word_rec_tests/DFSM_tests/DFSM_test1.cpp
        basic_tests/word_rec_tests/DFSM_tests/DFSM_test2.cpp
        basic_tests/word_rec_tests/DFSM_tests/DFSM_test3.cpp
        basic_tests/word_rec_tests/DFSM_tests/DFSM_test4.cpp
        basic_tests/word_rec_tests/DFSM_tests/DFSM_test5.cpp

        basic_tests/word_rec_tests/MDFSM_tests/MDFSM_test1.cpp
        basic_tests/word_rec_tests/MDFSM_tests/MDFSM_test2.cpp
        basic_tests/word_rec_tests/MDFSM_tests/MDFSM_test3.cpp
        basic_tests/word_rec_tests/MDFSM_tests/MDFSM_test4.cpp
        basic_tests/word_rec_tests/MDFSM_tests/MDFSM_test5.cpp
        )

add_executable(BasicFsmTests
        ../FSM/src/NFSM.cpp
        ../FSM/src/DFSM.cpp
        ../FSM/src/MDFSM.cpp
        ../FSM/src/RegularFSM.cpp
        ../FSM/src/State.cpp
        ../FSM/src/math_func/utility.cpp
        ${TEST_SOURCE}
        )

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(BasicFsmTests gtest gtest_main)
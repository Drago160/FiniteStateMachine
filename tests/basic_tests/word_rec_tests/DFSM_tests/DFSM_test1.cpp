#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"

class TestDFSM1 : public ::testing::Test {
 protected:
  void SetUp() {
    dfsm_ = new DFSM("../SM_examples/DFSM_examples/dfsm1.txt");
  }
  void TearDown() {
    delete dfsm_;
  }
  DFSM* dfsm_;
};
TEST_F(TestDFSM1, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_1.word) , Test1_1.answer);
}
TEST_F(TestDFSM1, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_2.word) , Test1_2.answer);
}
TEST_F(TestDFSM1, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_3.word) , Test1_3.answer);
}
TEST_F(TestDFSM1, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_4.word) , Test1_4.answer);
}
TEST_F(TestDFSM1, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_5.word) , Test1_5.answer);
}
TEST_F(TestDFSM1, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_6.word) , Test1_6.answer);
}
TEST_F(TestDFSM1, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_7.word) , Test1_7.answer);
}
TEST_F(TestDFSM1, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_8.word) , Test1_8.answer);
}
TEST_F(TestDFSM1, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_9.word) , Test1_9.answer);
}
TEST_F(TestDFSM1, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_10.word) , Test1_10.answer);
}

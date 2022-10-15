#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"

class TestDFSM2 : public ::testing::Test {
 protected:
  void SetUp() {
    dfsm_ = new DFSM("../SM_examples/DFSM_examples/dfsm2.txt");
  }
  void TearDown() {
    delete dfsm_;
  }
  DFSM* dfsm_;
};
TEST_F(TestDFSM2, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_1.word) , Test2_1.answer);
}
TEST_F(TestDFSM2, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_2.word) , Test2_2.answer);
}
TEST_F(TestDFSM2, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_3.word) , Test2_3.answer);
}
TEST_F(TestDFSM2, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_4.word) , Test2_4.answer);
}
TEST_F(TestDFSM2, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_5.word) , Test2_5.answer);
}
TEST_F(TestDFSM2, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_6.word) , Test2_6.answer);
}
TEST_F(TestDFSM2, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_7.word) , Test2_7.answer);
}
TEST_F(TestDFSM2, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_8.word) , Test2_8.answer);
}
TEST_F(TestDFSM2, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_9.word) , Test2_9.answer);
}
TEST_F(TestDFSM2, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test2_10.word) , Test2_10.answer);
}

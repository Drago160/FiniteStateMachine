#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"

class TestMDFSM5 : public ::testing::Test {
 protected:
  void SetUp() {
    MDFSM_ = new MDFSM("../SM_examples/MDFSM_examples/mdfsm5.txt");
  }
  void TearDown() {
    delete MDFSM_;
  }
  MDFSM* MDFSM_;
};
TEST_F(TestMDFSM5, test1) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_1.word) , Test5_1.answer);
}
TEST_F(TestMDFSM5, test2) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_2.word) , Test5_2.answer);
}
TEST_F(TestMDFSM5, test3) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_3.word) , Test5_3.answer);
}
TEST_F(TestMDFSM5, test4) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_4.word) , Test5_4.answer);
}
TEST_F(TestMDFSM5, test5) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_5.word) , Test5_5.answer);
}
TEST_F(TestMDFSM5, test6) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_6.word) , Test5_6.answer);
}
TEST_F(TestMDFSM5, test7) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_7.word) , Test5_7.answer);
}
TEST_F(TestMDFSM5, test8) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_8.word) , Test5_8.answer);
}
TEST_F(TestMDFSM5, test9) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_9.word) , Test5_9.answer);
}
TEST_F(TestMDFSM5, test10) {
  ASSERT_EQ(MDFSM_->RecognizeWord(Test5_10.word) , Test5_10.answer);
}

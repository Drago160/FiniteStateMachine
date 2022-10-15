#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"

class TestMDFSM1 : public ::testing::Test {
 protected:
  void SetUp() {
    mdfsm_ = new MDFSM("../SM_examples/MDFSM_examples/mdfsm1.txt");
  }
  void TearDown() {
    delete mdfsm_;
  }
  MDFSM* mdfsm_;
};
TEST_F(TestMDFSM1, test1) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_1.word) , Test1_1.answer);
}
TEST_F(TestMDFSM1, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_2.word) , Test1_2.answer);
}
TEST_F(TestMDFSM1, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_3.word) , Test1_3.answer);
}
TEST_F(TestMDFSM1, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_4.word) , Test1_4.answer);
}
TEST_F(TestMDFSM1, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_5.word) , Test1_5.answer);
}
TEST_F(TestMDFSM1, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_6.word) , Test1_6.answer);
}
TEST_F(TestMDFSM1, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_7.word) , Test1_7.answer);
}
TEST_F(TestMDFSM1, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_8.word) , Test1_8.answer);
}
TEST_F(TestMDFSM1, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_9.word) , Test1_9.answer);
}
TEST_F(TestMDFSM1, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_10.word) , Test1_10.answer);
}

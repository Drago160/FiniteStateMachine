#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"
class TestMDFSM5_convert : public ::testing::Test {
 protected:
  void SetUp() {
    DFSM dfsm("../SM_examples/DFSM_examples/dfsm5.txt");
    mdfsm_ = new MDFSM(dfsm);
  }
  void TearDown() {
    delete mdfsm_;
  }

  DFSM* mdfsm_;
};
TEST_F(TestMDFSM5_convert, test_size5) {
  ASSERT_EQ(mdfsm_->getSize(), size5);
}
TEST_F(TestMDFSM5_convert, test1) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_1.word) , Test5_1.answer);
}
TEST_F(TestMDFSM5_convert, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_2.word) , Test5_2.answer);
}
TEST_F(TestMDFSM5_convert, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_3.word) , Test5_3.answer);
}
TEST_F(TestMDFSM5_convert, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_4.word) , Test5_4.answer);
}
TEST_F(TestMDFSM5_convert, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_5.word) , Test5_5.answer);
}
TEST_F(TestMDFSM5_convert, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_6.word) , Test5_6.answer);
}
TEST_F(TestMDFSM5_convert, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_7.word) , Test5_7.answer);
}
TEST_F(TestMDFSM5_convert, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_8.word) , Test5_8.answer);
}
TEST_F(TestMDFSM5_convert, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_9.word) , Test5_9.answer);
}
TEST_F(TestMDFSM5_convert, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test5_10.word) , Test5_10.answer);
}

#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"
class TestMDFSM4_convert : public ::testing::Test {
 protected:
  void SetUp() {
    DFSM dfsm("../SM_examples/DFSM_examples/dfsm4.txt");
    mdfsm_ = new MDFSM(dfsm);
  }
  void TearDown() {
    delete mdfsm_;
  }

  DFSM* mdfsm_;
};
TEST_F(TestMDFSM4_convert, test_size4) {
  ASSERT_EQ(mdfsm_->getSize(), size4);
}
TEST_F(TestMDFSM4_convert, test1) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_1.word) , Test4_1.answer);
}
TEST_F(TestMDFSM4_convert, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_2.word) , Test4_2.answer);
}
TEST_F(TestMDFSM4_convert, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_3.word) , Test4_3.answer);
}
TEST_F(TestMDFSM4_convert, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_4.word) , Test4_4.answer);
}
TEST_F(TestMDFSM4_convert, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_5.word) , Test4_5.answer);
}
TEST_F(TestMDFSM4_convert, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_6.word) , Test4_6.answer);
}
TEST_F(TestMDFSM4_convert, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_7.word) , Test4_7.answer);
}
TEST_F(TestMDFSM4_convert, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_8.word) , Test4_8.answer);
}
TEST_F(TestMDFSM4_convert, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_9.word) , Test4_9.answer);
}
TEST_F(TestMDFSM4_convert, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test4_10.word) , Test4_10.answer);
}

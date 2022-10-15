#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"
class TestMDFSM3_convert : public ::testing::Test {
 protected:
  void SetUp() {
    DFSM dfsm("../SM_examples/DFSM_examples/dfsm3.txt");
    mdfsm_ = new MDFSM(dfsm);
  }
  void TearDown() {
    delete mdfsm_;
  }

  DFSM* mdfsm_;
};
TEST_F(TestMDFSM3_convert, test_size3) {
  ASSERT_EQ(mdfsm_->getSize(), size3);
}
TEST_F(TestMDFSM3_convert, test1) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_1.word) , Test3_1.answer);
}
TEST_F(TestMDFSM3_convert, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_2.word) , Test3_2.answer);
}
TEST_F(TestMDFSM3_convert, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_3.word) , Test3_3.answer);
}
TEST_F(TestMDFSM3_convert, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_4.word) , Test3_4.answer);
}
TEST_F(TestMDFSM3_convert, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_5.word) , Test3_5.answer);
}
TEST_F(TestMDFSM3_convert, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_6.word) , Test3_6.answer);
}
TEST_F(TestMDFSM3_convert, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_7.word) , Test3_7.answer);
}
TEST_F(TestMDFSM3_convert, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_8.word) , Test3_8.answer);
}
TEST_F(TestMDFSM3_convert, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_9.word) , Test3_9.answer);
}
TEST_F(TestMDFSM3_convert, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test3_10.word) , Test3_10.answer);
}

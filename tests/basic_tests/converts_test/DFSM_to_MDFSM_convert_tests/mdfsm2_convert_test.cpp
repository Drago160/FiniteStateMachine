#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"
class TestMDFSM2_convert : public ::testing::Test {
 protected:
  void SetUp() {
    DFSM dfsm("../SM_examples/DFSM_examples/dfsm2.txt");
    mdfsm_ = new MDFSM(dfsm);
  }
  void TearDown() {
    delete mdfsm_;
  }

  DFSM* mdfsm_;
};
TEST_F(TestMDFSM2_convert, test_size2) {
  ASSERT_EQ(mdfsm_->getSize(), size2);
}
TEST_F(TestMDFSM2_convert, test1) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_1.word) , Test2_1.answer);
}
TEST_F(TestMDFSM2_convert, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_2.word) , Test2_2.answer);
}
TEST_F(TestMDFSM2_convert, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_3.word) , Test2_3.answer);
}
TEST_F(TestMDFSM2_convert, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_4.word) , Test2_4.answer);
}
TEST_F(TestMDFSM2_convert, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_5.word) , Test2_5.answer);
}
TEST_F(TestMDFSM2_convert, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_6.word) , Test2_6.answer);
}
TEST_F(TestMDFSM2_convert, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_7.word) , Test2_7.answer);
}
TEST_F(TestMDFSM2_convert, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_8.word) , Test2_8.answer);
}
TEST_F(TestMDFSM2_convert, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_9.word) , Test2_9.answer);
}
TEST_F(TestMDFSM2_convert, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test2_10.word) , Test2_10.answer);
}


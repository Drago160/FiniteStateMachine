#include "gtest/gtest.h"
#include "MDFSM.h"
#include "test_words.h"
class TestMDFSM1_convert : public ::testing::Test {
 protected:
  void SetUp() {
    DFSM dfsm("../SM_examples/DFSM_examples/dfsm1.txt");
    mdfsm_ = new MDFSM(dfsm);
  }
  void TearDown() {
    delete mdfsm_;
  }
  DFSM* mdfsm_;
};
TEST_F(TestMDFSM1_convert, test_size1) {
  std::cout << mdfsm_->getSize();
ASSERT_EQ(mdfsm_->getSize(), size1);
}
TEST_F(TestMDFSM1_convert, test1) {
ASSERT_EQ(mdfsm_->RecognizeWord(Test1_1.word) , Test1_1.answer);
}
TEST_F(TestMDFSM1_convert, test2) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_2.word) , Test1_2.answer);
}
TEST_F(TestMDFSM1_convert, test3) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_3.word) , Test1_3.answer);
}
TEST_F(TestMDFSM1_convert, test4) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_4.word) , Test1_4.answer);
}
TEST_F(TestMDFSM1_convert, test5) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_5.word) , Test1_5.answer);
}
TEST_F(TestMDFSM1_convert, test6) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_6.word) , Test1_6.answer);
}
TEST_F(TestMDFSM1_convert, test7) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_7.word) , Test1_7.answer);
}
TEST_F(TestMDFSM1_convert, test8) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_8.word) , Test1_8.answer);
}
TEST_F(TestMDFSM1_convert, test9) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_9.word) , Test1_9.answer);
}
TEST_F(TestMDFSM1_convert, test10) {
  ASSERT_EQ(mdfsm_->RecognizeWord(Test1_10.word) , Test1_10.answer);
}

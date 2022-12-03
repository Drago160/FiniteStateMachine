#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"

class TestDFSM3 : public ::testing::Test {
 protected:
  void SetUp() {
    dfsm_ = new DFSM("../SM_examples/DFSM_examples/dfsm3.txt");
  }
  void TearDown() {
    delete dfsm_;
  }
  DFSM* dfsm_;
};
TEST_F(TestDFSM3, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_1.word) , Test3_1.answer);
}
TEST_F(TestDFSM3, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_2.word) , Test3_2.answer);
}
TEST_F(TestDFSM3, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_3.word) , Test3_3.answer);
}
TEST_F(TestDFSM3, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_4.word) , Test3_4.answer);
}
TEST_F(TestDFSM3, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_5.word) , Test3_5.answer);
}
TEST_F(TestDFSM3, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_6.word) , Test3_6.answer);
}
TEST_F(TestDFSM3, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_7.word) , Test3_7.answer);
}
TEST_F(TestDFSM3, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_8.word) , Test3_8.answer);
}
TEST_F(TestDFSM3, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_9.word) , Test3_9.answer);
}
TEST_F(TestDFSM3, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_10.word) , Test3_10.answer);
}

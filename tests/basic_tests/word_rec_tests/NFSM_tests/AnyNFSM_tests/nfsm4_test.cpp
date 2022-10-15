#include "gtest/gtest.h"
#include "NFSM.h"
#include "test_words.h"

class TestNoEpsNFSM4 : public ::testing::Test {
 protected:
  void SetUp() {
    nfsm_ = new NFSM("../SM_examples/NFSM_examples/nfsm4.txt");
    nfsm_->FilchEps();
  }
  void TearDown() {
    delete nfsm_;
  }


  NFSM* nfsm_;
};
TEST_F(TestNoEpsNFSM4, test1) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_1.word) , Test4_1.answer);
}
TEST_F(TestNoEpsNFSM4, test2) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_2.word) , Test4_2.answer);
}
TEST_F(TestNoEpsNFSM4, test3) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_3.word) , Test4_3.answer);
}
TEST_F(TestNoEpsNFSM4, test4) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_4.word) , Test4_4.answer);
}
TEST_F(TestNoEpsNFSM4, test5) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_5.word) , Test4_5.answer);
}
TEST_F(TestNoEpsNFSM4, test6) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_6.word) , Test4_6.answer);
}
TEST_F(TestNoEpsNFSM4, test7) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_7.word) , Test4_7.answer);
}
TEST_F(TestNoEpsNFSM4, test8) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_8.word) , Test4_8.answer);
}
TEST_F(TestNoEpsNFSM4, test9) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_9.word) , Test4_9.answer);
}
TEST_F(TestNoEpsNFSM4, test10) {
  ASSERT_EQ(nfsm_->RecognizeWord(Test4_10.word) , Test4_10.answer);
}
#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"
class TestDFSM4_convert : public ::testing::Test {
 protected:
  void SetUp() {
    NFSM nfsm("../SM_examples/NFSM_examples/nfsm4.txt");
    nfsm.FilchEps();
    dfsm_ = new DFSM(nfsm);
    compl_dfsm = new DFSM(nfsm);
    compl_dfsm->Complement();
  }
  void TearDown() {
    delete dfsm_;
    delete compl_dfsm;
  }
  DFSM* compl_dfsm;
  DFSM* dfsm_;
};


TEST_F(TestDFSM4_convert, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_1.word) , Test4_1.answer);
}
TEST_F(TestDFSM4_convert, test1_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_1.word) , !Test4_1.answer);
}

TEST_F(TestDFSM4_convert, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_2.word) , Test4_2.answer);
}

TEST_F(TestDFSM4_convert, test2_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_2.word) , !Test4_2.answer);
}

TEST_F(TestDFSM4_convert, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_3.word) , Test4_3.answer);
}
TEST_F(TestDFSM4_convert, Test4_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_3.word) , !Test4_3.answer);
}
TEST_F(TestDFSM4_convert, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_4.word) , Test4_4.answer);
}
TEST_F(TestDFSM4_convert, test4_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_4.word) , !Test4_4.answer);
}
TEST_F(TestDFSM4_convert, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_5.word) , Test4_5.answer);
}
TEST_F(TestDFSM4_convert, test5_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_5.word) , !Test4_5.answer);
}
TEST_F(TestDFSM4_convert, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_6.word) , Test4_6.answer);
}
TEST_F(TestDFSM4_convert, test6_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_6.word) , !Test4_6.answer);
}
TEST_F(TestDFSM4_convert, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_7.word) , Test4_7.answer);
}
TEST_F(TestDFSM4_convert, test7_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_7.word) , !Test4_7.answer);
}
TEST_F(TestDFSM4_convert, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_8.word) , Test4_8.answer);
}
TEST_F(TestDFSM4_convert, test8_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_8.word) , !Test4_8.answer);
}
TEST_F(TestDFSM4_convert, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_9.word) , Test4_9.answer);
}
TEST_F(TestDFSM4_convert, test9_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_9.word) , !Test4_9.answer);
}
TEST_F(TestDFSM4_convert, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test4_10.word) , Test4_10.answer);
}
TEST_F(TestDFSM4_convert, test10_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test4_10.word) , !Test4_10.answer);
}
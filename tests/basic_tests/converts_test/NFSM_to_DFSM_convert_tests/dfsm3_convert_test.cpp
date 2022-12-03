#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"
class TestDFSM3_convert : public ::testing::Test {
 protected:
  void SetUp() {
    NFSM nfsm("../SM_examples/NFSM_examples/nfsm3.txt");
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


TEST_F(TestDFSM3_convert, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_1.word) , Test3_1.answer);
}
TEST_F(TestDFSM3_convert, test1_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_1.word) , !Test3_1.answer);
}

TEST_F(TestDFSM3_convert, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_2.word) , Test3_2.answer);
}

TEST_F(TestDFSM3_convert, test2_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_2.word) , !Test3_2.answer);
}

TEST_F(TestDFSM3_convert, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_3.word) , Test3_3.answer);
}
TEST_F(TestDFSM3_convert, test3_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_3.word) , !Test3_3.answer);
}
TEST_F(TestDFSM3_convert, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_4.word) , Test3_4.answer);
}
TEST_F(TestDFSM3_convert, test4_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_4.word) , !Test3_4.answer);
}
TEST_F(TestDFSM3_convert, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_5.word) , Test3_5.answer);
}
TEST_F(TestDFSM3_convert, test5_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_5.word) , !Test3_5.answer);
}
TEST_F(TestDFSM3_convert, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_6.word) , Test3_6.answer);
}
TEST_F(TestDFSM3_convert, test6_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_6.word) , !Test3_6.answer);
}
TEST_F(TestDFSM3_convert, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_7.word) , Test3_7.answer);
}
TEST_F(TestDFSM3_convert, test7_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_7.word) , !Test3_7.answer);
}
TEST_F(TestDFSM3_convert, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_8.word) , Test3_8.answer);
}
TEST_F(TestDFSM3_convert, test8_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_8.word) , !Test3_8.answer);
}
TEST_F(TestDFSM3_convert, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_9.word) , Test3_9.answer);
}
TEST_F(TestDFSM3_convert, test9_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_9.word) , !Test3_9.answer);
}
TEST_F(TestDFSM3_convert, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test3_10.word) , Test3_10.answer);
}
TEST_F(TestDFSM3_convert, test10_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test3_10.word) , !Test3_10.answer);
}

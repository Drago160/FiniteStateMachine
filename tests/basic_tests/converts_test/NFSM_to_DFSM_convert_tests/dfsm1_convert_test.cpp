#include "gtest/gtest.h"
#include "DFSM.h"
#include "test_words.h"
class TestDFSM1_convert : public ::testing::Test {
 protected:
  void SetUp() {
    NFSM nfsm("../SM_examples/NFSM_examples/nfsm1.txt");
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

TEST_F(TestDFSM1_convert, test1) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_1.word) , Test1_1.answer);
}
TEST_F(TestDFSM1_convert, test1_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_1.word) , !Test1_1.answer);
}

TEST_F(TestDFSM1_convert, test2) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_2.word) , Test1_2.answer);
}

TEST_F(TestDFSM1_convert, test2_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_2.word) , !Test1_2.answer);
}

TEST_F(TestDFSM1_convert, test3) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_3.word) , Test1_3.answer);
}
TEST_F(TestDFSM1_convert, test3_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_3.word) , !Test1_3.answer);
}
TEST_F(TestDFSM1_convert, test4) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_4.word) , Test1_4.answer);
}
TEST_F(TestDFSM1_convert, test4_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_4.word) , !Test1_4.answer);
}
TEST_F(TestDFSM1_convert, test5) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_5.word) , Test1_5.answer);
}
TEST_F(TestDFSM1_convert, test5_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_5.word) , !Test1_5.answer);
}
TEST_F(TestDFSM1_convert, test6) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_6.word) , Test1_6.answer);
}
TEST_F(TestDFSM1_convert, test6_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_6.word) , !Test1_6.answer);
}
TEST_F(TestDFSM1_convert, test7) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_7.word) , Test1_7.answer);
}
TEST_F(TestDFSM1_convert, test7_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_7.word) , !Test1_7.answer);
}
TEST_F(TestDFSM1_convert, test8) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_8.word) , Test1_8.answer);
}
TEST_F(TestDFSM1_convert, test8_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_8.word) , !Test1_8.answer);
}
TEST_F(TestDFSM1_convert, test9) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_9.word) , Test1_9.answer);
}
TEST_F(TestDFSM1_convert, test9_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_9.word) , !Test1_9.answer);
}
TEST_F(TestDFSM1_convert, test10) {
  ASSERT_EQ(dfsm_->RecognizeWord(Test1_10.word) , Test1_10.answer);
}
TEST_F(TestDFSM1_convert, test10_compl) {
  ASSERT_EQ(compl_dfsm->RecognizeWord(Test1_10.word) , !Test1_10.answer);
}
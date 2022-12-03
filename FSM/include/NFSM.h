#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include "globals.h"
#include "State.h"


struct EpsInfoState {
  std::vector<std::string> attempts;
  bool Find(std::string);
};



class NFSM {
 private:
  std::vector<State> states_;
  int q0_;
  int size_;
  std::bitset<MaxStateNumber> F_;
  int edge_size_;
  int S_size_ = SigmaSize;
  bool IsEpsExist = true;
  std::vector<EpsInfoState> SeenBefore;
  bool RecognizeWordIfNoEps(std::string, int);
  bool RecognizeWordIfExistEps(std::string, int);
 public:
  NFSM(const std::string& file);
  NFSM();
  void FilchEps();
  void print_states();
  void print_ndsm();
  void print_in_input_format();
  bool RecognizeWord(std::string);
  int getSize();
  std::vector<State> getStates();
  std::bitset<MaxStateNumber> getF();
};

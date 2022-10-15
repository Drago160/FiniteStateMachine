#pragma once
#include "NFSM.h"
#include "globals.h"
#include <bitset>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_set>
#include "State.h"
#include "utility.h"


struct IndexState {
  std::vector<int> tranzitions;
  int WayByLetter(int letter);
  void SetSize(int new_size);
  void SetWayByLetter(int letter, int new_tranz_index);
};


class DFSM{
 public:
  DFSM(std::string file_name);
  DFSM(NFSM nfsm);
  DFSM() = default;
  bool RecognizeWord(std::string);
  int getSize();
  std::vector<IndexState> getStates();
  std::bitset<MaxStateNumber> getF();
  void Complement();
 protected:
  std::vector<IndexState> states_;
  int size_;
  int S_size_;
  std::bitset<MaxStateNumber> F_;
};

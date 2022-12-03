#pragma once
#include<vector>
#include<bitset>
#include "globals.h"

struct State {
  std::vector<std::bitset<MaxStateNumber>> tranzitions;

  std::bitset<MaxStateNumber> way_by_letter(int x);
  std::bitset<MaxStateNumber> way_by_eps();
  void Unite(int letter, std::bitset<MaxStateNumber>);
  bool IsTranzIncludeState(int letter, int state_id);
  std::bitset<MaxStateNumber> WayByLetter(int letter);
  void SetWayByLetter(int letter, std::bitset<MaxStateNumber>);
  void SetSize(int new_size);
};

struct DetState {
  std::vector<std::bitset<MaxStateNumber>> tranzitions;
  std::bitset<MaxStateNumber> mask;
};

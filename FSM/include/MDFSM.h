#pragma once
#include "State.h"
#include "globals.h"
#include "DFSM.h"
#include <map>
#include <set>

class MDFSM: public DFSM{
 public:
  MDFSM(std::string file_name) : DFSM(file_name){};
  MDFSM(DFSM);
 private:
  void BuildStatesByClasses(std::vector<int> state_to_class,
                            std::vector<IndexState> last_states,
                            std::bitset<MaxStateNumber>);
};

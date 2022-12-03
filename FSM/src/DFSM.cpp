#include "DFSM.h"
#include <execution>
int IndexState::WayByLetter(int letter) {
  return tranzitions[letter];
}
void IndexState::SetSize(int new_size) {
  tranzitions.resize(new_size);
}
void IndexState::SetWayByLetter(int letter, int new_tranz_index){
  tranzitions[letter] = new_tranz_index;
}

DFSM::DFSM(std::string file_name) {
  S_size_ = SigmaSize;
  std::ifstream input(file_name);
  input >> size_;
  int term_flag = 0;
  for(int i = 0; i < size_; ++i) {
    input>>term_flag;
    if (term_flag) {
      F_.set(i);
    }
  }
  int way_by_letter;
  states_.resize(size_);
  if (input.is_open()) {
    for(int i = 0; i < size_; ++i) {
      states_[i].SetSize(S_size_+1);
      for (int c = 1; c < S_size_+1; ++c) {
        input >> way_by_letter;
        states_[i].SetWayByLetter(c, way_by_letter);
      }
    }
  } else {
    std::cout << "error input(no files)" << std::endl;
    }
}

DFSM::DFSM(NFSM fsm){
  std::vector<State> old_states = fsm.getStates();
  std::vector<DetState> new_states;
  std::bitset<MaxStateNumber> old_F = fsm.getF();
  std::cout << std::endl;
  int old_size = fsm.getSize();

  S_size_ = SigmaSize;
  F_ = 0;

  std::queue<std::bitset<MaxStateNumber>> WorkingStates;
  std::unordered_set<std::bitset<MaxStateNumber>, std::hash<std::bitset<MaxStateNumber>>> UsedStates;
  std::bitset<MaxStateNumber> zero;

  zero.set(0);
  UsedStates.insert(zero);
  WorkingStates.push(zero);

  DetState new_state;
  new_state.tranzitions.resize(S_size_+1);

  while (!WorkingStates.empty()) {
    new_state.mask = WorkingStates.front();
    WorkingStates.pop();
    new_state.tranzitions.resize(S_size_ + 1);
    for(int c = 1; c < S_size_+1; ++c) {
      new_state.tranzitions[c] = 0;
      for (int k = 0; k < old_size; ++k) {
        if (new_state.mask.test(k)) {
          new_state.tranzitions[c] |= old_states[k].way_by_letter(c);
        }
      }
      if (UsedStates.find(new_state.tranzitions[c]) == UsedStates.end()) {
        UsedStates.insert(new_state.tranzitions[c]);
        WorkingStates.push(new_state.tranzitions[c]);
      }
    }
    new_states.push_back(new_state);
  }
  states_.resize(new_states.size());
  size_ = new_states.size();
  for(int i = 0; i < size_; ++i) {
    states_[i].SetSize(S_size_ + 1);
    for(int c = 1; c < S_size_+1; ++c) {
      for(int j = 0; j < size_; ++j) {
        if (new_states[i].tranzitions[c] == new_states[j].mask) {
          states_[i].SetWayByLetter(c, j);
          break;
        }
        states_[i].SetWayByLetter(c, size_ - 1);
      }
    }
    if ((new_states[i].mask & old_F) != 0) {
      F_.set(i);
    }
  }
}


bool DFSM::RecognizeWord(std::string word) {
  int pivot = 0;
  for(int pos = 0; pos < word.size(); ++pos) {
    pivot = states_[pivot].WayByLetter(charBiject(word[pos]));
  }
  return F_.test(pivot);
}

int DFSM::getSize() {
  return size_;
}

std::vector<IndexState> DFSM::getStates() {
  return states_;
}

std::bitset<MaxStateNumber> DFSM::getF() {
  return F_;
}

void DFSM::Complement() {
  F_ = ~F_;
}
#include "NFSM.h"
#include "utility.h"


bool EpsInfoState::Find(std::string word) {
  for(const auto& w: attempts) {
    if (w == word) {
      return true;
    }
  }
  return false;
}


NFSM::NFSM() {
  q0_ = 0;
  size_ = 0;
  F_ = 0;
  edge_size_ = 0;
  IsEpsExist = false;
  S_size_ = SigmaSize;
}

NFSM::NFSM(const std::string& file) {
  std::ifstream input(file);
  int bit;
  if (input.is_open()) {
    input >> size_;
    input >> edge_size_;
    SeenBefore.resize(size_);
    states_.resize(size_);
    F_ = 0;
    for(int i = 0; i < size_; ++i) {
      input >> bit;
      if (bit == 1) {
        F_.set(i);
      }
      states_[i].SetSize((S_size_+1));
      states_[i].tranzitions.resize(S_size_ + 1);
    }
    int index;
    char tranzit_char;
    int to_state_index;
    for(int i = 0; i < edge_size_; ++i) {
      input >> index;
      input >> tranzit_char;
      input >> to_state_index;
      std::bitset<MaxStateNumber> to_state_index_mask;
      to_state_index_mask.set(to_state_index);
      states_[index].Unite(charBiject(tranzit_char), to_state_index_mask);
    }
  } else {
    std::cout << "error input(no files)";
  }
  input.close();
}
void NFSM::FilchEps() {
  std::bitset<MaxStateNumber> tmp_set;
  for (int j = 0; j < size_; ++j) {//пройдем по всем состояниям
    for (int k = 0; k < size_; ++k) { //проверяем можно ли прийти в эту вершину по eps
      tmp_set = states_[j].way_by_eps();
      if (states_[j].IsTranzIncludeState(0, k)) {
        for(int c = 0; c <= S_size_; ++c) { //по буквам итерируемся
          states_[j].Unite(c, states_[k].way_by_letter(c));
        }
      }
      if (states_[j].way_by_eps() != tmp_set) {
        k = -1; // to get 0 after for
      }
    }
    if ((states_[j].way_by_eps() & F_) != 0) {
      F_.set(j);
    }
  }
  IsEpsExist = false;
}
bool NFSM::RecognizeWord(std::string word) {
  if (IsEpsExist) {
    bool ret = RecognizeWordIfExistEps(word, 0);
    SeenBefore.clear();
    return ret;
  }
  return RecognizeWordIfNoEps(word, 0);
}

bool NFSM::RecognizeWordIfExistEps(std::string word, int pivot) {
  if (word == "") {
    if (!SeenBefore[pivot].Find(word)) {
    SeenBefore[pivot].attempts.push_back(word);
      for(int i = 0; i < size_; ++i) {
        if (states_[pivot].IsTranzIncludeState(0, i)) {
          if (RecognizeWordIfExistEps(word, i)) {
            return true;
          }
        }
      }
    }
    return F_.test(pivot);
  }

  std::string new_word = word;
  new_word.erase(0, 1);

  for(int c = 1; c < S_size_ + 1; ++c) {
    for(int i = 0; i < size_; ++i) {
      if (states_[pivot].IsTranzIncludeState(charBiject(word[0]), i)) {
        if (RecognizeWordIfExistEps(new_word, i)) {
          return true;
        }
      }
    }
  }

  if (!SeenBefore[pivot].Find(word)) {
    SeenBefore[pivot].attempts.push_back(word);
    for(int i = 0; i < size_; ++i) {
      if (states_[pivot].IsTranzIncludeState(0, i)) {
        if (RecognizeWordIfExistEps(word, i)) {
          return true;
        }
      }
    }
  }
  return false;
}

bool NFSM::RecognizeWordIfNoEps(std::string word, int pivot = 0) {
  if (word.empty()) {
    return F_.test(pivot);
  }
  int reading_sumbol = word[0];
  word.erase(0, 1);
  for(int c = 1; c < S_size_+1; ++c) {
    for(int j = 0; j < size_; ++j) {
      if (states_[pivot].IsTranzIncludeState(charBiject(reading_sumbol), j)) {
        if (RecognizeWordIfNoEps(word, j)) {
          return true;
        }
      }
    }
  }
  return false;
}

int NFSM::getSize() { return size_; }

void NFSM::print_states() {
  for(int i = 0; i < size_; ++i) {
    std::cout << "1: " << states_[i].tranzitions[0] << std::endl;
    std::cout << "a: " << states_[i].tranzitions[1] << std::endl;
    std::cout << "b: " << states_[i].tranzitions[2] << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
  }
  std::cout << F_;
}

void NFSM::print_ndsm() {
  for(int i = 0; i < size_; ++i) {
    for(int c = 1; c < S_size_+1; ++c) {
      for(int j = 0; j < size_; ++j) {
        if(states_[i].WayByLetter(c).test(j)) {
          std::cout << "(" << i << ", "<< intBiject(c) <<") -> " << j << std::endl;
        }
      }
    }
  }
  for(int c = 0; c < size_; ++c) {
    if (F_.test(c)) {
      std::cout << c << " ";
    }
  }
}

void NFSM::print_in_input_format() {
  std::cout << size_ << std::endl;
  for(int c = 0; c < size_; ++c) {
    if (F_.test(c)) {
      std::cout << 1 << " ";
    } else {
      std::cout << 0 << " ";
    }
  }
  std::cout << std::endl;
  for(int i = 0; i < size_; ++i) {
    for(int c = 1; c < S_size_+1; ++c) {
      for(int j = 0; j < size_; ++j) {
        if(states_[i].WayByLetter(c).test(j)) {
          std::cout << i << " "<< intBiject(c) << " "<< j << std::endl;
        }
      }
    }
  }
}

std::vector<State> NFSM::getStates() {
    return states_;
}

std::bitset<MaxStateNumber> NFSM::getF() {
  return F_;
}

#include"RegularFSM.h"

Regular_automat::Regular_automat(DFSM aut) {
  std::vector<IndexState> old_states = aut.getStates();
  std::bitset<MaxStateNumber> old_F = aut.getF();
  size_ = aut.getSize();
  reg_states_.resize(size_+1);
  S_size_ = SigmaSize;
  std::string tranz_word;
  int tranz_state_index;
  for(int i = 0; i < size_; ++i) {
    for(int c = 1; c < S_size_ + 1; ++c) {
      tranz_word = intBiject(c);
      tranz_state_index = old_states[i].WayByLetter(c);
      if (tranz_state_index == i) {
        reg_states_[i].mesh = tranz_word;
        continue;
      }
      reg_states_[i].outputs.push_back(way(tranz_state_index, tranz_word));
      reg_states_[tranz_state_index].inputs.push_back(configuration(i, tranz_word));
    }
    if (old_F.test(i)) {
      reg_states_[i].outputs.push_back(way(aut.getSize(), "1"));
      reg_states_[size_].inputs.push_back(configuration(i, "1"));
    }
  }
  size_++;
  MakeRegular();
}

void Regular_automat::MakeRegular() {
  for(int i = 1; i < size_-1; ++i) {
    Filch(i);
  }
}

void Regular_automat::Filch(int index) {
  reg_state pivot = reg_states_[index];
  std::string new_word;
  for(configuration& conf_in : pivot.inputs) {
    for (way& way_out : pivot.outputs) {
      if (pivot.mesh == "1") {
        new_word = /*"("*/ conf_in.word + way_out.word/* + ")"*/;
      } else {
        new_word = /*"("*/ conf_in.word + "(" + pivot.mesh + ")*" + way_out.word/* + ")"*/;
      }
      if (way_out.index == conf_in.index) {
        reg_states_[way_out.index].mesh = "(" + reg_states_[way_out.index].mesh + "+" + new_word + ")";
        continue;
      }
      bool filching_flag = false;
      for (way& way_of_in : reg_states_[conf_in.index].outputs) { // проверяем на то если уже есть такой путь из предшествующего
        if (way_of_in.index == way_out.index) {
          way_of_in = {way_out.index, "(" + way_of_in.word + "+" + new_word + ")"};
          filching_flag = true;
          continue;
        }
      }
      for(configuration& conf_of_out : reg_states_[way_out.index].inputs) {  //
        if (conf_of_out.index == conf_in.index) {
          conf_of_out = {conf_in.index, "(" + conf_of_out.word + "+" + new_word + ")"};
          continue;
        }
      }
      if (!filching_flag) {
        reg_states_[conf_in.index].outputs.push_back({way_out.index, new_word});
        reg_states_[way_out.index].inputs.push_back({conf_in.index, new_word});
      }
    }
  }
  DeleteState(index);
}

void Regular_automat::DeleteState(int index) {
  IsUsed_.resize(size_);
  bool break_flag = false;
  for(configuration& conf : reg_states_[index].inputs) {
    if (break_flag) {
      break;
    }
    for(int i = 0; i < reg_states_[conf.index].outputs.size(); ++i) {
      if (reg_states_[conf.index].outputs[i].index == index) {
        reg_states_[conf.index].outputs.erase(reg_states_[conf.index].outputs.begin() + i);
        break_flag = false;
        break;
      }
    }
  }
  break_flag = false;
  for(way& way_in : reg_states_[index].outputs) {
    if (break_flag) {
      break;
    }
    for(int i = 0; i < reg_states_[way_in.index].inputs.size(); ++i) {
      if (reg_states_[way_in.index].inputs[i].index == index) {
        reg_states_[way_in.index].inputs.erase(reg_states_[way_in.index].inputs.begin() + i);
        break_flag = false;
        break;
      }
    }
  }
  IsUsed_[index] = true;
  reg_states_[index].outputs.clear();
  reg_states_[index].inputs.clear();
}


std::string Regular_automat::GetRegex() {
  return "(" + reg_states_[0].mesh + ")*" + "(" + reg_states_[0].outputs[0].word + ")";
}

void Regular_automat::PrintRegex() {
  std::cout << GetRegex();
}

void Regular_automat::PrintForLatex() {
    std::string reg = GetRegex();
    for (char& c : reg) {
      if (c == '*') {
        std::cout << "^";
      }
      std::cout << c;
    }
  }
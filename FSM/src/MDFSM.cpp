#include "MDFSM.h"


MDFSM::MDFSM(DFSM dfsm) {
  size_ = dfsm.getSize();
  S_size_ = SigmaSize;
  std::vector<IndexState> old_states = dfsm.getStates();
  std::bitset<MaxStateNumber> old_F = dfsm.getF();

  std::vector<int> state_to_class(size_);
  std::vector<int> state_to_class_old(size_);
  std::vector<int> new_link(size_);

  int term_represent;
  int nonterm_represent;

  for(int i = 0; i < size_; ++i) {
    if (old_F.test(i)) {
      term_represent = i;
      break;
    }
  }
  for(int i = 0; i < size_; ++i) {
    if (!old_F.test(i)) {
      nonterm_represent = i;
      break;
    }
  }

  for(int i = 0; i < size_; ++i) {
    if (old_F.test(i)) {
      state_to_class[i] = term_represent;
    } else {
      state_to_class[i] = nonterm_represent;
    }
  }

  std::map<std::pair<int, int>, int> new_classes_represent; //новые классы определяются в зависимости от пары начало->конец
  int last_size = 2;
  int new_size = 0;
  while (new_size != last_size) {
    last_size = new_size;
    for(int c = 1; c < S_size_+1; ++c) {
      state_to_class_old = state_to_class;
      for (int i = 0; i < size_; ++i) {
        new_link[i] = state_to_class_old[old_states[i].WayByLetter(c)];
        if (new_classes_represent.find({state_to_class_old[i], new_link[i]}) == new_classes_represent.end()) {
         //Если еще не задан репрезентативный для данного перехода
         new_classes_represent[{state_to_class_old[i], new_link[i]}] = i;
         state_to_class[i] = i;
        } else {
          state_to_class[i] = new_classes_represent[{state_to_class_old[i], new_link[i]}];
        }
      }
      new_size = new_classes_represent.size();
      new_classes_represent.clear();
    }
  }

  BuildStatesByClasses(state_to_class, old_states, old_F);
}

void MDFSM::BuildStatesByClasses(std::vector<int> state_to_class,
                                 std::vector<IndexState> last_states,
                                 std::bitset<MaxStateNumber> old_F) {

  std::set<int> dif_classes;
  for(const int& repr: state_to_class) { // добавляем классы в множество
    dif_classes.insert(repr);
  }

  //тут информация про связь старых и новых классов через индексы репрезентативных
  std::map<int, int> new_index_to_old_repr_index;
  std::map<int, int> old_repr_index_to_new_index;
  std::set<int> used_classes_ind;
  int last_class_index = 0;

  //делаем все классы идущими по порядку
  for(int& repr: state_to_class) { // переделываем классы для минимальных
    if (used_classes_ind.find(repr) != used_classes_ind.end()) { //если для этого класса уже найден индекс нового
      repr = old_repr_index_to_new_index[repr];
    } else {
      used_classes_ind.insert((repr));
      old_repr_index_to_new_index[repr] = last_class_index;
      new_index_to_old_repr_index[last_class_index] = repr;
      repr = last_class_index;
      last_class_index++;
    }
  }

  size_ = last_class_index;
  states_.resize(size_);

  //наконец переназначаем классы и делаем из них автомат
  for(int i = 0; i < size_; ++i) {
    states_[i].SetSize(S_size_ + 1);
    for(int c = 1; c < S_size_+1; ++c) {
      int new_way = state_to_class[last_states[new_index_to_old_repr_index[i]].WayByLetter(c)];
      states_[i].SetWayByLetter(c, new_way);
    }
  }

  F_ = 0;
  for(int i = 0; i < last_states.size(); ++i) {
    if (old_F.test(i)) {
      F_.set(state_to_class[i]);
    }
  }
}


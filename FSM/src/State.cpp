#include "State.h"

std::bitset<MaxStateNumber> State::way_by_letter(int n) {
  return tranzitions[n];
}

std::bitset<MaxStateNumber> State::way_by_eps() {
  return tranzitions[0];
}

void State::Unite(int letter, std::bitset<MaxStateNumber> states_mask) {
  tranzitions[letter] |= states_mask;
}

bool State::IsTranzIncludeState(int letter, int state_id) {
  return tranzitions[letter].test(state_id);
}

std::bitset<MaxStateNumber> State::WayByLetter(int letter) {
  return tranzitions[letter];
}

void State::SetWayByLetter(int letter, std::bitset<MaxStateNumber> new_way) {
  tranzitions[letter] = new_way;
}

void State::SetSize(int new_size) {
  tranzitions.resize(new_size);
}
#include <string>
#include <iostream>
#include <DFSM.h>

struct configuration {
  int index; //куда пришел
  std::string word; //по какому слову
  configuration(int x):index(x), word("1"){};
  configuration(int x, std::string s): index(x), word(s){};
};

struct way {
  int index; //откуда иду
  std::string word; //по какому слову
  way(int x, std::string s): index(x), word(s){};
  way(int x): index(x), word("1"){};
};

struct reg_state {
  std::vector<configuration> inputs;
  std::vector<way> outputs;
  std::string mesh = "1";
  reg_state() = default;
};

class Regular_automat {
 private:
  std::vector<bool> IsUsed_;
  std::vector<reg_state> reg_states_;
  int size_;
  int S_size_;
  void DeleteState(int index);
  void Filch(int index);
 public:
  Regular_automat(DFSM aut);
  void MakeRegular();
  void print_for_latex();
  std::string GetRegex();
  void PrintRegex();
  void PrintForLatex();

};

#pragma once
#include <string>

struct Test_pair {
  std::string word;
  bool answer;
  Test_pair(std::string word, bool answer) : word{word}, answer{answer}{};
};

const Test_pair Test1_1 = {"a", true};
const Test_pair Test1_2 = {"b", false};
const Test_pair Test1_3 = {"bb", false};
const Test_pair Test1_4 = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa", true};
const Test_pair Test1_5 = {"bbbaaabbba", false};
const Test_pair Test1_6 = {"", false};
const Test_pair Test1_7 = {"aaab", false};
const Test_pair Test1_8 = {"ab", false};
const Test_pair Test1_9 = {"bbbbbb", false};
const Test_pair Test1_10 = {"aaaaaa", true};
const int size1 = 3;

const Test_pair Test2_1 = {"a", true};
const Test_pair Test2_2 = {"b", true};
const Test_pair Test2_3 = {"ab", false};
const Test_pair Test2_4 = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaa", false};
const Test_pair Test2_5 = {"ba", false};
const Test_pair Test2_6 = {"", false};
const Test_pair Test2_7 = {"bb", false};
const Test_pair Test2_8 = {"bbbba", false};
const Test_pair Test2_9 = {"aaaab", false};
const Test_pair Test2_10 = {"aa", false};
const int size2 = 3;

const Test_pair Test3_1 = {"b", true};
const Test_pair Test3_2 = {"bb", true};
const Test_pair Test3_3 = {"abababababbaaaaaaaaaaa", true};
const Test_pair Test3_4 = {"", false};
const Test_pair Test3_5 = {"aaba", false};
const Test_pair Test3_6 = {"aaaaaa", false};
const Test_pair Test3_7 = {"bbbbbb", true};
const Test_pair Test3_8 = {"baaaaa", true};
const Test_pair Test3_9 = {"aaaaaaab", false};
const Test_pair Test3_10 = {"baaababbababaababab", true};
const int size3 = 3;

const Test_pair Test4_1 = {"aba", true};
const Test_pair Test4_2 = {"abba", true};
const Test_pair Test4_3 = {"abababbababa", true};
const Test_pair Test4_4 = {"", true};
const Test_pair Test4_5 = {"a", true};
const Test_pair Test4_6 = {"ba", true};
const Test_pair Test4_7 = {"bbbbbbb", false};
const Test_pair Test4_8 = {"aa", false};
const Test_pair Test4_9 = {"bb", false};
const Test_pair Test4_10 = {"bababaa", true};
const int size4 = 4;

const Test_pair Test5_1 = {"b", true};
const Test_pair Test5_2 = {"", true};
const Test_pair Test5_3 = {"aaaaaab", true};
const Test_pair Test5_4 = {"ababbaba", true};
const Test_pair Test5_5 = {"ab", true};
const Test_pair Test5_6 = {"bab", false};
const Test_pair Test5_7 = {"baa", false};
const Test_pair Test5_8 = {"bba", false};
const Test_pair Test5_9 = {"baaba", false};
const Test_pair Test5_10 = {"babab", false};
const int size5 = 6;

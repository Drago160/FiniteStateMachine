#include "utility.h"

int charBiject(char c) {
  if (c == '1') {
    return 0;
  }
  return c - 'a' + 1;
}

char intBiject(int x) {
  if (x == 0) {
    return '1';
  }
  return x + 'a' - 1;
}

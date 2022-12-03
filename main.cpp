#include "DFSM.h"
#include "NFSM.h"
#include "RegularFSM.h"
#include "MDFSM.h"

int main() {
  NFSM nfsm("../tests/SM_examples/NFSM_examples/nfsm1.txt"); // файл c примером автомата из ридинга (a+)
  DFSM dfsm("../tests/SM_examples/DFSM_examples/dfsm1.txt");
  std::cout << nfsm.RecognizeWord("aaa");
  std::cout << nfsm.RecognizeWord("bbb");
  std::cout << nfsm.RecognizeWord("") << std::endl;
  std::cout << dfsm.RecognizeWord("aaa");
  std::cout << dfsm.RecognizeWord("bbb");
  std::cout << dfsm.RecognizeWord("");
  return 0;
}
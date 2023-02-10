#include <iostream>

int doSomeThing(int currentSum, int input) {
  bool doPrintStuff = false;
  doPrintStuff && std::cout << "doSomeThing(" << currentSum << ", " << input << ")" << std::endl;
  return currentSum + (input * 2);
}

int main() {
  std::cout << "Hello" << std::endl;

  int sum = 0;
  for (int i = 0; i < 100; ++i) {
    std::cout << "main(): sum value: " << sum << std::endl;
    sum = doSomeThing(sum, i);
  }

  std::cout << "Final sum: " << sum << std::endl;

  return 0;
}
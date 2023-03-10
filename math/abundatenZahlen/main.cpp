#include <cmath>
#include <iostream>

int abundant(int testNum) {

  int result = 1;
  //
  for (int i = 2; i <= std::sqrt(testNum); ++i) {
    if (testNum % i == 0) {
      result += (i == (testNum / i)) ? i : (i + testNum / i);
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  int grenze{};
  int abundanz{};
  std::cin >> grenze;

  // erste abundate zahl geht ab 12 los
  for (int i = 10; i <= grenze; ++i) {
    int sum = abundant(i);
    if (sum > i) {
      // ausgabe der zahl und ihrer abundanz
      std::cout << i << " " << sum - i << std::endl;
    }
  }

  return 0;
}

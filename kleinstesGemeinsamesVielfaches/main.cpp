#include <iostream>

int ggt(int a, int b) { return b == 0 ? a : ggt(b, a % b); }

int kgv(int const num1, int const num2) {
  int temp = ggt(num1, num2);
  return temp ? (num1 * (num2 / temp)) : 0;
}

int main(int argc, const char *argv[]) {
  int eingabeNum1{};
  int eingabeNum2{};
  if (argc > 1) {
    eingabeNum1 = std::stoi(argv[1]);
    eingabeNum2 = std::stoi(argv[2]);
  } else {
    std::cin >> eingabeNum1;
    std::cin >> eingabeNum2;
  }

  int kgvAusgabe = kgv(eingabeNum1, eingabeNum2);
  std::cout << kgvAusgabe << std::endl;
}

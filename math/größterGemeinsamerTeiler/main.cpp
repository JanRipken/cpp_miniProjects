#include <iostream>

int gcd1(int num1, int num2) {
  while (num2 != 0) {
    int temp = num1 % num2;
    num1 = num2;
    num2 = temp;
  }
  return num1;
}

int gcd2(int a, int b) { return b == 0 ? a : gcd2(b, a % b); }

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

  int gcd1Ausgabe = gcd1(eingabeNum1, eingabeNum2);
  int gcd2Ausgabe = gcd2(eingabeNum1, eingabeNum2);
  std::cout << gcd1Ausgabe << std::endl;
  std::cout << gcd2Ausgabe << std::endl;
}

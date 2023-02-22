#include <iostream>

int groessterTeiler(int num1, int num2) {
  while (num2 != 0) {
    int temp = num1 % num2;
    num1 = num2;
    num2 = temp;
  }
  return num1;
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

  int gcd = groessterTeiler(eingabeNum1, eingabeNum2);
  std::cout << gcd << std::endl;
}

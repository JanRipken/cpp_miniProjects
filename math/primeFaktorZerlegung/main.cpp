#include <iostream>
int main() {
  int zahl;
  std::cout << "Zahl: ";
  std::cin >> zahl;

  int primfaktor = 2;
  while (zahl > 1) {
    if (zahl % primfaktor == 0) {
      std::cout << primfaktor << " ";
      zahl /= primfaktor;
    } else {
      primfaktor++;
    }
  }
  std::cout << std::endl;

  return 0;
}

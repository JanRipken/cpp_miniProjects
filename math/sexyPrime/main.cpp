#include <iostream>
#include <iterator>
// sexy prime = prime + 6 = prime
bool is_prime(unsigned int grenze) {
  for (unsigned int i = 2; i * i <= grenze; i++) {
    if (grenze % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  unsigned int grenze{};
  std::cout << "Grenze: ";
  std::cin >> grenze;

  unsigned int sexyPrime1 = 0;
  unsigned int sexyPrime2 = 0;
  for (int i = grenze; i >= 2; i--) {
    if (is_prime(i)) {
      sexyPrime1 = i;
      i = i - 6;
      if (is_prime(i)) {
        sexyPrime2 = i;
        std::cout << sexyPrime1 << " " << sexyPrime2 << std::endl;
      }
    }
  }

  return 0;
}

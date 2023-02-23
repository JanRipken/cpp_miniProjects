#include <iostream>

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

  unsigned int max_prime = 0;
  for (unsigned int i = 2; i <= grenze; i++) {
    if (is_prime(i)) {
      max_prime = i;
    }
  }

  if (max_prime == 0) {
    std::cout << "Keine Primzahlen. " << std::endl;
  } else {
    std::cout << "Die größte Primzahl ist: " << max_prime << std::endl;
  }
  return 0;
}

#include <iostream>

void terminal() {
  int ipv4{};
  std::cout << "IPv4 bitte: ";
  std::cin >> ipv4;
  std::cout << "Danke !"
            << "\n";
}

int main(int argc, char *argv[]) {

  terminal();
  return 0;
}

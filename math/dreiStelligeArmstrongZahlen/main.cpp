#include <iostream>

void armssssss() {
  for (int x = 1; x <= 9; ++x) {
    for (int y = 1; y <= 9; ++y) {
      for (int z = 1; z <= 9; ++z) {
        auto xyz = x * 100 + y * 10 + z;
        auto arm = x * x * x + y * y * y + z * z * z;
        if (xyz == arm) {
          std::cout << arm << std::endl;
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  armssssss();
  return 0;
}

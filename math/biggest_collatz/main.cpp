#include <iostream>
#include <utility>
#include <vector>

int even(int num) {
  num = num / 2;
  return num;
}

int odd(int num) {
  num = 3 * num + 1;
  return num;
}

int main(int argc, char *argv[]) {
  int max = 1000000;
  std::vector<std::pair<int, int>> lenColaltz;

  int i = 1;
  while (i <= max) {
    int j = i;
    int counter = 1;
    while (j != 1) {
      if (j % 2 == 0) {
        j = even(j);
      } else {
        j = odd(j);
      }
      counter++;
    }
    lenColaltz.push_back(std::make_pair(i, counter));
    i++;
  }

  // Find the pair with the highest second value
  int highest_length = 0;
  int number_with_highest_length = 0;
  for (std::pair<int, int> p : lenColaltz) {
    if (p.second > highest_length) {
      highest_length = p.second;
      number_with_highest_length = p.first;
    }
  }

  // Output the number with the longest Collatz sequence and its length
  std::cout << "Number with the longest Collatz sequence: "
            << number_with_highest_length << ", Length: " << highest_length
            << std::endl;

  return 0;
}

#include <cmath>
#include <iostream>
// sicherstellen das jede befreundete zahl nur einmal ausgegen wird
#include <set>

int sumEchteTeiler(int const num) {
  int result = 1;
  for (int i = 2; i <= std::sqrt(num); ++i) {
    if (num % i == 0) {
      result += (i == (num / i) ? i : (i + num / i));
    }
  }
  return result;
}

void befreundet(int const grenze) {
  std::set<std::pair<int, int>> ausgabe;
  for (int num = 4; num < grenze; ++num) {
    auto sum1 = sumEchteTeiler(num);
    if (sum1 < grenze) {
      auto sum2 = sumEchteTeiler(sum1);
      if (sum2 == num && num != sum1) {
        // das kleinere element des Paares wird zuerste ausgegebn thats why
        // u rlly should know that .... just learn it .....again
        // https://www.geeksforgeeks.org/sets-of-pairs-in-c/
        auto paar = std::make_pair(num, sum1);
        if (ausgabe.count(paar) == 0 &&
            ausgabe.count(std::make_pair(sum1, num)) == 0) {
          ausgabe.insert(paar);
          std::cout << num << " " << sum1 << std::endl;
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  befreundet(1000000);
  return 0;
}

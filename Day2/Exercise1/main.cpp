#include <iostream>
#include <string>

int main() {
  constexpr int premade_scores[3][3] = {{4, 8, 3}, {1, 5, 9}, {7, 2, 6}};
  std::uint64_t total_score = 0;
  std::string line;
  while(std::getline(std::cin, line)) {
      total_score += premade_scores[line[0] - 'A'][line[2] - 'X'];
  }
  std::cout << total_score << '\n';
  return 0;
}

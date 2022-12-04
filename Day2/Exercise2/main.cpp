#include <iostream>
#include <string>

int main() {
   constexpr int premade_scores[3][3] = {{3, 4, 8}, {1, 5, 9}, {2, 6, 7}};
   std::string line;
   std::uint64_t total_score = 0;
   while(std::getline(std::cin, line)) {
       total_score += premade_scores[line[0] - 'A'][line[2] - 'X'];
   }
   std::cout << total_score << '\n';
  return 0;
}

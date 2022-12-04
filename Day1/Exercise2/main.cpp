#include <iostream>
#include <numeric>
#include <string>


int main() {
    std::uint64_t three_best[3] = {0, 0, 0};
    std::uint64_t running = 0;
    std::string line;
    while(std::getline(std::cin, line)) {
        if (line.empty()) {
            if (running > three_best[2]) {
                three_best[2] = running;
                if (three_best[2] > three_best[1]) {
                    std::swap(three_best[2], three_best[1]);
                    if (three_best[1] > three_best[0]) {
                        std::swap(three_best[1], three_best[0]);
                    }
                }
            }
            running = 0;
        } else {
            running += std::stol(line);
        }
    }
    std::cout << std::accumulate(std::cbegin(three_best), std::cend(three_best), 0UL) << '\n';
    return 0;
}
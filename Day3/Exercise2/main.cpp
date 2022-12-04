#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    std::string line;
    std::string line2;
    std::string line3;
    std::uint64_t priority_sum = 0;
    while(std::getline(std::cin, line)) {
        std::getline(std::cin, line2);
        std::getline(std::cin, line3);

    }
    std::cout << priority_sum << '\n';
    return 0;
}

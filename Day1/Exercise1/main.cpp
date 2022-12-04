#include <iostream>
#include <string>

int main() {
    std::uint64_t winner = 0;
    std::uint64_t running = 0;
    std::string line;
    while(std::getline(std::cin, line)) {
        if(line.empty()) {
            if (running > winner) {
                winner = running;
            }
            running = 0;
        } else {
            running += std::stol(line);
        }
    }
    std::cout << winner << '\n';
    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>

int main () {
    std::string line;
    std::uint64_t priority_sum = 0;
    while(std::getline(std::cin, line)) {
        std::string split1 = line.substr(0, line.size() / 2);
        std::string split2 = line.substr(line.size() / 2);
        std::sort(split2.begin(), split2.end());
        if (split1.find(split2[0]) != std::string::npos) {
            if (split2[0] >= 97 && split2[0] <= 122) {
                priority_sum += split2[0] - 96;
            } else if (split2[0] >= 65 && split2[0] <= 90) {
                priority_sum += split2[0] - 38;
            }
        }
        for (std::size_t i = 1; i < split2.size(); i++) {
            if(split2[i] != split2[i-1]) {
                if (split1.find(split2[i]) != std::string::npos) {
                    if (split2[i] >= 97 && split2[i] <= 122) {
                        priority_sum += split2[i] - 96;
                    } else if (split2[i] >= 65 && split2[i] <= 90) {
                        priority_sum += split2[i] - 38;
                    }
                }
            }
        }
    }
    std::cout << priority_sum << '\n';
    return 0;
}
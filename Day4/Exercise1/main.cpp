#include <iostream>
#include <string>

int main () {
    std::string line;
    std::uint64_t count = 0;
    while(std::getline(std::cin, line)) {
        std::string split = line.substr(0, line.find(','));
        std::string split2 = line.substr(line.find(',')+1);
        int range1_b = std::stoi(split.substr(0, '-'));
        int range1_e = std::stoi(split.substr(split.find('-')+1));
        int range2_b = std::stoi(split2.substr(0, '-'));
        int range2_e = std::stoi(split2.substr(split2.find('-')+1));
        if ((range1_b >= range2_b && range1_e <= range2_e) ||
            (range2_b >= range1_b && range2_e <= range1_e)) {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}

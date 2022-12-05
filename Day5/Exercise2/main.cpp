#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
int main () {
    //I reformated the input of the file for this exercise, since parsing strings in C++
    //is still a major pain in the ass in 2022. No such thing as split into tokens and store into container...
    std::string line;
    //Get the number of stacks
    std::getline(std::cin, line);
    std::size_t number_of_stacks = std::stoi(line);
    std::vector<std::stack<char>> box_stacks{number_of_stacks, std::stack<char>{}};
    for (std::size_t i = 0; i < number_of_stacks; i++) {
        std::getline(std::cin, line);
        std::stringstream input_string_stream(line);
        std::istream_iterator<char> i_stream_iterator(input_string_stream);
        std::istream_iterator<char> eof;
        while(i_stream_iterator != eof) {
            box_stacks[i].push(*i_stream_iterator);
            i_stream_iterator++;
        }
    }
    while(std::getline(std::cin, line)) {
        std::vector<int> indexes;
        std::stringstream input_string_stream(line);
        std::istream_iterator<std::string> i_stream_iterator(input_string_stream);
        std::istream_iterator<std::string> eof;
        //Highly customized for this input
        while (i_stream_iterator != eof) {
            if (*i_stream_iterator != "move" && *i_stream_iterator != "from"
                && *i_stream_iterator != "to") {
                indexes.push_back(std::stoi(*i_stream_iterator));
            }
            i_stream_iterator++;
        }
        std::stack<char> helper_stack;
        for(int amount = 0; amount < indexes[0]; amount++) {
            helper_stack.push(box_stacks[indexes[1]-1].top());
            box_stacks[indexes[1]-1].pop();
        }

        for (int amount = 0; amount < indexes[0]; amount++) {
            box_stacks[indexes[2]-1].push(helper_stack.top());
            helper_stack.pop();
        }
    }
    for(const auto& box_stack : box_stacks) {
        std::cout << box_stack.top();
    }
    return 0;
}

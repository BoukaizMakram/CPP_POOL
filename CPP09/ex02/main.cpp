#include "PmergeMe.hpp"

bool isValidNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }
    
    std::vector<int> input;
    for (int i = 1; i < argc; i++) {
        if (!isValidNumber(argv[i])) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'" << std::endl;
            return 1;
        }
        input.push_back(std::atoi(argv[i]));
    }
    
    PmergeMe sorter(input);
    sorter.sortAndMeasure();
    
    return 0;
}
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe sorter;
    std::vector<int> original_vector;
    
    // Parse and validate input
    if (!sorter.parseInput(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    original_vector = sorter.getVector();
    // Sort the input
    sorter.sort();
    
    // Display results
    sorter.displayResults(original_vector);
    
    return 0;
}
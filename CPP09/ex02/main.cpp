#include "PmergeMe.hpp"

void printContainer(const std::string label, const std::vector<int>& vec) 
{
    std::cout << label;
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    PmergeMe sorter;

    if (ac < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;

    for (int i = 1; i < ac; i++) {
        std::stringstream ss(av[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            std::cerr << "Error: Invalid number." << std::endl;
            return 1;
        }
        vec.push_back(num);
    }
    sorter.sortVector(vec);
    printContainer("Vector:", vec);
}
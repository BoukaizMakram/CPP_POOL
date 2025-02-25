#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) { (void) other; return (*this); }

void PmergeMe::sortVector(std::vector<int>& vec) 
{
    if (vec.size() < 2) return;

    std::vector<int> sorted;
    sorted.push_back(vec[0]);

    for (size_t i = 1; i < vec.size(); i++) {
        printContainer("Sorted: ", sorted);
        printContainer("Vector: ", vec);
        std::vector<int>::iterator it = sorted.begin();
        while (it != sorted.end() && *it < vec[i]) ++it;
        sorted.insert(it, vec[i]);
    }
    vec = sorted;
}

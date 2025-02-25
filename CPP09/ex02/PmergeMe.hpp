#pragma once

#include <cstdlib>
#include <sstream>
#include <vector>
#include <iostream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortVector(std::vector<int>& vec);
};

void printContainer(const std::string label, const std::vector<int>& vec);
#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class PmergeMe 
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        
        template <typename T>
        void mergeInsertSort(T& container);
        
        std::vector<int> generateJacobsthal(int n);

        template <typename T>
        void printContainer(const T& container);

    public:
        PmergeMe();
        PmergeMe(const std::vector<int>& input);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        void sortAndMeasure();
};
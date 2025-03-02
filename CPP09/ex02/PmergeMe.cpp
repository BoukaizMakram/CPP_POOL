#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
    *this = other;
}

PmergeMe::PmergeMe(const std::vector<int>& input) : 
vec(input.begin(), input.end()), deq(input.begin(), input.end()) {}

PmergeMe::~PmergeMe() {};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return (*this);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container)
{
    if (container.size() < 2) return;
    std::vector<int> jacob = generateJacobsthal(container.size());
    std::vector<int> sorted;
    
    for (size_t i = 1; i < container.size(); i += 2) {
        if (container[i - 1] > container[i]) std::swap(container[i - 1], container[i]);
        sorted.push_back(container[i]);
    }
    if (container.size() % 2 == 1) {
        sorted.push_back(container.back());
    }
    
    mergeInsertSort(sorted);
    
    for (size_t i = 0; i < container.size(); i += 2) {
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), container[i]);
        sorted.insert(pos, container[i]);
    }
    
    for (size_t i = 0; i < container.size(); i++) {
        container[i] = sorted[i];
    }
}

std::vector<int> PmergeMe::generateJacobsthal(int n) 
{
    std::vector<int> jacobsthal;
    if (n == 0) return jacobsthal;
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(1);
    for (int i = 2; i < n; i++) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }
    return jacobsthal;
}

template <typename T>
void PmergeMe::printContainer(const T& container) {
    for (size_t i = 0; i < container.size(); i++) std::cout << container[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sortAndMeasure() 
{
    std::cout << "Before: ";
    printContainer(vec);
    
    clock_t startVec = clock();
    mergeInsertSort(vec);
    clock_t endVec = clock();
    
    clock_t startDeq = clock();
    mergeInsertSort(deq);
    clock_t endDeq = clock();
    
    std::cout << "After: ";
    printContainer(vec);
    
    std::cout << "Time to process " << vec.size() << " elements with std::vector: " 
                << static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC << " sec" << std::endl;
    
    std::cout << "Time to process " << deq.size() << " elements with std::deque: " 
                << static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC << " sec" << std::endl;
}

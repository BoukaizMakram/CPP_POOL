#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <iomanip>


class PmergeMe {
private:
    std::vector<int> _vector;
    std::list<int> _list;
    double _vectorTime;
    double _listTime;
    
    // Helper functions for vector implementation
    std::vector<int> mergeInsertSortVector(std::vector<int>& arr);
    void insertSortVector(std::vector<int>& arr, int begin, int end);
    void mergePairsVector(std::vector<std::pair<int, int> >& pairs);
    
    // Helper functions for list implementation
    std::list<int> mergeInsertSortList(std::list<int>& arr);
    void insertElementList(std::list<int>& arr, int value);
    
    // Jacobsthal sequence for insertion order
    std::vector<int> generateJacobsthalSequence(int n);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    // Parse and validate input
    bool parseInput(int argc, char** argv);
    
    // Sort using both containers
    void sort();
    
    // Display results
    void displayResults(std::vector<int> original_vec);
    
    // Getters
    const std::vector<int>& getVector() const;
    const std::list<int>& getList() const;
    double getVectorTime() const;
    double getListTime() const;
};

#endif
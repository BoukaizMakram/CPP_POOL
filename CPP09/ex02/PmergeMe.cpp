#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vectorTime(0), _listTime(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _list = other._list;
        _vectorTime = other._vectorTime;
        _listTime = other._listTime;
    }
    return *this;
}

bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2)
        return false;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // Check for non-numeric characters
        for (size_t j = 0; j < arg.length(); ++j) {
            if (j == 0 && arg[j] == '-')
                return false;  // Negative numbers not allowed
            if (!std::isdigit(arg[j]))
                return false;
        }
        
        // Convert to integer
        int num;
        std::istringstream iss(arg);
        iss >> num;
        
        if (num < 0)
            return false;  // Negative numbers not allowed
            
        _vector.push_back(num);
        _list.push_back(num);
    }
    
    return true;
}

void PmergeMe::sort() {
    // Sort vector
    clock_t startVector = clock();
    _vector = mergeInsertSortVector(_vector);
    _vectorTime = static_cast<double>(clock() - startVector) / CLOCKS_PER_SEC * 1000000;
    
    // Sort list
    clock_t startList = clock();
    _list = mergeInsertSortList(_list);
    _listTime = static_cast<double>(clock() - startList) / CLOCKS_PER_SEC * 1000000;
}

// Generate Jacobsthal sequence up to n
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    if (n <= 0) return sequence;
    
    sequence.push_back(0);
    if (n == 1) return sequence;
    
    sequence.push_back(1);
    if (n == 2) return sequence;
    
    for (int i = 2; i < n; ++i) {
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
    }
    
    return sequence;
}

// VECTOR IMPLEMENTATION

std::vector<int> PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    int size = arr.size();
    
    // Base case for small arrays
    if (size <= 1)
        return arr;
    
    // For small arrays, use insertion sort directly
    if (size <= 16) {
        insertSortVector(arr, 0, size - 1);
        return arr;
    }
    
    // Step 1: Create pairs of elements
    std::vector<std::pair<int, int> > pairs;
    int extraElement = -1;
    
    for (int i = 0; i < size - 1; i += 2) {
        int a = arr[i];
        int b = arr[i + 1];
        
        // Ensure larger element is first in each pair
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }
    
    // Handle odd number of elements
    if (size % 2 != 0)
        extraElement = arr[size - 1];
    
    // Step 2: Sort the pairs by their first element
    mergePairsVector(pairs);
    
    // Step 3: Extract sorted values
    std::vector<int> mainChain;
    std::vector<int> pendingElements;
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pendingElements.push_back(pairs[i].second);
    }
    
    // Step 4: Insert the pending elements using binary search
    // First pending element is always inserted at position 0
    std::vector<int> result;
    result.push_back(pendingElements[0]);
    result.insert(result.end(), mainChain.begin(), mainChain.end());
    
    // Get insertion sequence using Jacobsthal numbers
    std::vector<int> jacobsthal = generateJacobsthalSequence(32);
    std::vector<int> insertionOrder;
    
    for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] < static_cast<int>(pendingElements.size()); ++i) {
        insertionOrder.push_back(jacobsthal[i]);
        
        // Fill in the gaps between Jacobsthal numbers
        for (int j = jacobsthal[i] - 1; j > jacobsthal[i-1]; --j) {
            if (j < static_cast<int>(pendingElements.size()))
                insertionOrder.push_back(j);
        }
    }
    
    // Insert remaining elements
    for (size_t i = 1; i < pendingElements.size(); ++i) {
        int index = (i < insertionOrder.size()) ? insertionOrder[i-1] : i;
        
        if (index >= static_cast<int>(pendingElements.size()))
            index = i;
            
        int value = pendingElements[index];
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), value);
        result.insert(pos, value);
    }
    
    // Insert extra element if exists
    if (extraElement != -1) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), extraElement);
        result.insert(pos, extraElement);
    }
    
    return result;
}

void PmergeMe::insertSortVector(std::vector<int>& arr, int begin, int end) {
    for (int i = begin + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= begin && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

void PmergeMe::mergePairsVector(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
        return;
        
    if (pairs.size() <= 8) {
        // Use insertion sort for small arrays
        for (size_t i = 1; i < pairs.size(); ++i) {
            std::pair<int, int> key = pairs[i];
            int j = i - 1;
            
            while (j >= 0 && pairs[j].first > key.first) {
                pairs[j + 1] = pairs[j];
                j--;
            }
            
            pairs[j + 1] = key;
        }
        return;
    }
    
    // Split and recursively sort
    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
    
    mergePairsVector(left);
    mergePairsVector(right);
    
    // Merge sorted halves
    pairs.clear();
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first)
            pairs.push_back(left[i++]);
        else
            pairs.push_back(right[j++]);
    }
    
    while (i < left.size())
        pairs.push_back(left[i++]);
        
    while (j < right.size())
        pairs.push_back(right[j++]);
}

// LIST IMPLEMENTATION

std::list<int> PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    int size = arr.size();
    
    // Base case
    if (size <= 1)
        return arr;
    
    // For small arrays, use insertion sort
    if (size <= 16) {
        std::list<int> result;
        for (std::list<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
            insertElementList(result, *it);
        }
        return result;
    }
    
    // Step 1: Create pairs
    std::list<std::pair<int, int> > pairs;
    int extraElement = -1;
    
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end()) {
        int a = *it++;
        
        if (it != arr.end()) {
            int b = *it++;
            
            if (a < b)
                pairs.push_back(std::make_pair(b, a));
            else
                pairs.push_back(std::make_pair(a, b));
        } else {
            extraElement = a;
        }
    }
    
    // Step 2: Sort pairs by first element (recursively)
    std::list<std::pair<int, int> > sortedPairs;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        bool inserted = false;
        for (std::list<std::pair<int, int> >::iterator sortedIt = sortedPairs.begin(); sortedIt != sortedPairs.end(); ++sortedIt) {
            if (it->first < sortedIt->first) {
                sortedPairs.insert(sortedIt, *it);
                inserted = true;
                break;
            }
        }
        if (!inserted)
            sortedPairs.push_back(*it);
    }
    
    // Step 3: Create main chain and pending elements
    std::list<int> mainChain;
    std::list<int> pendingElements;
    
    for (std::list<std::pair<int, int> >::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
        mainChain.push_back(it->first);
        pendingElements.push_back(it->second);
    }
    
    // Step 4: Insert pending elements using binary search
    std::list<int> result;
    
    // First pending element is always inserted at the beginning
    if (!pendingElements.empty()) {
        result.push_back(pendingElements.front());
        pendingElements.pop_front();
    }
    
    // Insert all elements from main chain
    result.insert(result.end(), mainChain.begin(), mainChain.end());
    
    // Generate Jacobsthal sequence for insertion order
    std::vector<int> jacobsthal = generateJacobsthalSequence(32);
    std::vector<int> insertionOrder;
    
    for (size_t i = 1; i < jacobsthal.size() && jacobsthal[i] < static_cast<int>(pendingElements.size()); ++i) {
        insertionOrder.push_back(jacobsthal[i]);
        
        for (int j = jacobsthal[i] - 1; j > jacobsthal[i-1]; --j) {
            if (j < static_cast<int>(pendingElements.size()))
                insertionOrder.push_back(j);
        }
    }
    
    // Insert remaining elements
    int pendingIndex = 0;
    for (std::list<int>::iterator it = pendingElements.begin(); it != pendingElements.end(); ++it, ++pendingIndex) {
        int index = pendingIndex;
        if (pendingIndex < static_cast<int>(insertionOrder.size()))
            index = insertionOrder[pendingIndex];
            
        if (index >= static_cast<int>(pendingElements.size()))
            index = pendingIndex;
            
        std::list<int>::iterator pendingIt = pendingElements.begin();
        std::advance(pendingIt, index);
        insertElementList(result, *pendingIt);
    }
    
    // Insert extra element if exists
    if (extraElement != -1) {
        insertElementList(result, extraElement);
    }
    
    return result;
}

void PmergeMe::insertElementList(std::list<int>& arr, int value) {
    if (arr.empty() || value <= arr.front()) {
        arr.push_front(value);
        return;
    }
    
    if (value >= arr.back()) {
        arr.push_back(value);
        return;
    }
    
    // Find position for insertion
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        if (value <= *it) {
            arr.insert(it, value);
            return;
        }
    }
}

void PmergeMe::displayResults(std::vector<int> original_vec) {
    // Display before sorting
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = original_vec.begin(); it != original_vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Display after sorting
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Display time for vector
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << _vectorTime << " us" << std::endl;
    
    // Display time for list
    std::cout << "Time to process a range of " << _list.size() 
              << " elements with std::list : " << std::fixed << std::setprecision(5) 
              << _listTime << " us" << std::endl;
}

const std::vector<int>& PmergeMe::getVector() const {
    return _vector;
}

const std::list<int>& PmergeMe::getList() const {
    return _list;
}

double PmergeMe::getVectorTime() const {
    return _vectorTime;
}

double PmergeMe::getListTime() const {
    return _listTime;
}
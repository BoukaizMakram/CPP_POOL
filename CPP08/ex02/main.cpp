#include "MutantStack.hpp"
#include <list>
#include <iostream>

template <typename T>
void printStack(MutantStack<T>& stack) {
    for (typename MutantStack<T>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

template <typename T>
void printList(std::list<T>& lst) {
    for (typename std::list<T>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;
    
    int values[] = {3, 5, 737, 0};
    for (int i = 0; i < 4; ++i) mstack.push(values[i]);
    
    std::cout << "MutantStack contents:" << std::endl;
    printStack(mstack);
    
    std::stack<int> s(mstack);
    
    std::cout << "----------------------------" << std::endl;
    
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "Last element: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "List size after pop: " << list.size() << std::endl;
    
    for (int i = 0; i < 4; ++i) list.push_back(values[i]);
    
    std::cout << "List contents:" << std::endl;
    printList(list);
    
    return 0;
}
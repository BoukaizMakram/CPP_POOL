#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <deque>


template <typename T, typename Container = std::deque<T> > 
class MutantStack : public std::stack <T, Container>
{
    public:
        using std::stack<T>::c;
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack& others) {*this = others;}
        MutantStack&    operator=(const MutantStack& others) {
            std::stack< T, Container >::operator=(others);
            return *this;
        }
        typedef typename Container::iterator    iterator;
        iterator    begin() { return c.begin(); }
        iterator    end() { return c.end(); }
};
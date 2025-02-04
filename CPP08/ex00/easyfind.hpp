#pragma once
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
    {
        if (*it == value)
            return it;
    }
    throw std::runtime_error("Value not found in container");
}

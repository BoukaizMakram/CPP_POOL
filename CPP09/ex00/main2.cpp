#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, int> map;
    map["1"] = 1;
    map["3"] = 3;
    map["2"] = 2;
    map["6"] = 6;
    map["4"] = 4;
    map["5"] = 5;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << "map[" << it->first << "] = " << it->second << std::endl;
    }
    return (0);
}
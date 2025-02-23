#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();

        static void evaluate(const std::string& expression);
};

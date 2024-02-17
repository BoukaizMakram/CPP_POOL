#include <iostream>

int main()
{
	std::string originalString = "HI THIS IS BRAIN";
	std::string *stringPTR = &originalString;
	std::string &stringREF = originalString;

	std::cout << "\nMemory Addresses of the String:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Original String:   " << &originalString << std::endl;
	std::cout << "String Pointer:    " << stringPTR << std::endl;
	std::cout << "String Reference:  " << &stringREF << std::endl;

	std::cout << "\nValues of the String:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Via Original String:  " << originalString << std::endl;
	std::cout << "Via String Pointer:   " << *stringPTR << std::endl;
	std::cout << "Via String Reference: " << stringREF << std::endl;

	std::cout << std::endl;
	return 0;
}

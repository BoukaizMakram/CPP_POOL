#include <iostream>

int main()
{
	std::string originalString = "HI THIS IS BRAIN";
	std::string *stringPtr = &originalString;
	std::string &stringRef = originalString;

	std::cout << "\nMemory Addresses of the String:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Original String:   " << &originalString << std::endl;
	std::cout << "String Pointer:    " << stringPtr << std::endl;
	std::cout << "String Reference:  " << &stringRef << std::endl;

	std::cout << "\nValues of the String:" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Via Original String:  " << originalString << std::endl;
	std::cout << "Via String Pointer:   " << *stringPtr << std::endl;
	std::cout << "Via String Reference: " << stringRef << std::endl;

	std::cout << std::endl;
	return 0;
}

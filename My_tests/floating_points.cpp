#include <iostream>
#include <iomanip>

int main()
{
	float x = 0.7f;
	float y = 0.6f;
	float z = x + y;

	/*the default precision used when printing floating-point 
	numbers in C++. By default, std::cout uses a limited number of 
	digits to represent floating-point numbers, and it rounds the 
	value for display. If you want to see more digits and get a more 
	accurate representation of the floating-point number, you can use 
	std::setprecision*/

	std::cout << std::setprecision(9) << z << std::endl;  	 // Set precision to 9 digits

	/*Keep in mind that even though you can see more digits, 
	the internal representation of the floating-point number 
	in the computer might still have some small errors due to 
	the limitations of representing real numbers in a finite 
	amount of memory.*/

	return (0);
}
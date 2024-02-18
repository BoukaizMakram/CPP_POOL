#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out;

	out.open("text");
	if (out.is_open())
	{
		out << "Hello world";
		exit(0);
	}
	return (0);
}
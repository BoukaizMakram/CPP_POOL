#include <iostream>
#include <fstream>

int	find_and_replace(std::string in_file_name, std::string s1, std::string s2)
{
	std::string		line;
	std::ifstream	in_file(in_file_name);
	std::ofstream	out_file(in_file_name + ".replace");

	if (!in_file.is_open() || !out_file.is_open()) 
	{
    	std::cerr << "Error opening files." << std::endl;
    	return (0);
	}
	else
	{
		std::cout << "The file \"" 
		<< in_file_name << ".replace\" has been successfully created." << std::endl;
		while (getline(in_file, line))
		{
			size_t pos = 0;
			while (line.find(s1, pos) != std::string::npos)
			{
				out_file << line.substr(pos, line.find(s1, pos) - pos);
				out_file << s2;
				pos = line.find(s1, pos) + s1.length();
			}
			out_file << line.substr(pos) << std::endl;
		}
		std::cout << "The substitution of \"" << s1 
		<< "\" with \"" << s2 << "\" has been performed in the file \"" 
		<< in_file_name << ".replace\"." << std::endl;
	}
	in_file.close();
	out_file.close();
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Enter three parameters: FileName, s1, s2." << std::endl
		<< "The program replaces every occurrence of s1 with s2 in the specified file." 
		<< std::endl;
		return (1);
	}
	if (!find_and_replace(av[1], av[2], av[3]))
		return (1);
	return (0);
}

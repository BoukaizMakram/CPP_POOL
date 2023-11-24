#include <iostream>
#include <fstream>

void	find_and_replace(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::string		filename2 = filename + ".replace";
	std::ifstream 	input_file(filename.c_str());
	std::ofstream	output_file(filename2.c_str());
	std::string		line;
	size_t			pos = 0;

	if(!input_file.is_open() || !output_file.is_open())
	{
		std::cerr << "Error with opening input file: " << filename << " or creating output file: " << filename + ".replace" << std::endl;
		return ;
	}

	while (getline(input_file, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos = s2.length();
		}
		output_file << line << std::endl;
	}
	input_file.close();
	output_file.close();
	std::cout << "File replacement completed. Check " << filename << ".replace" << std::endl;
}

int	main(int ac, char *av[])
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (ac != 4)
	{
		std::cerr << "program takes three parameters in the following order: a filename and two strings, s1 and s2." << std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	find_and_replace(filename, s1, s2);
	return (0);
}

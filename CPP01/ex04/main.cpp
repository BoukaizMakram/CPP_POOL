#include <iostream>
#include <fstream>
#include <string>

void replaceAndWriteToFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open the input file
    std::ifstream inputFile(filename);

    // Check if the input file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return;
    }

    // Create the output file with .replace extension
    std::ofstream outputFile(filename + ".replace");

    // Check if the output file is open
    if (!outputFile.is_open()) {
        std::cerr << "Error creating output file." << std::endl;
        return;
    }

    // Process each line of the input file
    std::string line;
    while (getline(inputFile, line)) {
        // Replace occurrences of s1 with s2 in the current line
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }

        // Write the modified line to the output file
        outputFile << line << std::endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "File replacement completed. Check " << filename << ".replace" << std::endl;
}

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    // Perform replacement and write to a new file
    replaceAndWriteToFile(filename, s1, s2);

    return 0;
}

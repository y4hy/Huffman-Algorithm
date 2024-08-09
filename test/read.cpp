#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Specify the file name
    std::string filename = "output.txt";

    // Create an output file stream (ofstream) object
    std::ofstream file;

    // Open the file in append mode (std::ios::app) to add new content without overwriting
    file.open(filename, std::ios::app);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Write some strings to the file
    file << "This is the first line.\n";
    file << "This is the second line.\n";
    file << "C++ file handling example.\n";

    // Close the file
    file.close();

    std::cout << "Strings written to file successfully." << std::endl;

    return 0;
}

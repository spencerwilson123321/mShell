#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <unistd.h>

std::vector<std::string> tokenize(std::string line) {
    std::vector<std::string> tokens;
    std::stringstream stream(line);
    std::string token; 
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main(int argc, char** argv) {
    std::string line;
    int status;
    while (true) {
        
        // Read line from standard input.
        std::cout << "$ ";
        std::getline(std::cin, line);

        // Tokenize
        auto args = tokenize(line);

        // Check if the command is a builtin
        if (args[0] == "cd" && args.size() > 1) {
            chdir(args[1].c_str());
        
        // External program
        } else  { 
            std::flush(std::cout);
            status = std::system(line.c_str());
        }
    }
    return 0;
}

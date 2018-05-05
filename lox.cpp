#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void run_file(const std::string &path) {
    // Open the file at path and read it line by line
    std::ifstream source_file {path};
    std::string source_code, line;
    while (std::getline(source_file, line)) {
        source_code.append(line);
    } 
    std::cout << source_code << std::endl;
}

void run(const std::string &line) {
    // Split the line of code into tokens based on whitespace for now
    std::stringstream ss {line};
    std::vector<std::string> tokens;
    std::string token;
    while (ss >> token) {
        tokens.emplace_back(token);
    }
    for (auto token: tokens) {
        std::cout << token << std::endl;
    }
}

// REPL - read code entered by user line by line,
// executing & printing results of each
void run_prompt() {
    try {
        while (true) {
            std::cout << "> ";
            std::string line;
            std::getline(std::cin, line);
            run(line);
        }
    } catch(const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        std::cout << "Usage: lox [script]" << std::endl;
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        // Source file provided - run the script
        run_file(argv[1]);
    } else {
        run_prompt();
    }
}

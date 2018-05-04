#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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
    // Split the line of code into tokens for now
    std::string copy_line {line};
    std::vector<std::string> tokens;
    for (size_t i = 0; !copy_line.empty(); ) {
        size_t next_whitespace = copy_line.find(" ");
        if (next_whitespace == std::string::npos) break;
        std::string token = copy_line.substr(i, next_whitespace);
        // 'Remove' the token we just read
        copy_line = copy_line.substr(i);
        i = next_whitespace + 1;
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

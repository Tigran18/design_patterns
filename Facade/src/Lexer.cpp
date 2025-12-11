#include "../include/Lexer.hpp"
#include <iostream>

std::vector<std::string> Lexer::tokenize(const std::string& filename) {
    std::cout << "[Lexer] Tokenizing: " << filename << "\n";
    return {"int", "a", "=", "5", ";"};
}

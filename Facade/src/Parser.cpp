#include "../include/Parser.hpp"
#include <iostream>

std::string Parser::parse(const std::vector<std::string>& tokens) {
    std::cout << "[Parser] Parsing " << tokens.size() << " tokens\n";
    return "(AST: a = 5)";
}

#include "../include/CodeGen.hpp"
#include <iostream>

void CodeGen::emit(const std::string& optimizedAst) {
    std::cout << "[CodeGen] Emitting code for " << optimizedAst << "\n";
}

#pragma once
#include <string>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Optimizer.hpp"
#include "CodeGen.hpp"

class CompilerFacade {
public:
    void compile(const std::string& filename);

private:
    Lexer lexer;
    Parser parser;
    Optimizer optimizer;
    CodeGen codegen;
};
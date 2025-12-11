#include "../include/Facade.hpp"
#include <iostream>

void CompilerFacade::compile(const std::string& filename) {
    std::cout << "Compiler Facade start\n";

    auto tokens = lexer.tokenize(filename);
    auto ast = parser.parse(tokens);
    auto optAst = optimizer.optimize(ast);
    codegen.emit(optAst);

    std::cout << "Compiler Facade end\n";
}

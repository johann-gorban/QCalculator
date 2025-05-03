#include "calculator.hpp"
#include "lexer.hpp"

#include <iostream>

int main() {
    auto calculator = new Calculator();
    auto lexer = new Lexer();

    std::vector<token_ptr> tokens = lexer->tokenize("2 2 +");
    std::cout << calculator->calculate(tokens) << std::endl;
    return 0;
}
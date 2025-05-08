#include <iostream>

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"
#include "tokenization/manager.hpp"

class TokenPrinter {
public:
    static void visit(const token_ptr token) noexcept {
        TokenManager manager;
        auto type = token->get_type();
        std::cout << "Token: " << manager.get_type_name(type) << " " << token->get_data() << std::endl;
    }
};


int main() {
    Tokenizer tokenizer;
    std::vector<token_ptr> tokens;
    // Test 1
    {
        tokens = tokenizer.tokenize("+2+3+4+5");
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }

    // Test 2
    {
        tokens = tokenizer.tokenize("2*2-2+2");
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }

    // Test 3
    {
        tokens = tokenizer.tokenize("254*22/2");
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }

    // Test 4
    {
        tokens = tokenizer.tokenize("254(2+3+4)");
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }

    // Test 5
    {
        tokens = tokenizer.tokenize("254(2.4+3+4)");
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }

    return 0;
}
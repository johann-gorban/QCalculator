#include <iostream>

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"
#include "token_manager.hpp"

#include "parsing/parser.hpp"
#include "parsing/extended_tokens.hpp"

class TokenPrinter {
public:
    static void visit(const token_ptr token) noexcept {
        TokenManager manager;
        auto type = token->get_type();
        std::cout << "Token: " << manager.get_type_name(type) << " " << token->get_data();

        if (type == TokenType::Operator) {
            auto etoken = std::static_pointer_cast<OperatorToken>(token);
            if (etoken) {
                std::cout << " " << int(etoken->get_arity()) << " " << etoken->get_precedance();
            }
            else {
                std::cerr << " Cast failed! Actual type: " << typeid(*token).name() << std::endl;
            }
        }

        std::cout << std::endl;
    }
};

class Tester {
private:
    static long unsigned int test_number;
public:
    static void test(const std::string &expression_to_test) {
        static Tokenizer tokenizer;
        static Parser parser;

        std::cout << "Test #" << test_number++ << std::endl;

        std::vector<token_ptr> tokens = tokenizer.tokenize(expression_to_test);
        std::vector<token_ptr> extended_tokens = parser.parse(tokens);
        
        for (const auto &token : tokens) {
            TokenPrinter::visit(token);
        }
        std::cout << std::endl;
    }
};

long unsigned int Tester::test_number = 1;


int main() {
    
    // Test 1
    {
        Tester::test("+2+3+4+");
    }

    // Test 2
    {
        Tester::test("2*2-2+2");
    }

    // Test 3
    {
        Tester::test("254*22/2");
    }

    // Test 4
    {
        Tester::test("254(2+3+4)");
    }

    // Test 5
    {
        Tester::test("123.3*34");
    }

    // Test 6
    {
        Tester::test("sin(42)");
    }

    // Test 7
    {
        Tester::test("sin(24/4)*2");
    }

    // Test 8
    {
        try {
            Tester::test("cos()");
        }
        catch (std::exception) {
            std::cout << "Right!" << std::endl;
        }
    }

    // Test 9
    {
        Tester::test("sin(24,234)*2");
    }

    return 0;
}
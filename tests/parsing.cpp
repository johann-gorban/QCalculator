#include <iostream>

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"
#include "token_manager.hpp"

#include "parsing/parser.hpp"
#include "parsing/extended_tokens.hpp"

class ExtendedTokenPrinter {
public:
    static void visit(const token_ptr token) noexcept {
        TokenManager manager;
        auto type = token->get_type();
        std::cout << "Token: " << manager.get_type_name(type) << " " << token->get_data();

        if (type == TokenType::Operator) {
            auto etoken = std::static_pointer_cast<OperatorToken>(token);
            if (etoken) {
                std::cout << " | Arity:" << int(etoken->get_arity()) << " | Precedance: " << etoken->get_precedance();
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

        try {
            std::vector<token_ptr> tokens = tokenizer.tokenize(expression_to_test);
            std::vector<token_ptr> extended_tokens = parser.parse(tokens);
            
            for (const auto &token : extended_tokens) {
                ExtendedTokenPrinter::visit(token);
            }
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
};

long unsigned int Tester::test_number = 1;


int main() {
    // Test 1
    {
        Tester::test("2+3*4");
    }
    // Test 2
    {
        Tester::test("(2+3)*4");
    }
    // Test 3
    {
        Tester::test(")34");
    }
    // Test 4
    {
        Tester::test("2++3");
    }
    // Test 5
    {
        Tester::test("sin(30)+45");
    }
    // Test 6
    {
        Tester::test("2*3+");
    }
    // Test 7
    {
        Tester::test("(2+3");
    }
    // Test 8
    {
        Tester::test("23+4");
    }
    // Test 9
    {
        Tester::test("2+3*4/5");
    }
    // Test 10
    {
        Tester::test("sin(cos(30))");
    }
    // Test 11
    {
        Tester::test("2*3+4*5");
    }
    // Test 12
    {
        Tester::test("+2+3");
    }
    // Test 13
    {
        Tester::test("2..3+4");
    }
    // Test 14
    {
        Tester::test("2+3*");
    }
    // Test 15
    {
        Tester::test("sin30");
    }
    // Test 16
    {
        Tester::test("2+(3*4))");
    }
    // Test 17
    {
        Tester::test("2+3*4/");
    }
    // Test 18
    {
        Tester::test("(2+3)*(4-5)");
    }
    // Test 19
    {
        Tester::test("2+3*4-5/6");
    }
    // Test 20
    {
        Tester::test("sin(cos(tan(45)))");
    }

    return 0;
}
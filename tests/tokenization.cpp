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

class Tester {
private:
    static long unsigned int test_number;
public:
    static void test(const std::string &expression_to_test) {
        static Tokenizer tokenizer;
        std::cout << "Test #" << test_number++ << std::endl;
        std::vector<token_ptr> tokens = tokenizer.tokenize(expression_to_test);
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
        Tester::test("+2+3+4+5");
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
        Tester::test("254(2.43643746+3+4)");
    }

    return 0;
}
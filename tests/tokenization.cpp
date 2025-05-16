#include <iostream>

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"
#include "token_manager.hpp"

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
        try {
            std::vector<token_ptr> tokens = tokenizer.tokenize(expression_to_test);
            for (const auto &token : tokens) {
                TokenPrinter::visit(token);
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
        Tester::test("+2+3+4+5");
    }
    // Test 2
    {
        Tester::test("2+*2+343++++++sin()");
    }
    // Test 3
    {
        Tester::test("2.2.3+234");
    }
    // Test 4
    {
        Tester::test("s1n()");
    }
    // Test 5
    {
        Tester::test("123.456");
    }
    // Test 6
    {
        Tester::test("1.2.3.4");
    }
    // Test 7
    {
        Tester::test("sin(cos(tan(pi)))");
    }
    // Test 8
    {
        Tester::test("x+y*z^2");
    }
    // Test 9
    {
        Tester::test("1.2+3.4");
    }
    // Test 10
    {
        Tester::test("++--+-");
    }
    // Test 11
    {
        Tester::test("3.14*2.71");
    }
    // Test 12
    {
        Tester::test("var_1+var_2");
    }
    // Test 13
    {
        Tester::test("1..2");
    }
    // Test 14
    {
        Tester::test("sqrt(-1)");
    }
    // Test 15
    {
        Tester::test("123abc");
    }
    // Test 16
    {
        Tester::test("(a+b)*(c-d)");
    }
    // Test 17
    {
        Tester::test("1.2+3.4");
    }
    // Test 18
    {
        Tester::test("sinh(cosh(tanh(x)))");
    }
    // Test 19
    {
        Tester::test("1.2.3");
    }
    // Test 20
    {
        Tester::test("+-*/^()");
    }

    return 0;
}
#include "facade.hpp"

#include <iostream>
#include <string>

class Tester {
private:
    static unsigned int test_counter;
public:
    static void test(const std::string &expression) {
        std::cout << "Test #" << test_counter++ << std::endl;
        std::cout << Facade::calculate(expression) << std::endl;
    }
};

unsigned int Tester::test_counter = 1;

int main() {
    {
        Tester::test("15+15");
    }

    {
        Tester::test("2^2-2");
    }

    {
        Tester::test("(2+2)*2");
    }

    {
        Tester::test("2(2+2)");
    }
    
    {
        Tester::test("0");
    }

    {
        Tester::test("2/0");
    }

    {
        Tester::test("-1+3");
    }

    {
        Tester::test("");
    }

    return 0;
}
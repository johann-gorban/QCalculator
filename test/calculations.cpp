#include "facade.hpp"

#include <iostream>
#include <string>

class Tester {
private:
    static unsigned int test_counter;
public:
    static void test(const std::string &expression) {
        static Facade facade;

        std::cout << "Test #" << test_counter++ << std::endl;
        std::cout << facade.calculate(expression) << std::endl;
    }
};

unsigned int Tester::test_counter = 1;

int main() {
    // Test 1 - Простое сложение
    {
        Tester::test("2+3");
    }
    // Test 2 - Приоритет операторов
    {
        Tester::test("2+3*4");
    }
    // Test 3 - Со скобками
    {
        Tester::test("(2+3)*4");
    }
    // Test 4 - Унарный минус
    {
        Tester::test("-2+3");
    }
    // Test 5 - Множественные операторы
    {
        Tester::test("2+3*4-5");
    }
    // Test 6 - Вложенные скобки
    {
        Tester::test("(2+(3*4))-5");
    }
    // Test 7 - Функция с одним аргументом
    {
        Tester::test("sin(30)");
    }
    // Test 8 - Функция с выражением
    {
        Tester::test("sin(30+45)");
    }
    // Test 9 - Несколько функций
    {
        Tester::test("sin(30)+cos(45)");
    }
    // Test 10 - Комплексное выражение
    {
        Tester::test("2+sin(30)*3");
    }
    // Test 11 - Много операций
    {
        Tester::test("2+3*4-5/6");
    }
    // Test 12 - Все базовые операторы
    {
        Tester::test("2+3*4/5-6");
    }
    // Test 13 - Глубоко вложенные скобки
    {
        Tester::test("((2+3)*4)-5");
    }
    // Test 14 - Множественное умножение
    {
        Tester::test("2*3*4");
    }
    // Test 15 - Смешанные операции
    {
        Tester::test("2+3*4/5-6");
    }
    // Test 16 - Функция от функции
    {
        Tester::test("sin(cos(45))");
    }
    // Test 17 - Тройная вложенность
    {
        Tester::test("sin(cos(tan(45)))");
    }
    // Test 18 - Комбинация всего
    {
        Tester::test("(2+sin(30))*3-4/5");
    }
    // Test 19 - Длинное выражение
    {
        Tester::test("1+2*3-4/5+6*7-8");
    }
    // Test 20 - Максимально комплексное
    {
        Tester::test("sin(30)*(2+cos(45))-tan(60)/4");
    }
    // Test 21
    {
        Tester::test("sin(75)*(3-cos(30))/-2+cos(45)");
    }
    // Test 22
    {
        Tester::test("tan(60)*2+tan(30)-1/4");
    }
    // Test 23
    {
        Tester::test("cos(45)-3*sin(45)+1/5*sqrt(2)");
    }
    // Test 24
    {
        Tester::test("sin(90)/(1+cos(0))");
    }
    // Test 25
    {
        Tester::test("(3*(2+(4-5)))*(sin((7+8)/9)-10/11)+12*13-14");
    }    

    return 0;
}
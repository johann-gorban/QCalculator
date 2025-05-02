#include "commands.hpp"

#include <cmath>

NumberCommand::NumberCommand(double value) : value(value) {}

void NumberCommand::execute(std::stack<double> &computation_stack) {
    computation_stack.push(this->value);
}


void AdditionCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a + b);
}

void SubstractCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a - b);
}

void MultiplyCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a * b);
}

void DivisionCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a / b);
}

void PowerCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(std::pow(a, b));
}

void MinusCommand::execute(std::stack<double> &computation_stack) {
    double neg_a = -1 * computation_stack.top();
    computation_stack.pop();

    computation_stack.push(neg_a);
}
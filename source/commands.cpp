#include "commands.hpp"

#include <stdexcept>
#include <cmath>


void NumberCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double number_data = std::stod(token->get_data());
    computation_stack.push(number_data);
}


void AdditionCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a + b);
}

void SubstractCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a - b);
}

void MultiplyCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a * b);
}

void DivisionCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    computation_stack.push(a / b);
}

void PowerCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double b = computation_stack.top();
    computation_stack.pop();

    double a = computation_stack.top();
    computation_stack.pop();

    // computation_stack.push(std::pow(a, b));
    computation_stack.push(std::pow(a, b));
}

void MinusCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double neg_a = -1 * computation_stack.top();
    computation_stack.pop();

    computation_stack.push(neg_a);
}
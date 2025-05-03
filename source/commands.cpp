#include "commands.hpp"

#include <stdexcept>


void NumberCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    auto number_token = std::static_pointer_cast<Number>(token);
    if (!number_token) {
        throw std::runtime_error("Computation error: expected a number");
    }

    computation_stack.push(number_token->get_value());
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
    computation_stack.push(a + b);
}

void MinusCommand::execute(std::stack<double> &computation_stack, const token_ptr &token) {
    double neg_a = -1 * computation_stack.top();
    computation_stack.pop();

    computation_stack.push(neg_a);
}
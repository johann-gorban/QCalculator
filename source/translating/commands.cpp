#include "translating/commands.hpp"

#include <stdexcept>
#include <cmath>


Command::Command(token_ptr &token) : token(token) {
}

void Command::set_token(token_ptr &token) {
    this->token = token;
}

const token_ptr &Command::get_token() const {
    return this->token;
}

NumberCommand::NumberCommand(token_ptr &token) : Command(token) {
}

void NumberCommand::set_token(token_ptr &token) {
    // It smells like decorators are needed
    // <before>
    Command::set_token(token);
    // <after>
}

void NumberCommand::execute(std::stack<double> &computation_stack) {
    const token_ptr &current_token = this->get_token();
    double number_data = std::stod(current_token->get_data());
    computation_stack.push(number_data);
}

AdditionCommand::AdditionCommand(token_ptr &token) : Command(token) {
}

void AdditionCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void AdditionCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();
    double a = computation_stack.top();
    computation_stack.pop();
    computation_stack.push(a + b);
}

SubstractCommand::SubstractCommand(token_ptr &token) : Command(token) {
}

void SubstractCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void SubstractCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();
    double a = computation_stack.top();
    computation_stack.pop();
    computation_stack.push(a - b);
}

MultiplyCommand::MultiplyCommand(token_ptr &token) : Command(token) {
}

void MultiplyCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void MultiplyCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();
    double a = computation_stack.top();
    computation_stack.pop();
    computation_stack.push(a * b);
}

DivisionCommand::DivisionCommand(token_ptr &token) : Command(token) {
}

void DivisionCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void DivisionCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();
    double a = computation_stack.top();
    computation_stack.pop();
    computation_stack.push(a / b);
}

PowerCommand::PowerCommand(token_ptr &token) : Command(token) {
}

void PowerCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void PowerCommand::execute(std::stack<double> &computation_stack) {
    double b = computation_stack.top();
    computation_stack.pop();
    double a = computation_stack.top();
    computation_stack.pop();
    computation_stack.push(std::pow(a, b));
}

MinusCommand::MinusCommand(token_ptr &token) : Command(token) {
}

void MinusCommand::set_token(token_ptr &token) {
    Command::set_token(token);
}

void MinusCommand::execute(std::stack<double> &computation_stack) {
    double neg_a = -1 * computation_stack.top();
    computation_stack.pop();
    computation_stack.push(neg_a);
}
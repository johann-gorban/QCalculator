#pragma once

#include <stack>

#include "tokens.hpp"

class Command;

typedef std::shared_ptr<Command> command_ptr;

class Command {
public:
    virtual void execute(std::stack<double> &computation_stack, const token_ptr &token) = 0;

    virtual ~Command() = default;
};


class NumberCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class AdditionCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class SubstractCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class MultiplyCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class DivisionCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class PowerCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};


class MinusCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack, const token_ptr &token) override;
};

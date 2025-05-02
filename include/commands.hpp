#pragma once

#include <stack>

class Command {
public:
    virtual void execute(std::stack<double> &computation_stack) = 0;

    virtual ~Command() = default;
};


class NumberCommand : public Command {
private:
    double value;
public:
    NumberCommand(double value);

    void execute(std::stack<double> &computation_stack) override;
};


class AdditionCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};


class SubstractCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};


class MultiplyCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};


class DivisionCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};


class PowerCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};


class MinusCommand : public Command {
public:
    void execute(std::stack<double> &computation_stack) override;
};

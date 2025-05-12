#pragma once

#include <stack>

#include "tokens.hpp"

class Command;

typedef std::shared_ptr<Command> command_ptr;

class Command {
private:
    token_ptr token;
public:
    explicit Command(token_ptr &token);

    virtual void execute(std::stack<double> &computation_stack) = 0;

    virtual const token_ptr &get_token() const;
    virtual void set_token(token_ptr &token);

    virtual ~Command() = default;
};

class NumberCommand : public Command {
public:
    explicit NumberCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class AdditionCommand : public Command {
public:
    explicit AdditionCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class SubstractCommand : public Command {
public:
    explicit SubstractCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class MultiplyCommand : public Command {
public:
    explicit MultiplyCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class DivisionCommand : public Command {
public:
    explicit DivisionCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class PowerCommand : public Command {
public:
    explicit PowerCommand(token_ptr &token);
    void set_token(token_ptr &token) override;
    void execute(std::stack<double> &computation_stack) override;
};

class MinusCommand : public Command {
public:
    explicit MinusCommand(token_ptr &token);

    void set_token(token_ptr &token) override;

    void execute(std::stack<double> &computation_stack) override;
};
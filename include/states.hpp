#pragma once

#include <string>
#include <vector>
#include "tokens.hpp"

class TokenizerContext;

class State {
public:
    virtual void handle_char(TokenizerContext &context, char c) = 0;

    virtual void finish_input(TokenizerContext &context) = 0;

    virtual ~State() = default;
};


class StartState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};


class NumberState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};


class IdentifierState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};


class OperatorState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};


class ParanthesisState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};


class CommaState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void finish_input(TokenizerContext &context) override;
};
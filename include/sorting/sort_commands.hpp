#pragma once

#include "parsing/extended_tokens.hpp"

#include <vector>
#include <stack>
#include <memory>

class SortCommand;

typedef std::shared_ptr<SortCommand> sort_command_ptr;

class SortCommand {
public:
    virtual void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) = 0;
    virtual ~SortCommand() = default;
};


class SortOperatorCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortNumberCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortFunctionCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortSeparatorCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortLeftParenthesisCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortRightParenthesisCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};


class SortEndCommand : public SortCommand {
public:
    void execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &output_tokens, const token_ptr &token) override;
};
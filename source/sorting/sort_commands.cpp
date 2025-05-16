#include "sorting/sort_commands.hpp"

#include <stdexcept>

void SortOperatorCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &result_tokens, const token_ptr &token) {
    if (token->get_type() != TokenType::Operator) {
        throw std::runtime_error("SortOperatorCommand: token is not an operator");
    }

    auto op1 = std::static_pointer_cast<OperatorToken>(token);

    while (!token_stack.empty()) {
        token_ptr top_token = token_stack.top();

        if (top_token->get_type() != TokenType::Operator) {
            break;
        }

        auto op2 = std::static_pointer_cast<OperatorToken>(top_token);

        bool higher_precedence = op2->get_precedance() > op1->get_precedance();
        bool equal_precedence_left_associative =
            op2->get_precedance() == op1->get_precedance() &&
            op1->get_associativity() == Associativity::Left;

        if (higher_precedence || equal_precedence_left_associative) {
            result_tokens.push_back(op2);
            token_stack.pop();
        } else {
            break;
        }
    }

    token_stack.push(token);
}


void SortNumberCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &result_tokens, const token_ptr &token) {
    result_tokens.push_back(token);
}


void SortFunctionCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &, const token_ptr &token) {
    token_stack.push(token);
}


void SortSeparatorCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &result_tokens, const token_ptr &token) {
    while (!token_stack.empty()) {
        token_ptr token_in_stack = token_stack.top();

        if (token_in_stack->get_data() == "LEFT_PARENTHESIS") {
            break;
        }

        result_tokens.push_back(token_in_stack);
        token_stack.pop();
    }

    if (token_stack.empty()) {
        throw std::runtime_error("Syntax error: missing parenthesis or function argument separator");
    }
}


void SortLeftParenthesisCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &, const token_ptr &token) {
    token_stack.push(token);
}


void SortRightParenthesisCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &result_tokens, const token_ptr &token) {
    while (!token_stack.empty()) {
        token_ptr token_in_stack = token_stack.top();

        if (token_in_stack->get_data() == "LEFT_PARENTHESIS") {
            break;
        }

        result_tokens.push_back(token_in_stack);
        token_stack.pop();
    }

    if (token_stack.empty()) {
        throw std::runtime_error("Syntax error: missing left parenthesis");
    }

    token_stack.pop();

    if (!token_stack.empty()) {
        token_ptr top_token = token_stack.top();
        if (top_token->get_type() == TokenType::Function) {
            result_tokens.push_back(top_token);
            token_stack.pop();
        }
    }
}


void SortEndCommand::execute(std::stack<token_ptr> &token_stack, std::vector<token_ptr> &result_tokens, const token_ptr &token) {
    while (!token_stack.empty()) {
        token_ptr top_token = token_stack.top();

        if (top_token->get_data() == "LEFT_PARENTHESIS") {
            throw std::runtime_error("Syntax error: missing right parenthesis");
        }

        result_tokens.push_back(top_token);
        token_stack.pop();
    }
}
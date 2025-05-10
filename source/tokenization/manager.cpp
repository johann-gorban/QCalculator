#include "tokenization/manager.hpp"

#include <stdexcept>

TokenManager::TokenManager() {
    // Token types for debugging
    this->tokentype_names[TokenType::Number] = "NUMBER";
    this->tokentype_names[TokenType::Function] = "FUNCTION";
    this->tokentype_names[TokenType::BinaryOperator] = "BINARY_OPERATOR";
    this->tokentype_names[TokenType::UnaryOperator] = "UNARY_OPERATOR";
    this->tokentype_names[TokenType::LeftParenthesis] = "LEFT_PARENTHESIS";
    this->tokentype_names[TokenType::RightParenthesis] = "RIGHT_PARENTHESIS";
    this->tokentype_names[TokenType::Separator] = "SEPARATOR";

    // Operators
    this->available_tokens["-"] = "SUB";
    this->available_tokens["+"] = "ADD";
    this->available_tokens["*"] = "MUL";
    this->available_tokens["/"] = "DIV";
    this->available_tokens["^"] = "POW";

    // Functions
    this->available_tokens["sin"] = "SIN";
    // ...
}

bool TokenManager::is_valid_name(const std::string &name) const noexcept {
    return (this->available_tokens.count(name) == 0) ? false : true;
}

const std::string &TokenManager::get_name(const std::string &name) const {
    if (this->is_valid_name(name)) {
        return this->available_tokens.at(name);
    }
    else {
        throw std::runtime_error("Token error: no tokens with such symbols available");
    }
}

const std::string &TokenManager::get_type_name(TokenType type) const {
    if (this->tokentype_names.count(type) != 0) {
        return this->tokentype_names.at(type);
    }
    else {
        throw std::runtime_error("Token type error: no tokens type with such index");
    }
}
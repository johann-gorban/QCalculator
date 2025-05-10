#include "tokenization/manager.hpp"

#include <stdexcept>

TokenManager::TokenManager() {
    // Token types for debugging
    this->TokenType_names[TokenType::NUMBER] = "NUMBER";
    this->TokenType_names[TokenType::FUNCTION] = "FUNCTION";
    this->TokenType_names[TokenType::BinaryOperator] = "BinaryOperator";
    this->TokenType_names[TokenType::UNARY_OPERATOR] = "UNARY_OPERATOR";
    this->TokenType_names[TokenType::LEFT_PARANTHESIS] = "LEFT_PARANTHESIS";
    this->TokenType_names[TokenType::RIGHT_PARANTHESIS] = "RIGHT_PARANTHESIS";
    this->TokenType_names[TokenType::SEPARATOR] = "SEPARATOR";

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
    if (this->TokenType_names.count(type) != 0) {
        return this->TokenType_names.at(type);
    }
    else {
        throw std::runtime_error("Token type error: no tokens type with such index");
    }
}
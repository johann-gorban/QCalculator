#include "tokenization/manager.hpp"

#include <stdexcept>

TokenManager::TokenManager() {
    // Token types
    this->token_type_names[token_type::NUMBER] = "NUMBER";
    this->token_type_names[token_type::FUNCTION] = "FUNCTION";
    this->token_type_names[token_type::BINARY_OPERATOR] = "BINARY_OPERATOR";
    this->token_type_names[token_type::UNARY_OPERATOR] = "UNARY_OPERATOR";
    this->token_type_names[token_type::LEFT_PARANTHESIS] = "LEFT_PARANTHESIS";
    this->token_type_names[token_type::RIGHT_PARANTHESIS] = "RIGHT_PARANTHESIS";
    this->token_type_names[token_type::SEPARATOR] = "SEPARATOR";

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

bool TokenManager::is_available(const std::string &name) const noexcept {
    return (this->available_tokens.count(name) == 0) ? false : true;
}

const std::string &TokenManager::get_name(const std::string &name) const {
    if (this->is_available(name)) {
        return this->available_tokens.at(name);
    }
    else {
        throw std::runtime_error("Token error: no tokens with such symbols available");
    }
}

const std::string &TokenManager::get_type_name(token_type type) const {
    if (this->token_type_names.count(type) != 0) {
        return this->token_type_names.at(type);
    }
    else {
        throw std::runtime_error("Token type error: no tokens type with such index");
    }
}
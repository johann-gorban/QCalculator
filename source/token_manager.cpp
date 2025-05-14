#include "token_manager.hpp"

#include <stdexcept>
#include <algorithm>

TokenManager::TokenManager() {
    // Token types for debugging
    this->tokentype_names[TokenType::Number] = "NUMBER";
    this->tokentype_names[TokenType::Function] = "FUNCTION";
    this->tokentype_names[TokenType::Operator] = "OPERATOR";
    this->tokentype_names[TokenType::Parenthesis] = "PARENTHESIS";
    this->tokentype_names[TokenType::Separator] = "SEPARATOR";

    this->available_token_names.push_back("-");
    this->available_token_names.push_back("+");
    this->available_token_names.push_back("*");
    this->available_token_names.push_back("/");
    this->available_token_names.push_back("^");

    this->available_token_names.push_back("sin");
}

bool TokenManager::is_valid_name(const std::string &name) const noexcept {
    bool exists = (std::find(
        this->available_token_names.begin(),
        this->available_token_names.end(),
        name
    ) != this->available_token_names.end());

    return exists;
}

const std::string &TokenManager::get_type_name(TokenType type) const {
    if (this->tokentype_names.count(type) != 0) {
        return this->tokentype_names.at(type);
    }
    else {
        throw std::runtime_error("Token type error: no tokens type with such index");
    }
}

unsigned int TokenManager::get_precedance(const std::string &operator_name, Arity operator_arity) const {
    unsigned int precedance = 0;
    if (this->precedance_table.count(operator_name) != 0) {
        const std::unordered_map<Arity, unsigned int> &operator_table = precedance_table.at(operator_name);
        if (operator_table.count(operator_arity) != 0) {
            precedance = operator_table.at(operator_arity);
        }
    }
    else {
        throw std::runtime_error("Token error: token has no precedance");
    }

    return precedance;
}
#pragma once

#include "tokens.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class TokenManager {
private:
    static std::unordered_map<std::string, std::shared_ptr<Operator>> operator_tokens;
    static std::unordered_map<std::string, std::shared_ptr<Function>> function_tokens;
public:
    TokenManager();

    const std::shared_ptr<Token> get_token(const std::string &name) const;

    bool function_has_token(const std::string &name) const;

    bool operator_has_token(char operator_name) const;
};
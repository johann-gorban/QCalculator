#pragma once

#include "tokens.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class TokenManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Operator>> operator_tokens;
    std::unordered_map<std::string, std::shared_ptr<Function>> function_tokens;
public:
    TokenManager();

    const token_ptr get_token(const std::string &name) const;

    bool function_has_token(const std::string &name) const;

    bool operator_has_token(char operator_name) const;
};
#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "tokens.hpp"

class TokenManager {
private:
    std::vector<std::string> available_token_names;
    std::unordered_map<TokenType, std::string> tokentype_names;
public:
    TokenManager();

    bool is_valid_name(const std::string &name) const noexcept;

    const std::string &get_type_name(TokenType) const;
};
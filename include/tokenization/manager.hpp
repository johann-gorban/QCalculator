#pragma once

#include <unordered_map>
#include <string>

#include "tokens.hpp"

class TokenManager {
private:
    std::unordered_map<std::string, std::string> available_tokens;
    std::unordered_map<token_type, std::string> token_type_names;
public:
    TokenManager();

    bool is_available(const std::string &name) const noexcept;

    const std::string &get_name(const std::string &name) const;

    const std::string &get_type_name(token_type) const;
};
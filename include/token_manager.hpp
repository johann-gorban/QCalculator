#pragma once

#include "tokens.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class TokenManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Token>> tokens;
public:
    TokenManager();

    const std::shared_ptr<Token> get_token(const std::string &name) const;

    bool has_token(const std::string &name) const;
};
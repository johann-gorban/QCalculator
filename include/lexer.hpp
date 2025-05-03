#pragma once

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "tokens.hpp"

class Lexer {
private:
    std::unordered_map<std::string, std::shared_ptr<Token>> token_keys;
public:
    Lexer();

    std::vector<token_ptr> tokenize(const std::string &expression);

    ~Lexer() = default;
};
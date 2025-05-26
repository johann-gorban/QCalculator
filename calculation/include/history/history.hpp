#pragma once

#include "tokenization/tokens.hpp"

#include <vector>
#include <string>

class History {
private:
    std::vector<std::string> expressions;
public:
    void save(const std::string &expression) noexcept;

    // Returns empty string if invalid index given
    const std::string get(const std::size_t &index);
};
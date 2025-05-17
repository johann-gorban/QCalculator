#pragma once

#include "tokenization/tokens.hpp"

#include <unordered_map>
#include <vector>
#include <string>

class History {
private:
    std::size_t last_id;
    std::unordered_map<std::size_t, std::vector<token_ptr>> token_table;
    std::unordered_map<std::size_t, std::string> result_table;
public:
    void save_calculation(const std::vector<token_ptr> &tokens, const std::string &result) noexcept;

    const std::vector<token_ptr> get_tokens(const std::size_t id) const;

    const std::string get_result(const std::size_t id) const;
};
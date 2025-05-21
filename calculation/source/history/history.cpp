#include "history/history.hpp"

#include <stdexcept>

void History::save_calculation(const std::vector<token_ptr> &tokens, const std::string &result) noexcept {
    this->last_id++;
    this->token_table[last_id] = tokens;
    this->result_table[last_id] = result;
};

const std::vector<token_ptr> History::get_tokens(const std::size_t id) const {
    if (this->token_table.count(id)) {
        return this->token_table.at(id);
    }
    else {
        throw std::runtime_error("History does not have tokens for expression with ID:" + std::to_string(id));
    }
}

const std::string History::get_result(const std::size_t id) const {
    if (this->result_table.count(id)) {
        return this->result_table.at(id);
    }
    else {
        throw std::runtime_error("History does not have result for expression with ID:" + std::to_string(id));
    }
}
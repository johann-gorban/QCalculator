#include "history/history.hpp"

#include <stdexcept>

void History::save(const std::string &expression) noexcept {
    this->expressions.push_back(expression);
}

const std::string History::get(const std::size_t &index) {
    std::string result = "";
    if (index < this->expressions.size()) {
        result = this->expressions[index];
    }
    return result;
}
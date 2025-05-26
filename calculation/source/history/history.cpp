#include "history/history.hpp"

#include <stdexcept>

void History::save(const std::string &expression) noexcept {
    this->expressions.push_back(expression);
    this->current_index = this->expressions.size() - 1;
}

const std::string History::get_prev() {
    if (this->current_index > 0) {
        this->current_index--;
    }
    return this->expressions[this->current_index]; 
}

const std::string History::get_next() {
    if (this->current_index < this->expressions.size() - 1) {
        this->current_index++;
    }
    return this->expressions[this->current_index]; 
}
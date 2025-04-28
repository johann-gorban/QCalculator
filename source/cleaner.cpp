#include "cleaner.hpp"

void Cleaner::clean_expression(std::string &expression) {
    std::string expression_copy;
    // expression_copy.reserve(expression.size());

    for (auto ch : expression) {
        if (!dirty_chars.contains(ch)) {
            expression_copy += ch;
        }
        // If C++20 is not allowed
        // if (dirty_chars.find(ch) == dirty_chars.end()) {
        //     expression += ch;
        // }
    }

    expression = expression_copy;
}

Cleaner::Cleaner(std::unordered_set<char> chars_to_remove) : dirty_chars(std::move(chars_to_remove)) {};

void Cleaner::add_char_to_remove(char ch) {
    this->dirty_chars.insert(ch);
}

void Cleaner::add_char_to_remove(std::unordered_set<char> &chars) {
    this->dirty_chars.insert(chars.begin(), chars.end());
}
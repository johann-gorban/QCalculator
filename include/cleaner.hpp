#pragma once

#include <string>
#include <unordered_set>

class Cleaner {
private:
    std::unordered_set<char> dirty_chars;
public:
    explicit Cleaner(std::unordered_set<char> chars_to_remove);

    void clean_expression(std::string &expression);

    void add_char_to_remove(char ch);

    void add_char_to_remove(std::unordered_set<char> &chars);

    ~Cleaner() = default;
};
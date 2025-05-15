#pragma once

#include "tokenization/tokens.hpp"

#include <vector>

class Sorter {
public:
    std::vector<token_ptr> rpn_sort(const std::vector<token_ptr> &tokens);
};
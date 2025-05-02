#pragma once

#include <vector>
#include <memory>

#include "tokens.hpp"


class Calculator {
public:
    double calculate(std::vector<std::shared_ptr<Token>> tokens_rpn);
};
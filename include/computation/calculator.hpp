#pragma once

#include <vector>
#include <memory>

#include "translating/translator.hpp"


class Calculator {
public:
    double calculate(const std::vector<command_ptr> &commands);
};
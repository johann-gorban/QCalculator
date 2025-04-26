#pragma once

#include <string>

class Calculator {
private:
    std::string to_postfix(const std::string &) const;

    std::string get_num_from_str(const std::string &, std::size_t &) const noexcept;
public:
    std::string calculate(const std::string &) const;
};
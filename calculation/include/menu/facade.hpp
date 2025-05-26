#pragma once

#include "sorting/sorter.hpp"
#include "translating/translator.hpp"
#include "computation/calculator.hpp"
#include "tokenization/tokenizer.hpp"
#include "parsing/parser.hpp"
#include "memory/memory.hpp"
#include "history/history.hpp"

#include <string>

class Facade {
private:
    Tokenizer tokenizer;
    Parser parser;
    Sorter sorter;
    Translator translator;
    Calculator calculator;
    Memory memory;
    History history;
public:
    Facade();

    const std::string calculate(const std::string &expression) const;
    
    const std::string memory_add(const std::string &expression) noexcept;

    const std::string memory_substract(const std::string &expression) noexcept;

    const void memory_clear() noexcept;

    const std::string memory_read() const noexcept;

    void history_save(const std::string &expression) noexcept;

    const std::string history_get_prev();
    
    const std::string history_get_next();
};
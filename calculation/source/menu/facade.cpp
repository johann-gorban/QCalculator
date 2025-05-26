#include "menu/facade.hpp"

#include "parsing/extended_tokens.hpp"

Facade::Facade() :
    memory(),
    history()
{}

const std::string Facade::calculate(const std::string &expression) const {
    std::string result;
    
    static Tokenizer tokenizer;
    static Parser parser;
    static Sorter sorter;
    static Calculator calculator;

    try {
        std::vector<token_ptr> tokens = tokenizer.tokenize(expression);
        std::vector<token_ptr> extended_tokens = parser.parse(tokens);
        std::vector<token_ptr> sorted_tokens = sorter.rpn_sort(extended_tokens);
        std::vector<command_ptr> commands = translator.translate_tokens(sorted_tokens);

        result = std::to_string(calculator.calculate(commands));
    }
    catch (std::exception &error) {
        result = error.what();
    }
    
    return result;
}

const std::string Facade::memory_add(const std::string &expression) noexcept {
    std::string result = "";
    try {
        double value = std::stod(expression);
        this->memory.add(value);
    }
    catch (std::exception &error) {
        result = error.what();
    }

    return result;
}

const std::string Facade::memory_substract(const std::string &expression) noexcept {
    std::string result = "";
    try {
        double value = std::stod(expression);
        this->memory.substract(value);
    }
    catch (std::exception &error) {
        result = error.what();
    }

    return result;
}

const void Facade::memory_clear() noexcept {
    this->memory.clear();
}

const std::string Facade::memory_read() const noexcept {
    return std::to_string(this->memory.get_value());
}

void Facade::history_save(const std::string &expression) noexcept {
    this->history.save(expression);
}

const std::string Facade::history_get_prev() {
    return this->history.get_prev();
}

const std::string Facade::history_get_next() {
    return this->history.get_next();
}
#pragma once

#include <memory>
#include <vector>
#include <string>

#include "states.hpp"


class LexerContext {
private:
    std::vector<std::shared_ptr<Token>> tokens;
    std::unique_ptr<State> current_state;
    std::string buffer;
public:
    explicit LexerContext(std::unique_ptr<State> start_state);

    std::vector<std::shared_ptr<Token>> get_tokens() const;

    void set_state(std::unique_ptr<State> new_state);

    const std::string &get_buffer() const;

    void emit_token(std::shared_ptr<Token> token);

    void append_buffer(char c);

    void finish();
};
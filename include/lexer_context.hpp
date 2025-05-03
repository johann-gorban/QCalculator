#pragma once

#include <memory>
#include <vector>
#include <string>

#include "states.hpp"

typedef std::shared_ptr<Token> token_ptr;
typedef std::shared_ptr<State> state_ptr;

class LexerContext {
private:
    std::vector<token_ptr> tokens;
    state_ptr start_state;
    std::string buffer;
public:
    LexerContext();

    std::vector<token_ptr> get_tokens() const;

    std::string get_buffer() const;

    void clear_buffer();

    void handle_char(char c);

    void append_buffer(char c);

    void append_token(token_ptr token);

    void set_state(state_ptr new_state);
};
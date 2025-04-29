#pragma once

#include <memory>
#include <vector>
#include <string>

#include "states.hpp"


class TokenizerContext {
private:
    std::unique_ptr<State> current_state;
    std::string buffer;
    std::vector<std::shared_ptr<Token>> tokens;
public:
    explicit TokenizerContext(std::unique_ptr<State> start_state);

    std::vector<std::shared_ptr<Token>> get_tokens() const;

    void set_state(std::unique_ptr<State> new_state);

    void emit_token(std::shared_ptr<Token> token);

    void append_buffer(char c);

    void finish();
};
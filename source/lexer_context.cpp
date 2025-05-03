#include "lexer_context.hpp"


LexerContext::LexerContext() {
    this->start_state = std::make_shared<StartState>();
}

void LexerContext::append_token(token_ptr token) {
    this->tokens.push_back(token);
}

void LexerContext::append_buffer(char c) {
    this->buffer += c;
}

void LexerContext::handle_char(char c) {
    this->start_state->handle_char(*this, c);
}

std::string LexerContext::get_buffer() const {
    return this->buffer;
}

std::vector<token_ptr> LexerContext::get_tokens() const {
    return this->tokens;
}
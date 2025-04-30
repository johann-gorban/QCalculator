#include "lexer_context.hpp"


LexerContext::LexerContext(std::unique_ptr<State> start_state) {
    this->current_state = std::move(start_state);
}


void LexerContext::set_state(std::unique_ptr<State> new_state) {
    this->current_state = std::move(new_state);
}


void LexerContext::finish() {
    if (this->current_state) {
        this->current_state->finish_input(*this);
    }
}


const std::string &LexerContext::get_buffer() const {
    return this->buffer;
}


std::vector<std::shared_ptr<Token>> LexerContext::get_tokens() const{
    return this->tokens;
}


void LexerContext::emit_token(std::shared_ptr<Token> token) {
    this->tokens.push_back(token);
    buffer.clear();
}


void LexerContext::append_buffer(char c) {
    this->buffer += c;
}

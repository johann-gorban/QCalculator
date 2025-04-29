#include "tokenizer_context.hpp"


TokenizerContext::TokenizerContext(std::unique_ptr<State> start_state) {
    this->current_state = std::move(start_state);
}


void TokenizerContext::set_state(std::unique_ptr<State> new_state) {
    this->current_state = std::move(new_state);
}


void TokenizerContext::finish() {
    if (this->current_state) {
        this->current_state->finish_input(*this);
    }
}


std::vector<std::shared_ptr<Token>> TokenizerContext::get_tokens() const{
    return this->tokens;
}


void TokenizerContext::emit_token(std::shared_ptr<Token> token) {
    this->tokens.push_back(token);
    buffer.clear();
}


void TokenizerContext::append_buffer(char c) {
    this->buffer += c;
}

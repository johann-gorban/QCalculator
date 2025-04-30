#include "states.hpp"
#include "lexer_context.hpp"

#include <memory>
#include <algorithm>
#include <stdexcept>


void State::finish_input(LexerContext &context) {
    // Empty as template
}


void StartState::handle_char(LexerContext &context, char c) {
    std::unique_ptr<State> new_state;
    // Pay attention to possible bug here (because of start with .) 
    if (std::isdigit(c) || c == '.') {
        new_state = std::make_unique<NumberState>();
    }
    else if (std::isalpha(c)) {
        new_state = std::make_unique<IdentifierState>();
    }
    else if (std::string("+-^*/").find(c) != std::string::npos) {
        new_state = std::make_unique<OperatorState>();
    }
    // Pay attention to left paranthesis in the beginning
    // Should throw a syntax error
    else if (c == ')' || c == '(') {
        new_state = std::make_unique<ParanthesisState>();
    }
    // Pay attention to comma in the beginning of expression
    // Should throw a syntax error
    else if (c == ',') {
        new_state = std::make_unique<CommaState>();
    }

}


void NumberState::handle_char(LexerContext &context, char c) {
    std::unique_ptr<State> new_state;
    if (std::isdigit(c)) {
        context.append_buffer(c);
        new_state = std::make_unique<NumberState>(); // Why?
    }
    else if (c == '.') {
        auto current_buffer = context.get_buffer();
        if (std::count(current_buffer.begin(), current_buffer.end(), '.') != 0) {
            throw std::runtime_error("Invalid float number format");
        }
        else {
            context.append_buffer(c);
            new_state = std::make_unique<NumberState>(); // Why?
        }
    }
    else if (std::string("+-^*/").find(c) != std::string::npos) {
        new_state = std::make_unique<OperatorState>();
    }
    else if (c == ')' || c == '(') {
        new_state = std::make_unique<NumberState>();
    }
    else if (std::isalpha(c)) {
        throw std::runtime_error("Invalid number format"); // Maybe add ErrorState?
    }
    
    context.set_state(std::move(new_state));
}


void NumberState::finish_input(LexerContext &context) {
    auto current_buffer = context.get_buffer();
    double number = std::stod(current_buffer);
    
    auto number_token = std::make_shared<Token>(Number(number));
    context.emit_token(number_token);
}
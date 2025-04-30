#include "states.hpp"

#include <memory>

void StartState::handle_char(LexerContext& context, char c) {
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

void StartState::finish_input(LexerContext &context) {

}
#include "states.hpp"
#include "lexer_context.hpp"
#include "token_manager.hpp"

#include <memory>
#include <algorithm>
#include <stdexcept>


void State::emit_token_from_buffer(LexerContext &context) {
    // Nothing here
}


void StartState::handle_char(LexerContext &context, char c) {
    state_ptr new_state;

    if (std::isdigit(c) || c == '.') {
        new_state = std::make_shared<NumberState>();
    }

    else if (std::isalpha(c)) {
        new_state = std::make_shared<IdentifierState>();
    }

    // Handle unary minus in the beginning
    else if (c == '-') {
        new_state = std::make_shared<UnaryMinusState>();
    }

    else if (c == '(') {
        new_state = std::make_shared<LeftParanthesisState>();
    }
    
    else if (c == ')') {
        new_state = std::make_shared<RightParanthesisState>();
    }

    else if (c == ',') {
        new_state = std::make_shared<CommaState>();
    }

    else {
        TokenManager token_manager;
        if (token_manager.operator_has_token(c)) {
            new_state = std::make_shared<OperatorState>();
        }
    }

    new_state->handle_char(context, c);
}

void StartState::emit_token_from_buffer(LexerContext &context) {

}

//////////////////////////////////////////////////////////////////////////////////////////

void NumberState::handle_char(LexerContext &context, char c) {
    state_ptr new_state = std::make_shared<NumberState>();

    if (std::isdigit(c)) {
        context.append_buffer(c);
    }

    else if (c == '.') {
        auto current_buffer = context.get_buffer();
        
        // Need to check how much floating points are in the number
        // If there is a point and now there is a new point, it is lexical error

        if (std::count(current_buffer.begin(), current_buffer.end(), '.') != 0) {
            throw std::runtime_error("Lexical error: invalid float number format");
        }
        else {
            context.append_buffer(c);
        }
    }

    
    else {
        // Create token after the state changed
        this->emit_token_from_buffer(context);

        TokenManager token_manager;
        if (token_manager.operator_has_token(c)) {
            new_state = std::make_shared<OperatorState>();
        }

        if (c == ')') {
            new_state = std::make_shared<RightParanthesisState>();
        }

        if (c == '(') {
            new_state = std::make_shared<LeftParanthesisState>();
            // Should also add multiplication token
            // 2(2 + 2) <=> 2 * (2 + 2)
            context.append_token(std::make_shared<OperatorMultiplication>());
        }
    
        if (std::isalpha(c)) {
            new_state = std::make_shared<IdentifierState>();
            // Should also add multiplication token
            // 2sin(pi/2) <=> 2 * sin(pi/2)
            context.append_token(std::make_shared<OperatorMultiplication>());
        }

        if (c == '\0') {
            new_state = std::make_shared<EndState>();
        }

        if (c == ' ') {
            new_state = std::make_shared<StartState>();
        }
    }
    context.set_state(new_state);
}

void NumberState::emit_token_from_buffer(LexerContext &context) {
    // Get buffer that stores number
    auto current_buffer = context.get_buffer();
    
    // Convert string number to double
    double number = std::stod(current_buffer);
    
    // Create new number token
    auto number_token = std::make_shared<Number>(number);

    // Append the created token to context
    context.append_token(number_token);

    context.clear_buffer();
}

//////////////////////////////////////////////////////////////////////////////////////////

void OperatorState::handle_char(LexerContext &context, char c) {
    state_ptr new_state = std::make_shared<OperatorState>();

    if (c == '-') {
        new_state = std::make_shared<UnaryMinusState>();
    }

    else if (std::isdigit(c) || c == '.') {
        new_state = std::make_shared<NumberState>();
        this->emit_token_from_buffer(context);
    }

    else if (c == ' ') {
        new_state = std::make_shared<StartState>();
    }

    else if (std::isalpha(c)) {
        new_state = std::make_shared<IdentifierState>();
        this->emit_token_from_buffer(context);
    }

    else if (c == ')') {
        new_state = std::make_shared<LeftParanthesisState>();
        this->emit_token_from_buffer(context);
    }

    else if (c == '(') {
        new_state = std::make_shared<RightParanthesisState>();
        this->emit_token_from_buffer(context);
    }

    else if (c == ',') {
        new_state = std::make_shared<CommaState>();
        this->emit_token_from_buffer(context);
    }

    else if (c == '\0') {
        new_state = std::make_shared<EndState>();
        this->emit_token_from_buffer(context);
    }

    else {
        TokenManager token_manager;
        if (token_manager.operator_has_token(c)) {
            new_state = std::make_shared<OperatorState>();
            context.append_buffer(c);
        }
    }

    context.set_state(new_state);
}

void OperatorState::emit_token_from_buffer(LexerContext &context) {
    // Get buffer that stores operator
    auto current_buffer = context.get_buffer();
    
    // Get operator from buffer string
    std::string op_name = current_buffer;

    // Create token manager to define operator we got
    TokenManager token_manager;

    // Create new operator token
    auto number_token = token_manager.get_token(op_name);

    // Append the created token to context
    context.append_token(number_token);

    context.clear_buffer();
}

//////////////////////////////////////////////////////////////////////////////////////////

void UnaryMinusState::handle_char(LexerContext &context, char c) {
    // Will emit number token for -1 and multiplication token
    // So appending token into context is needed
    state_ptr new_state = std::make_shared<UnaryMinusState>();

    this->emit_token_from_buffer(context);

    if (std::isdigit(c) || c == '.') {
        new_state = std::make_shared<NumberState>();
    }
    else if (std::isalpha(c)) {
        new_state = std::make_shared<IdentifierState>();
    }
    else if (c == ' ') {
        new_state = std::make_shared<StartState>();
    }
    else if (c == ')') {
        new_state = std::make_shared<RightParanthesisState>();
    }
    else if (c == '(') {
        new_state = std::make_shared<LeftParanthesisState>();
    }
    else if (c == ',') {
        new_state = std::make_shared<CommaState>();
    }
    else if (c == '\0') {
        new_state = std::make_shared<EndState>();
    }
    else {
        TokenManager token_manager;
        if (token_manager.operator_has_token(c)) {
            new_state = std::make_shared<OperatorState>();
        }
    }

    context.set_state(new_state);
}

void UnaryMinusState::emit_token_from_buffer(LexerContext &context) {
    context.append_token(std::make_shared<Number>(-1));
    context.append_token(std::make_shared<OperatorMultiplication>());
}

//////////////////////////////////////////////////////////////////////////////////////////

void IdentifierState::handle_char(LexerContext &context, char c) {

}

void IdentifierState::emit_token_from_buffer(LexerContext &context) {

}

//////////////////////////////////////////////////////////////////////////////////////////

void LeftParanthesisState::handle_char(LexerContext &context, char c) {

}

void LeftParanthesisState::emit_token_from_buffer(LexerContext &context) {
    
}

//////////////////////////////////////////////////////////////////////////////////////////

void RightParanthesisState::handle_char(LexerContext &context, char c) {

}

void RightParanthesisState::emit_token_from_buffer(LexerContext &context) {
    
}

//////////////////////////////////////////////////////////////////////////////////////////

void CommaState::handle_char(LexerContext &context, char c) {

}

void CommaState::emit_token_from_buffer(LexerContext &context) {
    
}

//////////////////////////////////////////////////////////////////////////////////////////

void EndState::handle_char(LexerContext &context, char c) {
    context.set_state(std::make_shared<StartState>());
}

void EndState::emit_token_from_buffer(LexerContext &context) {
    
}

//////////////////////////////////////////////////////////////////////////////////////////
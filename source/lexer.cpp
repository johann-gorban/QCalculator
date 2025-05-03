#include "lexer.hpp"
#include "lexer_context.hpp"

Lexer::Lexer() {
    // Paranthesis and separator
    this->token_keys["("] = std::make_shared<LeftParanthesis>();
    this->token_keys[")"] = std::make_shared<RightParanthesis>();
    this->token_keys[","] = std::make_shared<Separator>();

    // Operators
    this->token_keys["+"] = std::make_shared<OperatorAddition>();
    this->token_keys["-"] = std::make_shared<OperatorSubstraction>();
    this->token_keys["*"] = std::make_shared<OperatorMultiplication>();
    this->token_keys["/"] = std::make_shared<OperatorDivision>();
    this->token_keys["^"] = std::make_shared<OperatorPower>();
    
    // Functions
}

std::vector<token_ptr> Lexer::tokenize(const std::string &expression) {
    LexerContext lexer_context;

    for (auto c : expression) {
        lexer_context.handle_char(c);
    }
    lexer_context.handle_char('\0');

    return lexer_context.get_tokens();
}
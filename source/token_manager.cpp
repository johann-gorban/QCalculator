#include "token_manager.hpp"


TokenManager::TokenManager() {
    // Operator tokens
    this->operator_tokens["+"] = std::make_shared<OperatorAddition>();
    this->operator_tokens["-"] = std::make_shared<OperatorSubstraction>();
    this->operator_tokens["*"] = std::make_shared<OperatorMultiplication>();
    this->operator_tokens["/"] = std::make_shared<OperatorDivision>();
    this->operator_tokens["^"] = std::make_shared<OperatorPower>();

    // Function tokens 
}

bool TokenManager::function_has_token(const std::string &name) const {
    return (this->function_tokens.find(name) != this->function_tokens.end());
}

bool TokenManager::operator_has_token(char name) const {
    // Convert char to string
    std::string op_name;
    op_name += name;

    return (this->function_tokens.find(op_name) != this->function_tokens.end());
}

const std::shared_ptr<Token> TokenManager::get_token(const std::string &name) const {
    std::shared_ptr<Token> token_ptr(nullptr);
    
    if (this->operator_has_token(name.at(0))) {
        token_ptr = this->operator_tokens.at(name);
    }

    else if (this->function_has_token(name)) {
        token_ptr = this->function_tokens.at(name);
    }

    return token_ptr;
}
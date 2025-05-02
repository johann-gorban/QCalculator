#include "token_manager.hpp"


TokenManager::TokenManager() {
    this->tokens["+"] = std::make_shared<OperatorAddition>();
    this->tokens["-"] = std::make_shared<OperatorSubstraction>();
    this->tokens["*"] = std::make_shared<OperatorMultiplication>();
    this->tokens["/"] = std::make_shared<OperatorDivision>();
    this->tokens["^"] = std::make_shared<OperatorPower>();
    this->tokens["~"] = std::make_shared<OperatorMinus>();
}

bool TokenManager::has_token(const std::string &name) const {
    return (this->tokens.find(name) != this->tokens.end());
}

const std::shared_ptr<Token> TokenManager::get_token(const std::string &name) const {
    std::shared_ptr<Token> token_ptr(nullptr);
    
    if (this->has_token(name)) {
        token_ptr = this->tokens.at(name);
    }

    return token_ptr;
}
#include "command_manager.hpp"


CommandManager::CommandManager() {
    commands["+"] = std::make_shared<AdditionCommand>();
    tokens["+"] = std::make_shared<OperatorAddition>();

    commands["-"] = std::make_shared<SubstractCommand>();
    tokens["-"] = std::make_shared<OperatorSubstraction>();

    commands["*"] = std::make_shared<MultiplyCommand>();
    tokens["*"] = std::make_shared<OperatorMultiplication>();

    commands["/"] = std::make_shared<DivisionCommand>();
    tokens["/"] = std::make_shared<OperatorDivision>();

    commands["^"] = std::make_shared<PowerCommand>();
    tokens["^"] = std::make_shared<OperatorPower>();

    // Fucking unary minus 
    commands["~"] = std::make_shared<MinusCommand>();
    tokens["~"] = std::make_shared<OperatorMinus>();
}

const std::shared_ptr<Command> CommandManager::get_command(const std::string &token_name) const {
    std::shared_ptr<Command> command(nullptr);

    if (commands.find(token_name) != commands.end()) {
        command = commands.at(token_name);
    }
    
    return command;
}

bool CommandManager::has_token(const std::string &token_name) const {
    return (tokens.find(token_name) != tokens.end());
}

bool CommandManager::has_command(const std::string &token_name) const {
    return (commands.find(token_name) != commands.end());
}
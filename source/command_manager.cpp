#include "command_manager.hpp"


CommandManager::CommandManager() {
    this->commands["ADD"] = std::make_shared<AdditionCommand>();
    this->commands["SUB"] = std::make_shared<SubstractCommand>();
    this->commands["MUL"] = std::make_shared<MultiplyCommand>();
    this->commands["DIV"] = std::make_shared<DivisionCommand>();
    this->commands["POW"] = std::make_shared<PowerCommand>();
    this->commands["NUMBER"] = std::make_shared<NumberCommand>();
}

const command_ptr CommandManager::get_command(const token_ptr &token) const {
    command_ptr command(nullptr);

    std::string token_name = token->get_name();

    if (this->has_command(token_name)) {
        command = this->commands.at(token_name);
    }
    
    return command;
}

bool CommandManager::has_command(const std::string &token_name) const {
    return (commands.find(token_name) != commands.end());
}
#include "command_manager.hpp"


CommandManager::CommandManager() {
    this->commands["+"] = std::make_shared<AdditionCommand>();
    this->commands["-"] = std::make_shared<SubstractCommand>();
    this->commands["*"] = std::make_shared<MultiplyCommand>();
    this->commands["/"] = std::make_shared<DivisionCommand>();
    this->commands["^"] = std::make_shared<PowerCommand>();
    this->commands["~"] = std::make_shared<MinusCommand>();
}

const std::shared_ptr<Command> CommandManager::get_command(const std::string &token_name) const {
    std::shared_ptr<Command> command(nullptr);

    if (this->has_command(token_name)) {
        command = this->commands.at(token_name);
    }
    
    return command;
}

bool CommandManager::has_command(const std::string &token_name) const {
    return (commands.find(token_name) != commands.end());
}
#pragma once

#include "commands.hpp"
#include "tokens.hpp"

#include <unordered_map>
#include <memory>

class CommandManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Command>> commands;
    std::unordered_map<std::string, std::shared_ptr<Token>> tokens;
public:
    CommandManager();

    const std::shared_ptr<Command> get_command(const std::string &token_name) const;

    bool has_token(const std::string &token_name) const;

    bool has_command(const std::string &token_name) const;
};
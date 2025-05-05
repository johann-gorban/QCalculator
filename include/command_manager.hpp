#pragma once

#include "commands.hpp"
#include "tokens.hpp"

#include <unordered_map>
#include <memory>

 

class CommandManager {
private:
    std::unordered_map<std::string, command_ptr> commands;
public:
    CommandManager();

    const command_ptr get_command(const token_ptr &token) const;

    bool has_command(const std::string &token_name) const;
};
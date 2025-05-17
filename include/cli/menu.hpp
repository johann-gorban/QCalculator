#pragma once

#include <unordered_map>
#include <string>
#include "commands.hpp"

class CLIMenu {
private:
    std::unordered_map<std::string, menu_command_ptr> commands;
private:
    void display() const noexcept;
public:
    CLIMenu();
    
    void run() const noexcept;
};
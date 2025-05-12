#include "translating/translator.hpp"


const std::vector<command_ptr> &Translator::translate_tokens(const std::vector<token_ptr> &tokens) const {
    std::vector<command_ptr> commands;

    CommandManager command_manager;

    for (const auto &token : tokens) {
        command_ptr command = command_manager.get_command(token);
        if (command) {
            commands.push_back(command);
        }
    }

    return commands;
}
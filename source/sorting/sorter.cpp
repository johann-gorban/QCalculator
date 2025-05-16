#include "sorting/sorter.hpp"
#include "sorting/sort_command_manager.hpp"

#include <stack>
#include <stdexcept>

std::vector<token_ptr> Sorter::rpn_sort(const std::vector<token_ptr> &tokens) {
    // "Stack" for storing tokens in reverse polnish notation order
    std::vector<token_ptr> result;

    std::stack<token_ptr> token_stack;
    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
        token_stack.push(*it);
    }

    static SortCommandManager command_manager;
    for (const auto& token : tokens) {
        auto command = command_manager.get_command(token);
        command->execute(token_stack, result, token);
    }

    sort_command_ptr end_command = std::make_shared<SortEndCommand>();
    end_command->execute(token_stack, result, nullptr);

    return result;
}
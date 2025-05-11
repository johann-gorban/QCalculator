#include "calculator.hpp"
#include "command_manager.hpp"

#include <stack>
#include <stdexcept>

double Calculator::calculate(std::vector<std::shared_ptr<Token>> tokens_rpn) {
    // Stack for computation. There the intermediate calculations are being stored
    std::stack<double> computations;

    // Command manager for getting command for calculation by token
    CommandManager command_manager;

    for (const auto &token: tokens_rpn) {
        auto command = command_manager.get_command(token);
        command->execute(computations, token);
    } 
    
    return computations.top();
}
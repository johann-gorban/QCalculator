#include "calculator.hpp"
#include "translating/translator.hpp"

#include <stack>
#include <stdexcept>

double Calculator::calculate(const std::vector<command_ptr> &commands){
    // Stack for computation. There the intermediate calculations are being stored
    std::stack<double> computations;

    // Command manager for getting command for calculation by token
    CommandManager command_manager;

    for (const auto &command : commands) {
        command->execute(computations);
    } 
    
    return computations.top();
}
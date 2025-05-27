#include "menu.hpp"
#include "commands.hpp"

#include <iostream>

CLIMenu::CLIMenu() {
    this->commands["="] = std::make_shared<CalculateCommand>("Enter and calculate expression");
    this->commands["M+"] = std::make_shared<MemoryAddCommand>("Add last result to memory");
    this->commands["M-"] = std::make_shared<MemorySubtractCommand>("Substract last result from memory");
    this->commands["MC"] = std::make_shared<MemoryClearCommand>("Clear memory");
    this->commands["MR"] = std::make_shared<MemoryReadCommand>("Print memory out");
}

void CLIMenu::display() const noexcept {
    for (auto &it : commands) {
        std::cout << it.first << ". " << it.second->get_description() << std::endl;
    }
}

void CLIMenu::run() const noexcept {
    static Facade facade;

    std::string result, last_result, command = "";

    while (1) {
        this->display();

        std::cout << "Input: ";
        std::cin >> command;

        if (command == "Exit") {
            break;
        }

        if (command == "=") {
            std::cout << "Expression: ";
            std::string expression;
            std::cin >> expression;
            result = this->commands.at(command)->execute(facade, expression);
        }
        else {
            result = this->commands.at(command)->execute(facade, last_result);
        }

        last_result = result;

        std::cout << "Result: " << result << std::endl;
    }
}
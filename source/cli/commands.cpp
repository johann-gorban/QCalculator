#include "cli/commands.hpp"

MenuCommand::MenuCommand(const std::string &description) : _description(description) {}

const std::string MenuCommand::get_description() const noexcept {
    return this->_description;
}

CalculateCommand::CalculateCommand(const std::string &description) : MenuCommand(description) {
}

const std::string CalculateCommand::execute(Facade &facade, const std::string &data) const {
    return facade.calculate(data);
}


MemoryAddCommand::MemoryAddCommand(const std::string &description) : MenuCommand(description) {
}

const std::string MemoryAddCommand::execute(Facade &facade, const std::string &data) const {
    return facade.memory_add(data);
}


MemorySubtractCommand::MemorySubtractCommand(const std::string &description) : MenuCommand(description) {
}

const std::string MemorySubtractCommand::execute(Facade &facade, const std::string &data) const {
    return facade.memory_substract(data);
}


MemoryClearCommand::MemoryClearCommand(const std::string &description) : MenuCommand(description) {
}

const std::string MemoryClearCommand::execute(Facade &facade, const std::string &data) const {
    facade.memory_clear();
    return data;
}


MemoryReadCommand::MemoryReadCommand(const std::string &description) : MenuCommand(description) {
}

const std::string MemoryReadCommand::execute(Facade &facade, const std::string &data) const {
    return facade.memory_read();
}
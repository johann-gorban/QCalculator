#pragma once

#include <string>
#include <memory>

#include "facade.hpp"

class MenuCommand;
using menu_command_ptr = std::shared_ptr<MenuCommand>;

class MenuCommand {
private:
    const std::string _description;
public:
    MenuCommand() = delete;

    explicit MenuCommand(const std::string &description);

    virtual const std::string execute(Facade &facade, const std::string &data = "") const = 0;

    const std::string get_description() const noexcept;

    virtual ~MenuCommand() = default;
};


class CalculateCommand : public MenuCommand {
public:
    explicit CalculateCommand(const std::string& description);

    const std::string execute(Facade &facade, const std::string &data = "") const override;
};

class MemoryAddCommand : public MenuCommand {
public:
    explicit MemoryAddCommand(const std::string& description);

    const std::string execute(Facade &facade, const std::string &data = "") const override;
};

class MemorySubtractCommand : public MenuCommand {
public:
    explicit MemorySubtractCommand(const std::string& description);

    const std::string execute(Facade &facade, const std::string &data = "") const override;
};

class MemoryClearCommand : public MenuCommand {
public:
    explicit MemoryClearCommand(const std::string& description);

    const std::string execute(Facade &facade, const std::string &data = "") const override;
};

class MemoryReadCommand : public MenuCommand {
public:
    explicit MemoryReadCommand(const std::string& description);
    
    const std::string execute(Facade &facade, const std::string &data = "") const override;
};



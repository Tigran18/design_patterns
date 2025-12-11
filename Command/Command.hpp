#pragma once
#include <memory>

class Receiver {
public:
    void turnOn();
    void turnOff();
};

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class OnCommand : public Command {
public:
    explicit OnCommand(Receiver& r);
    void execute() override;

private:
    Receiver& receiver;
};

class OffCommand : public Command {
public:
    explicit OffCommand(Receiver& r);
    void execute() override;

private:
    Receiver& receiver;
};

class Invoker {
public:
    void setCommand(std::unique_ptr<Command> cmd);
    void run();

private:
    std::unique_ptr<Command> command;
};

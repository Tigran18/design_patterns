#include "Command.hpp"
#include <iostream>

void Receiver::turnOn() {
    std::cout << "Receiver on\n";
}

void Receiver::turnOff() {
    std::cout << "Receiver off\n";
}

OnCommand::OnCommand(Receiver& r)
    : receiver(r) {}

void OnCommand::execute() {
    receiver.turnOn();
}

OffCommand::OffCommand(Receiver& r)
    : receiver(r) {}

void OffCommand::execute() {
    receiver.turnOff();
}

void Invoker::setCommand(std::unique_ptr<Command> cmd) {
    command = std::move(cmd);
}

void Invoker::run() {
    if (command) {
        command->execute();
    }
}

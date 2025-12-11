#include "Command.hpp"

int main() {
    Receiver receiver;
    Invoker invoker;

    invoker.setCommand(std::make_unique<OnCommand>(receiver));
    invoker.run();

    invoker.setCommand(std::make_unique<OffCommand>(receiver));
    invoker.run();

    return 0;
}

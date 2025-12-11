#include "Chain.hpp"

int main() {
    auto info = std::make_shared<InfoHandler>();
    auto warn = std::make_shared<WarningHandler>();
    auto err = std::make_shared<ErrorHandler>();

    info->setNext(warn);
    warn->setNext(err);

    info->handle("info");
    info->handle("warning");
    info->handle("error");
    info->handle("unknown");

    return 0;
}

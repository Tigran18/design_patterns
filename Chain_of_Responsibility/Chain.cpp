#include "Chain.hpp"
#include <iostream>

void Handler::setNext(std::shared_ptr<Handler> nextHandler) {
    next = std::move(nextHandler);
}

void Handler::handle(const std::string& request) {
    if (!process(request) && next) {
        next->handle(request);
    }
}

bool InfoHandler::process(const std::string& request) {
    if (request == "info") {
        std::cout << "InfoHandler handled\n";
        return true;
    }
    return false;
}

bool WarningHandler::process(const std::string& request) {
    if (request == "warning") {
        std::cout << "WarningHandler handled\n";
        return true;
    }
    return false;
}

bool ErrorHandler::process(const std::string& request) {
    if (request == "error") {
        std::cout << "ErrorHandler handled\n";
        return true;
    }
    return false;
}

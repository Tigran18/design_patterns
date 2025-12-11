#include <iostream>
#include <memory>
#include <string>

enum class LogLevel {
    Debug,
    Info,
    Error
};

class Logger {
protected:
    std::shared_ptr<Logger> next;

public:
    virtual ~Logger() = default;

    void setNext(std::shared_ptr<Logger> nextLogger) {
        next = nextLogger;
    }

    void handle(LogLevel level, const std::string& msg) {
        if (canHandle(level)) {
            process(msg);
        } else if (next) {
            next->handle(level, msg);
        }
    }

protected:
    virtual bool canHandle(LogLevel level) = 0;
    virtual void process(const std::string& msg) = 0;
};

class DebugLogger : public Logger {
protected:
    bool canHandle(LogLevel level) override {
        return level == LogLevel::Debug;
    }
    void process(const std::string& msg) override {
        std::cout << "[DEBUG] " << msg << "\n";
    }
};

class InfoLogger : public Logger {
protected:
    bool canHandle(LogLevel level) override {
        return level == LogLevel::Info;
    }
    void process(const std::string& msg) override {
        std::cout << "[INFO] " << msg << "\n";
    }
};

class ErrorLogger : public Logger {
protected:
    bool canHandle(LogLevel level) override {
        return level == LogLevel::Error;
    }
    void process(const std::string& msg) override {
        std::cout << "[ERROR] " << msg << "\n";
    }
};

int main() {
    auto debugLogger = std::make_shared<DebugLogger>();
    auto infoLogger  = std::make_shared<InfoLogger>();
    auto errorLogger = std::make_shared<ErrorLogger>();

    // Build: Debug → Info → Error
    debugLogger->setNext(infoLogger);
    infoLogger->setNext(errorLogger);

    // Test messages
    debugLogger->handle(LogLevel::Debug, "Initializing system...");
    debugLogger->handle(LogLevel::Info,  "User logged in.");
    debugLogger->handle(LogLevel::Error, "Disk failure!");

    return 0;
}

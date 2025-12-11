#pragma once
#include <string>
#include <memory>

class Handler {
public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> nextHandler);

    void handle(const std::string& request);

protected:
    virtual bool process(const std::string& request) = 0;

private:
    std::shared_ptr<Handler> next;
};

class InfoHandler : public Handler {
protected:
    bool process(const std::string& request) override;
};

class WarningHandler : public Handler {
protected:
    bool process(const std::string& request) override;
};

class ErrorHandler : public Handler {
protected:
    bool process(const std::string& request) override;
};

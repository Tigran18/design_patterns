#pragma once
#include <memory>

class Context;

class State {
public:
    virtual ~State() = default;
    virtual void toggle(Context& ctx) = 0;
    virtual void print() const = 0;
};

class Context {
public:
    explicit Context(std::unique_ptr<State> st);
    void setState(std::unique_ptr<State> st);
    void toggle();
    void print() const;

private:
    std::unique_ptr<State> state;
};

class OnState : public State {
public:
    void toggle(Context& ctx) override;
    void print() const override;
};

class OffState : public State {
public:
    void toggle(Context& ctx) override;
    void print() const override;
};

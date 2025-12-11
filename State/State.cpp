#include "State.hpp"
#include <iostream>

Context::Context(std::unique_ptr<State> st)
    : state(std::move(st)) {}

void Context::setState(std::unique_ptr<State> st) {
    state = std::move(st);
}

void Context::toggle() {
    state->toggle(*this);
}

void Context::print() const {
    state->print();
}

void OnState::toggle(Context& ctx) {
    ctx.setState(std::make_unique<OffState>());
}

void OnState::print() const {
    std::cout << "State: ON\n";
}

void OffState::toggle(Context& ctx) {
    ctx.setState(std::make_unique<OnState>());
}

void OffState::print() const {
    std::cout << "State: OFF\n";
}

#include "State.hpp"

int main() {
    Context ctx(std::make_unique<OffState>());
    ctx.print();
    ctx.toggle();
    ctx.print();
    ctx.toggle();
    ctx.print();
    return 0;
}

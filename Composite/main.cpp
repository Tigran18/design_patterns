#include <iostream>
#include "Composite.hpp"

int main() {
    auto circle1 = std::make_unique<Circle>();
    auto rect1 = std::make_unique<Rectangle>();
    auto group1 = std::make_unique<Group>();
    group1->add(std::make_unique<Circle>());
    group1->add(std::make_unique<Rectangle>());
    auto mainGroup = std::make_unique<Group>();
    mainGroup->add(std::move(circle1));
    mainGroup->add(std::move(rect1));
    mainGroup->add(std::move(group1));
    mainGroup->draw();
    return 0;
}
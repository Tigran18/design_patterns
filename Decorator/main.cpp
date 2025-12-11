#include "decorator.hpp"
#include <memory>

int main() {
    std::shared_ptr<IPlane> jet = std::make_shared<FighterJet>();
    std::shared_ptr<IPlane> armedJet = std::make_shared<ArmedDecorator>(jet);

    armedJet->fly();
}

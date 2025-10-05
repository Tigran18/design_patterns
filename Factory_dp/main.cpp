#include <iostream>
#include "Factory.hpp"
#include <vector>
#include <memory>

int main(){
    srand(time(0));
    std::vector<std::unique_ptr<IMaterials>> materials;
    for (size_t i = 0; i < 10; ++i) {
        Types type = (std::rand() % 2 == 0) ? Types::type1 : Types::type2;
        int m1 = std::rand() % 100;
        float m2 = static_cast<float>(std::rand() % 100);
        char m3 = 'A' + (std::rand() % 26);
        materials.push_back(Factory::create(type, m1, m2, m3));
    }
    for(const auto& material : materials) {
        material->show_info();
    }
    return 0;
}
#include "Factory.hpp"

template <Types T>
Material<T>::Material(int m1, float m2, char m3) requires (T == Types::type1) {
    member1 = m1;
    member2 = m2;
    member3 = m3;
    std::cout << "Constructor called for object of type1" << std::endl;
}

template <Types T>
Material<T>::Material(int m1, float m2, char m3) requires (T == Types::type2) {
    member1 = m1;
    member2 = m2;
    member3 = m3;
    std::cout << "Constructor called for object of type2" << std::endl;
}

template <Types T>
void Material<T>::show_info() const {
    std::cout << "Int is: " << member1
              << ", Float is: " << member2
              << ", Char is: " << member3 << std::endl;
}

std::unique_ptr<IMaterials> Factory::create(Types tp, int m1, float m2, char m3) {
    switch (tp) {
        case Types::type1:
            return std::make_unique<Material<Types::type1>>(m1, m2, m3);
        case Types::type2:
            return std::make_unique<Material<Types::type2>>(m1, m2, m3);
    }
    return nullptr;
}
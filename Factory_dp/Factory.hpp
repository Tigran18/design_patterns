#pragma once
#include <iostream>
#include <memory>

enum class Types {
    type1,
    type2
};

class IMaterials {
public:
    virtual ~IMaterials() {}
    virtual void show_info() const = 0;
};

template <Types T>
class Material : public IMaterials {
public:
    Material(int m1, float m2, char m3) requires (T == Types::type1);
    Material(int m1, float m2, char m3) requires (T == Types::type2);

    void show_info() const override;

private:
    int member1;
    float member2;
    char member3;
};

class Factory {
public:
    static std::unique_ptr<IMaterials> create(Types tp, int m1, float m2, char m3);
};

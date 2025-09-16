#include <iostream>
#include <memory>

enum class DrinkType {
    coffee,
    tea
};

class IDrink {
public:
    IDrink(){
        std::cout << "Base" << std::endl;
    }
    virtual ~IDrink() = 0;
    virtual void vf() = 0;
};

IDrink::~IDrink() {}

template <DrinkType T>
class Drink : public IDrink {
public:
    Drink(float v) : volume(v) {
        if constexpr (T == DrinkType::coffee)
            std::cout << "Coffee created" << std::endl;
        else if constexpr (T == DrinkType::tea)
            std::cout << "Tea created" << std::endl;
    }

    void vf() override {
        if constexpr (T == DrinkType::coffee)
            std::cout << "Coffee action\n";
        else
            std::cout << "Tea action\n";
    }

private:
    float volume;
};

class Factory {
public:
    static std::unique_ptr<IDrink> create(DrinkType type, float volume) {
        switch(type) {
            case DrinkType::coffee:
                return std::make_unique<Drink<DrinkType::coffee>>(volume);
            case DrinkType::tea:
                return std::make_unique<Drink<DrinkType::tea>>(volume);
        }
        return nullptr;
    }
};

int main() {
    // Compile-time creation
    Drink<DrinkType::coffee> cofa(10.5f);
    Drink<DrinkType::tea> chay(20.5f);

    // Runtime creation via factory
    auto drink = Factory::create(DrinkType::coffee, 80.75f);
    drink->vf();

    return 0;
}

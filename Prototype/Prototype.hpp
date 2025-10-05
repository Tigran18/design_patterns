#pragma once

#include <iostream>

class Cake {
public: 
    virtual ~Cake() = default;

    virtual void print() const = 0;

    virtual Cake* clone() const = 0;
};

class StrawberryCake : public Cake {
public:
    StrawberryCake(float radius, unsigned int n) : radius(radius), number_of_strawberries(n) {

    }

    void print() const {
        std::cout << "The radius of the cake is: " 
        << radius << "\nNumber of strawberries used: " 
        << number_of_strawberries << std::endl;
    }

    Cake* clone() const{
        return new StrawberryCake(*this);
    }

private:
    float radius = 0.0f;

    unsigned int number_of_strawberries = 0;
};

class BananaCake : public Cake {
public:
    BananaCake(float radius, unsigned int n) : radius(radius), number_of_bananas(n) {

    }

    void print() const {
        std::cout << "The radius of the cake is: " 
        << radius << "\nNumber of bananas used: " 
        << number_of_bananas << std::endl;
    }

    Cake* clone() const {
        return new BananaCake(*this);
    }
private:
    float radius = 0.0f;

    unsigned int number_of_bananas = 0;
};
#pragma once
#include <iostream>
#include <memory>

class IPlane {
public:
    virtual ~IPlane() = default;
    virtual void fly() = 0;
};

class FighterJet : public IPlane {
public:
    void fly() override {
        std::cout << "Fighter jet is flying fast and agile!\n";
    }
};

class CargoJet : public IPlane {
public:
    void fly() override {
        std::cout << "Cargo jet is flying heavily with supplies.\n";
    }
};

class Decorator : public IPlane {
protected:
    std::shared_ptr<IPlane> plane;
public:
    Decorator(std::shared_ptr<IPlane> p) : plane(std::move(p)) {}
    void fly() override {
        plane->fly();   
    }
};

class ArmedDecorator : public Decorator {
public:
    ArmedDecorator(std::shared_ptr<IPlane> p) : Decorator(std::move(p)) {}

    void fly() override {
        Decorator::fly();
        std::cout << "Now equipped with missiles!\n";
    }
};

class CargoDecorator : public Decorator {
public: 
    CargoDecorator(std::shared_ptr<IPlane> p) : Decorator(std::move(p)) {}

    void fly() override {
        Decorator::fly();
        std::cout << "Now equipped with cars!\n";
    }
};
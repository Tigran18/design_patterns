#pragma once
#include <iostream>

class Engine {
public:
    virtual int get_horsepower() = 0;
    virtual void set_horsepower(int hp) = 0;
protected:
    int horsepower = 0;
};

class Trunk {
public:
    virtual float get_size() = 0;
    virtual void set_size(float sz) = 0;
protected:
    float size = 0.0f;
};

class SedanEngine : public Engine {
public:
    int get_horsepower() override { 
        return horsepower; 
    }

    void set_horsepower(int hp) override { 
        horsepower = hp; 
    }
};

class TruckEngine : public Engine {
public:
    int get_horsepower() override { 
        return horsepower; 
    }

    void set_horsepower(int hp) override { 
        horsepower = hp; 
    }
};

class SedanTrunk : public Trunk {
public:
    float get_size() override { 
        return size; 
    }

    void set_size(float sz) override { 
        size = sz; 
    }
};

class TruckTrunk : public Trunk {
public:
    float get_size() override { 
        return size; 
    }

    void set_size(float sz) override { 
        size = sz; 
    }
};

class CarFactory {
public:
    virtual Engine* createEngine() = 0;
    virtual Trunk* createTrunk() = 0;
    virtual ~CarFactory() = default;
};

class SedanFactory : public CarFactory {
public:
    Engine* createEngine() override {
        SedanEngine* e = new SedanEngine();
        e->set_horsepower(150);
        return e;
    }

    Trunk* createTrunk() override {
        SedanTrunk* t = new SedanTrunk();
        t->set_size(450.5f);
        return t;
    }
};

class TruckFactory : public CarFactory {
public:
    Engine* createEngine() override {
        TruckEngine* e = new TruckEngine();
        e->set_horsepower(400);
        return e;
    }
    
    Trunk* createTrunk() override {
        TruckTrunk* t = new TruckTrunk();
        t->set_size(1200.0f);
        return t;
    }
};
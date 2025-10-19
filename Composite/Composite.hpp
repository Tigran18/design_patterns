#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {

    }
};

class Circle : public Shape {
public:
    void draw() override { 
        std::cout << "Circle\n"; 
    }
};

class Rectangle : public Shape {
public:
    void draw() override { 
        std::cout << "Rectangle\n"; 
    }
};

class Group : public Shape {
private:
    std::vector<std::unique_ptr<Shape>> children;
public:
    void add(std::unique_ptr<Shape> shape) {
        children.push_back(std::move(shape));
    }

    void draw() override {
        std::cout << "Group start\n";
        for (auto& child : children) {
            child->draw();
        }
        std::cout << "Group end\n";
    }
};
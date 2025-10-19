#include <iostream>
#include "AbstractFactory.hpp"

void buildCar(CarFactory* factory) {
    Engine* engine = factory->createEngine();
    Trunk* trunk = factory->createTrunk();

    std::cout << "Engine horsepower: " << engine->get_horsepower() << "\n";
    std::cout << "Trunk size: " << trunk->get_size() << "\n";

    delete engine;
    delete trunk;
}

int main() {
    CarFactory* sedanFactory = new SedanFactory();
    CarFactory* truckFactory = new TruckFactory();

    std::cout << "Sedan:\n";
    buildCar(sedanFactory);

    std::cout << "\nTruck:\n";
    buildCar(truckFactory);

    delete sedanFactory;
    delete truckFactory;
}

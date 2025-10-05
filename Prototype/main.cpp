#include "Prototype.hpp"

int main() {
    Cake* prototype1 = new StrawberryCake(12.5f, 8);
    Cake* prototype2 = new BananaCake(15.0f, 5);
    Cake* cake1 = prototype1->clone();
    Cake* cake2 = prototype2->clone();
    cake1->print();
    cake2->print();
    delete prototype1;
    delete prototype2;
    delete cake1;
    delete cake2;
    return 0;
}

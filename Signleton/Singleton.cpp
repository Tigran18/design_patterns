#include "Singleton.hpp"

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

Singleton::Singleton()
{
    std::cout << "Instance created" << std::endl;
}

Singleton& Singleton::get_instance() 
{
    if(!instance) {
        std::lock_guard<std::mutex> lock(mtx);
        if(!instance) {
            instance = new Singleton();
        }
    }
    return *instance;
}

void Singleton::do_something()
{
    std::cout << instance << std::endl;
}

void Singleton::destroy_instance()
{
    std::lock_guard<std::mutex> lock(mtx);
    delete instance;
    instance = nullptr;
}

Singleton::~Singleton()
{
    std::cout<< "Instance deleted" <<std::endl;
}

#include <iostream>
#include "Singleton.hpp"
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

void func(Singleton& instance) {
    std::lock_guard<std::mutex> lock(mtx);
    instance.do_something();
}

int main() {
    Singleton& instance1 = Singleton::get_instance();
    Singleton& instance2 = Singleton::get_instance();

    instance1.do_something();
    instance2.do_something();

    std::vector<std::thread> threads;
    threads.push_back(std::thread(func, std::ref(instance1)));
    threads.push_back(std::thread(func, std::ref(instance2)));

    for (auto& thread : threads) {
        thread.join();
    }

    Singleton::destroy_instance();
    return 0;
}

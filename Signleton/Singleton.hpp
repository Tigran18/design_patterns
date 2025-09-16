#include <iostream>
#include <mutex>

class Singleton{
private:
    Singleton();

    Singleton(const Singleton& instance) = delete;

    Singleton(Singleton&& instance) noexcept = delete;

    Singleton& operator=(const Singleton& instance) = delete;

    Singleton& operator=(Singleton&& instance) noexcept = delete;
    
    static Singleton* instance;

    static std::mutex mtx;
public:
    static Singleton& get_instance();

    void do_something();

    static void destroy_instance();

    ~Singleton();
};

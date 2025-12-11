#include <iostream>
#include <vector>
#include <memory>


class Observer {
public:
    virtual ~Observer() {
        
    }
    virtual void update(float temperature) = 0;
};

class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void notify(float value) {
        for (auto& obs : observers) {
            obs->update(value);
        }
    }
};

class WeatherStation : public Subject {
private:
    float temperature = 0.0f;

public:
    void setTemperature(float t) {
        temperature = t;
        notify(temperature);
    }
};

class PhoneDisplay : public Observer {
public:
    void update(float temperature) override {
        std::cout << "[Phone] Temp: " << temperature << "C\n";
    }
};

class WindowDisplay : public Observer {
public:
    void update(float temperature) override {
        std::cout << "[Window] Temp: " << temperature << "C\n";
    }
};

int main() {
    WeatherStation station;
    auto phone = std::make_shared<PhoneDisplay>();
    auto window = std::make_shared<WindowDisplay>();
    station.attach(phone);
    station.attach(window);
    station.setTemperature(22.5);
    station.setTemperature(25.0);
    return 0;
}

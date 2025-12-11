#include "Bridge.hpp"

void TV::TurnOn() {
        std::cout << "TV turned on" << std::endl;
        this->power = true;
    }

void TV::TurnOff() {
    std::cout << "TV turned off" << std::endl;
    this->power = false;
}

void TV::SetVolyume(const int volume) {
    if(volume >=0 && volume <= 100) {
        this->volume = volume;
    }
}

bool TV::GetState() const {
    return this->power;
}

void Radio::TurnOn() {
    std::cout << "Radio turned on" << std::endl;
}

void Radio::TurnOff() {
    std::cout << "Radio turned off" << std::endl;
}

void Radio::SetVolume(const int volume) {
    if(volume >=0 && volume <= 100) {
        this->volume = volume;
    }
}

bool Radio::GetState() const {
    return this->power;
}
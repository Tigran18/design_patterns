#pragma once

#include <iostream>
#include <memory>

class Device {
protected:
    int volume = 0;
    bool power = false;
public:
    virtual ~Device() = default;

    virtual void TurnOn() = 0;

    virtual void TurnOff() = 0;

    virtual void SetVolume(const int volume) = 0;

    virtual bool GetState() const = 0;

    virtual int GetVolume() const = 0;
};

class TV : public Device {
public:
    void TurnOn();

    void TurnOff();

    void SetVolyume(const int volume);

    bool GetState() const;
};

class Radio : public Device {
public:
    void TurnOn();

    void TurnOff();

    void SetVolume(const int volume);

    bool GetState() const;
};

class Remote {
protected:
    std::shared_ptr<Device> device;
public: 
    virtual ~Remote() = default;

    virtual void TogglePower() = 0;

    virtual void TurnUpVoldume() = 0;

    virtual void TurnDownVolume() = 0;
};

class ControlPanel : public Remote{
private:
    int volume_step = 10;
public:
    void TogglePower() {
        if(device->GetState()) {
            device->TurnOff();
        }
        else {
            device->TurnOn();
        }
    }

    void TurnUpVoldume() {
        if(device)
    }

    void TurnDownVolume() {
        
    }
};
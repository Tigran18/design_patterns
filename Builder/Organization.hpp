#pragma once

#include <iostream>
#include <string>

class Organization {
private:
    std::string name;
    std::string purpose;
    size_t starting_year = 0;
  
public:
    void set_name(const std::string& name) {
        this->name = name;
    }
    
    void set_purpose(const std::string& purpose) {
        this->purpose = purpose;
    }
    
    void set_starting_year(const size_t& starting_year) {
        this->starting_year = starting_year;
    }
    
    void show() {
        std::cout << "Organization name is: " << name
        << "\nOrganization target is: " << purpose
        << "\nOrganization works since: " << starting_year;
    }
};

#pragma once

#include "OrganizationBuilder.hpp"

class Synopsys : public OrganizationBuilder {
public:
    Synopsys() : OrganizationBuilder() {
        set_name("Synopsys Armenia");
        set_purpose("Chip design and software engineering");
        set_starting_year(2004);
    }
    
    void set_name(const std::string& name) override {
        organization->set_name(name);
    }

    void set_purpose(const std::string& purpose) override {
        organization->set_purpose(purpose);
    }

    void set_starting_year(size_t starting_year) override {
        organization->set_starting_year(starting_year);
    }
};

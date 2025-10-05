#pragma once

#include "Organization.hpp"

class OrganizationBuilder{
public:
    OrganizationBuilder() {
        organization = new Organization();
    }
    
    virtual void set_name(const std::string& name) = 0;
    
    virtual void set_purpose(const std::string& purpose) = 0;
    
    virtual void set_starting_year(size_t starting_year) = 0;
    
    virtual ~OrganizationBuilder() {
        delete organization;
    }
    
    Organization* getObject() {
        return organization;
    }
protected:
    Organization* organization;
};

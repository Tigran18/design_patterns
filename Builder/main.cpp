#include <iostream>
#include <string>
#include "Organization.hpp"
#include "Synopsys.hpp"

int main() {
    Synopsys builder;
    Organization* org = builder.getObject();
    org->show();
    return 0;
}
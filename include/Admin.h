#pragma once

// include
#include "Participant.h"
#include <iostream>

class Admin : public Participant {
private:

public:
    Admin(const std::string&, const std::string&, const std::string&);
    ~Admin();
    friend std::ostream& operator<< (std::ostream&, const Admin&);
};
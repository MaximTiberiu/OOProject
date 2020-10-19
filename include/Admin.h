#pragma once

// include
#include "Participant.h"

class Admin : public Participant {
private:

public:
    Admin(const std::string&, const std::string&, const std::string&);
    ~Admin();
};
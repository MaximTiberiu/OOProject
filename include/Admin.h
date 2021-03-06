#pragma once

// include
#include "Participant.h"
#include <iostream>
#include <memory>

class Admin : public Participant {
private:

public:
    Admin();
    Admin(const std::string&, const std::string&, const std::string&);
    Admin(const Admin&);
    ~Admin();
    std::unique_ptr<Participant> clone() override;

};
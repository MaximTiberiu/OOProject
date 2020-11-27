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
    Admin(const std::unique_ptr<Admin>&);
    ~Admin();
    friend std::ostream& operator<< (std::ostream&, const std::unique_ptr<Admin>&);
};
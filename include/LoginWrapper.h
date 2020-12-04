#pragma once
#include "./Participant.h"
#include <memory>
#include <iostream>

class LoginWrapper {
private:
    std::unique_ptr<Participant> participant;

public:
    LoginWrapper(Participant&);
    friend std::ostream &operator<< (std::ostream&, const LoginWrapper&);
};
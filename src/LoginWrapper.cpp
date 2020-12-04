#include "../include/LoginWrapper.h"

LoginWrapper::LoginWrapper(Participant& p) {
    this->participant = p.clone();
}

std::ostream &operator<< (std::ostream & out, const LoginWrapper& l) {
    out << l.participant->getUsername() << " " << l.participant->getPassword() << " " << l.participant->getEmail() << "\n";
    return out;
}

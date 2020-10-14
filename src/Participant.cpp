// include
#include "../include/Participant.h"

Participant::Participant(std::string username){
    this->username = username;
}

Participant::~Participant() = default;

std::string Participant::getUsername(){
    return username;
}
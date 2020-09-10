
#include "Linebacker.h"

using namespace std;
/********************************************/
Linebacker::Linebacker():DefensiePacket(){this->kind='L';}
/********************************************/
Linebacker::Linebacker(int n):DefensiePacket(n){this->kind='L';}
/********************************************/
Linebacker::Linebacker(string id_):DefensiePacket(id_){this->kind='L';}
/********************************************/
Linebacker::Linebacker(const Linebacker& cp):DefensiePacket((DefensiePacket)cp){this->kind='L';}
/********************************************/
Linebacker::~Linebacker(){}
/********************************************/
void Linebacker::Print() const{
    DefensiePacket::Print();
 }
/********************************************/
ostream& operator<<(ostream& out, const Linebacker& p){
    p.Print();
    return out;
 }
/********************************************/
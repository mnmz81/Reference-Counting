#include "Cornerback.h"

using namespace std;
/********************************************/
Cornerback::Cornerback():DefensiePacket(){this->kind='C';}
/********************************************/
Cornerback::Cornerback(int n):DefensiePacket(n){this->kind='C';}
/********************************************/
Cornerback::Cornerback(string id_):DefensiePacket(id_){this->kind='C';}
/********************************************/
Cornerback::Cornerback(const Cornerback& cp):DefensiePacket(cp){this->kind='C';}
/********************************************/
Cornerback::~Cornerback(){}
/********************************************/
void Cornerback::endGeneration(){
    vector<int> newGeneration;
    for(int i=0;i<dim;i++){
        int bitDeffent=binaryString[i];
        if(bitDeffent==rand()%dim+1){
            if(bitDeffent==1)
                newGeneration.push_back(0);
            else
               newGeneration.push_back(1);
        }
        else
            newGeneration.push_back(binaryString[i]);   
    }
    this->binaryString.clear();
    this->binaryString.assign(newGeneration.begin(),newGeneration.end());
 }
/********************************************/
void Cornerback::Print() const{
    DefensiePacket::Print();
 }
/********************************************/
ostream& operator<<(ostream& out, const Cornerback& p){
    p.Print();
    return out;
 }
/********************************************/
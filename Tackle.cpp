
#include "Tackle.h"

using namespace std;
/********************************************/
Tackle::Tackle():DefensiePacket(){this->kind='T';}
/********************************************/
Tackle::Tackle(int n):DefensiePacket(n){this->kind='T';}
/********************************************/
Tackle::Tackle(string id_):DefensiePacket(id_){this->kind='T';}
/********************************************/
Tackle::Tackle(const Tackle& cp):DefensiePacket((DefensiePacket)cp){this->kind='T';}
/********************************************/
Tackle::~Tackle(){}
/********************************************/
void Tackle::endGeneration(){
    vector<int> newGeneration;
    for(int i=0;i<dim;i++){
        int bitDeffent=binaryString[i];
        if(bitDeffent==rand()%4+1){
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
void Tackle::Print() const{
    DefensiePacket::Print();
 }
/********************************************/
ostream& operator<<(ostream& out, const Tackle& p){
    p.Print();
    return out;
 }
/********************************************/

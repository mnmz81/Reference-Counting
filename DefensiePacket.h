#ifndef DEFENSIEPACKET_H_
#define  DEFENSIEPACKET_H_
#include <iostream>
#include <vector>
#include "AttackPackage.h"
    
//this class extends CyberPackage
//this class is the father of Cornerback and Linebacker and Tackle
class DefensiePacket:public CyberPackage
{
protected:
    char kind;
    int power;
    int helpUpdate(AttackPackage& temp);//calculate per Attack Package
public:
    DefensiePacket();//c'tor
    DefensiePacket(string id_);//c'tor
    DefensiePacket(int n);//c'tor
    DefensiePacket(const DefensiePacket& cp);//copy c'tor
    virtual ~DefensiePacket();//d'tor
    /***getter**/
    char GetKind(){return kind;};
    int GetPwoer(){return power;};
    /**setter**/
    void SetKind(char t){kind=t;};
    void SetString(vector<int>& temp);
    /****opertor**/
    friend ostream& operator<<(ostream&, const DefensiePacket&);
    DefensiePacket& operator=(const DefensiePacket& rhs);
     /***Functions***/
    void SetPepe(DefensiePacket& temp){this->valueCraet=temp.valueCraet;};//set new valueCraet
    void UpdatePower(vector<AttackPackage>& temp); //update the power of pakage
    virtual void Print() const;//print defensie packet
    void MakeSwap(DefensiePacket& temp,int i,int j);// swap of firest Generations
    void Loser(){this->valueCraet->refCount--;}; // update vlaue Craet thet is lose son;
};

#endif //MACRO
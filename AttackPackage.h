#ifndef ATTACKPACKGE_H_
#define ATTACKPACKGE_H_
#include <iostream>
#include "CyberPackage.h"

//this class extends CyberPackage
class AttackPackage:public CyberPackage
{
private:
    char kind;
public:
    AttackPackage();//c'tor
    AttackPackage(string id_);//c'tor
    AttackPackage(int n);//c'tor
    AttackPackage(const AttackPackage& cp);//copy c'tor
    ~AttackPackage();
     /***getter**/
    char GetKind(){return kind;};
    /****opertor**/
    AttackPackage& operator=(const AttackPackage& rhs);
    friend ostream& operator<<(ostream&, const AttackPackage&);
    /***Functions***/
    void Print() const;//print Attack Package
};

#endif //MACRO




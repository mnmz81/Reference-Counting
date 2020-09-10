
#ifndef CORNERBACK_H_
#define CORNERBACK_H_
#include <iostream>
#include "DefensiePacket.h"

//this class extends DefensiePacket
class Cornerback:public DefensiePacket
{
private:
public:
    Cornerback();//c'tor
    Cornerback(string id_);//c'tor
    Cornerback(const Cornerback& cp);//copy c'tor
    Cornerback(int  n);//c'tor
    ~Cornerback();//d'tor
    /***Functions***/
    void endGeneration();//updata String in the end of Generations
    virtual void Print() const; //print Cornerback
    /****opertor**/
    friend ostream& operator<<(ostream&, const Cornerback&);
};
#endif //MACRO
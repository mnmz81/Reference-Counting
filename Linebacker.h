
#ifndef LINEBACKER_H_
#define LINEBACKER_H_
#include "DefensiePacket.h"

//this class extends DefensiePacket
class Linebacker:public DefensiePacket
{
private:
public:
    Linebacker(/* args */);
    Linebacker(string id_);//c'tor
    Linebacker(int n);//c'tor
    Linebacker(const Linebacker& cp);//copy c'tor
    ~Linebacker();
    /***Functions***/
    virtual void Print() const; //print Linebacker
    /****opertor**/
    friend ostream& operator<<(ostream&, const Linebacker&);
};
   
#endif //
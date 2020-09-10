
#ifndef TACKLE_H_
#define TACKLE_H_
#include "DefensiePacket.h"

//this class extends DefensiePacket
class Tackle:public DefensiePacket
{
private:
public:
    Tackle();
    Tackle(int n);
    Tackle(string id_);//c'tor
    Tackle(const Tackle& cp);//copy c'tor
    ~Tackle();
    /***Functions***/
    void endGeneration();
    virtual void Print() const;
    /****opertor**/
    friend ostream& operator<<(ostream&, const Tackle&);
};
    
#endif //MACRO
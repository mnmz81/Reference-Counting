
#ifndef CYBERPACKAGE_H_
#define CYBERPACKAGE_H_
#include <iostream>
#include <vector>

//this class is the father of DefensiePacket and AttackPackage

using namespace std;
class CyberPackage
{
protected:
    vector<int> binaryString;
    int dim;
    struct TheOldOne { //remeber the first initialization and count 
        int refCount; // how much Defensie Packet Created from him
        vector<int> data;
        TheOldOne(vector<int>&);
        ~TheOldOne();
        vector<int>& GetOld(){return data;}
    };
    TheOldOne* value; //this RC for the first initialization
    TheOldOne* valueCraet; //this RC for next Generations
public:
    CyberPackage();//c'tor
    CyberPackage(string id);//c'tor
    CyberPackage(int n);//c'tor
    CyberPackage(const CyberPackage& cp);//copy c'tor
    virtual ~CyberPackage();//d'tor
    /***getter**/
    int GetDim(){return dim;};
    vector<int>&  GetString(){return binaryString;};
    /****opertor**/
    CyberPackage& operator=(const CyberPackage& rhs);
    friend ostream& operator<<(ostream&, const CyberPackage&);
    /***Functions***/
    virtual void Print() const; //print the binaryString
    void PrintTheOldOne()const;//print of first initialization
}; 

#endif //CYBERPACKAGE_H_



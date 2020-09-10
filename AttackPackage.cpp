#include <iostream>
#include "AttackPackage.h"
using namespace std;

/********************************************/
AttackPackage::AttackPackage():kind('A'){}
/********************************************/
AttackPackage::AttackPackage(int n):CyberPackage(n),kind('A'){}
/********************************************/
AttackPackage::AttackPackage(string id_):CyberPackage(id_),kind('A'){}
/********************************************/
AttackPackage::AttackPackage(const AttackPackage& cp):CyberPackage((CyberPackage)cp),kind('A'){}
/********************************************/
AttackPackage::~AttackPackage(){}
/********************************************/
void AttackPackage::Print() const{
    CyberPackage::Print(); //father function
    cout<<' '<<kind;
 }
/********************************************/
ostream& operator<<(ostream& out, const AttackPackage& p){
    p.Print();
    return out;
 }
/********************************************/
AttackPackage& AttackPackage::operator= ( const AttackPackage& rhs){
    rhs.value->refCount++;
    binaryString.clear();
    binaryString.assign(rhs.binaryString.begin(),rhs.binaryString.end());
    value=new TheOldOne(binaryString);
    if(valueCraet!=nullptr)   valueCraet->refCount--;
    valueCraet=rhs.valueCraet;
    return *this;

 }
/********************************************/
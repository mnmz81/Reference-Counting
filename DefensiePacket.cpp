
#include "DefensiePacket.h"

using namespace std;
/********************************************/
DefensiePacket::DefensiePacket():kind('D'),power(0){}
/********************************************/
DefensiePacket::DefensiePacket(int n):CyberPackage(n),kind('D'),power(0){}
/********************************************/
DefensiePacket::DefensiePacket(string id_):CyberPackage(id_),kind('D'),power(0){}
/********************************************/
DefensiePacket::DefensiePacket(const DefensiePacket& cp):CyberPackage((CyberPackage)cp),kind('D'),power(cp.power){}
/********************************************/
DefensiePacket::~DefensiePacket(){};
/********************************************/
int DefensiePacket::helpUpdate(AttackPackage& temp){
    int norm=this->dim;
    int sum=0;
    for(int i=0;i<dim;i++)
        sum=sum+(binaryString[i]*(1-temp.GetString()[i]) +temp.GetString()[i]*(1-binaryString[i]));
    return norm-sum;
 }
/********************************************/
void DefensiePacket::UpdatePower(vector<AttackPackage>& array){
    int max=-1;
    int current;
    for(AttackPackage t:array){
        current=helpUpdate(t);
        if(max<current) max=current;
    }
    power=max;
 }
/********************************************/
void DefensiePacket::Print() const{
    CyberPackage::Print();
    cout<<' '<<kind;
 }
/********************************************/
ostream& operator<<(ostream& out, const DefensiePacket& p){
    p.Print();
    return out;
 }
/********************************************/
void DefensiePacket::MakeSwap(DefensiePacket& temp,int i,int j){
    vector<int> temp1=this->value->data;
    for (; i < j; i++)
        temp1[i]=temp.value->data[i];
    this->binaryString.clear();
    this->binaryString.assign(temp1.begin(),temp1.end());
 }
/********************************************/
DefensiePacket& DefensiePacket::operator= ( const DefensiePacket& rhs){
    if(this==&rhs)   return *this;
    rhs.value->refCount++;
    binaryString.clear();
    binaryString.assign(rhs.binaryString.begin(),rhs.binaryString.end());
    value=new TheOldOne(binaryString);
    if(valueCraet!=nullptr)   valueCraet->refCount--;
    valueCraet=rhs.valueCraet;
    return *this;
 }
/********************************************/
void DefensiePacket::SetString(vector<int>& temp){
    this->binaryString.clear();
    this->binaryString.assign(temp.begin(),temp.end());
 }
/********************************************/
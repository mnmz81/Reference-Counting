
#include "CyberPackage.h"

CyberPackage::TheOldOne::TheOldOne(vector<int>& temp):refCount(1),data(temp){}
/********************************************/
CyberPackage::TheOldOne::~TheOldOne(){}
/********************************************/
CyberPackage::CyberPackage(){
    this->dim=10;
    for(int i=0;i<10;i++)
        binaryString.push_back(rand()%2);
    value=new TheOldOne(binaryString);
    valueCraet=value;
 }
/********************************************/
CyberPackage::CyberPackage(int n){
    this->dim=n;
    for(int i=0;i<dim;i++)
        binaryString.push_back(rand()%2);
    value=new TheOldOne(binaryString);
    valueCraet=value;
 }
/********************************************/
CyberPackage::CyberPackage(string id){
    int temp;
    dim=0;
    for(unsigned int i=0;i<id.size();i++){
        if((id.at(i)!='1')&&(id.at(i)!='0') )continue;
        else{
            dim++;
            temp=(id.at(i)-'0');
            if(temp>1||temp<0) throw "ERROR: Invalid input.";
            else binaryString.push_back(temp);
        }
    }
    value=new TheOldOne(binaryString);
    valueCraet=value;  
 }
/********************************************/
CyberPackage::CyberPackage(const CyberPackage& cp){
    binaryString.assign(cp.binaryString.begin(),cp.binaryString.end());
    dim=cp.dim;
    value=new TheOldOne(binaryString);
    cp.value->refCount++;
    valueCraet=cp.value;
 }
/********************************************/
CyberPackage::~CyberPackage(){
   delete value;
 }
/********************************************/
CyberPackage& CyberPackage::operator= ( const CyberPackage& rhs){
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
void CyberPackage::Print()const {
    std::vector<int>::const_iterator b=binaryString.begin();
    std::vector<int>::const_iterator e=binaryString.end();
    while(b!=e){
        cout<<*b;
        b++;
        if(b!=e) cout<<" ";
    }
 }
/********************************************/
void CyberPackage::PrintTheOldOne() const{
    std::vector<int>::const_iterator b=value->data.begin();
    std::vector<int>::const_iterator e=value->data.end();
    while(b!=e){
        cout<<*b;
        b++;
         cout<<" ";
    }
    cout<<value->refCount<<endl;
 }
/********************************************/
ostream& operator<<(ostream& out, const CyberPackage& p){
    p.Print();
    return out;
 }
/********************************************/


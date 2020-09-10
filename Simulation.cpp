
#include "Simulation.h"
#define MAXSTRING 100000
#define MAXTIME 10000000
#define MAXPACKAGE 1000


using namespace std;
/*************************************/
Simulation::Simulation():attackNumber(10),defensieNumber(10),DimOfSring(10),TimeOfSimulation(0){
    AttackPackage* temp1;
    DefensiePacket* temp2;
    for(int i=0;i<attackNumber;i++){
        temp1=new AttackPackage(DimOfSring);
        temp2=new DefensiePacket(DimOfSring);
        attackArray.push_back(*temp1);
        defensieArray.push_back(new DefensiePacket(DimOfSring));
        delete temp2;
        delete temp1;
    }
 }
/*************************************/
Simulation::Simulation(char* a,char* b){
    ifstream input1(a);
	ifstream input2(b);
    int Cnum,Tnum,Lnum;
    AttackPackage* temp;
    string line;
    if (!input1.good() || input1.eof() || !input2.good() || input2.eof()) throw "ERROR: Invalid input1.(simulation)";
    input1 >> DimOfSring >> Tnum >> Cnum >> Lnum >> TimeOfSimulation;
    input2 >> attackNumber;
    defensieNumber=Tnum+Cnum+Lnum;
    if (DimOfSring < 2 || DimOfSring > MAXSTRING||TimeOfSimulation < 0 || TimeOfSimulation > MAXTIME){
        if( Tnum < 1 ||Cnum < 1 || Lnum < 1||attackNumber < 1 || 
        attackNumber > MAXPACKAGE || defensieNumber> MAXPACKAGE){
        throw "ERROR: Invalid input2.(simulation)";
        }
    }
    getline(input2,line);
    while (!input2.eof()){
        getline(input2, line);
        temp=new AttackPackage(line);
        if(temp->GetDim()!=DimOfSring) throw "ERROR: Invalid input3.(simulation)";
        attackArray.push_back(*temp);
        delete temp;
    }
    if(attackArray.size()!=attackNumber) throw "ERROR: Invalid input4.(simulation)";
    for(int i=0;i<Tnum;i++) {defensieArray.push_back(new Tackle(DimOfSring));}
    for(int i=0;i<Cnum;i++) defensieArray.push_back(new Cornerback(DimOfSring));
    for(int i=0;i<Lnum;i++) defensieArray.push_back(new Linebacker(DimOfSring));
    input1.close();
    input2.clear();
    MaxPower=0;
 }
/*************************************/
Simulation::~Simulation(){
    defensieArray.erase(defensieArray.begin(), defensieArray.end());
    defensieArray.clear();
 }
/*************************************/
void Simulation::PrintFinish() {
    this->PrintTheLastGener();
    cout<<endl<<endl;
    this->PrintFirstGener();
    this->PrintMaxPwoer();
 }
/*************************************/
void Simulation::PrintTheLastGener(){
    for(int i=0;i<defensieArray.size();i++){
        if(typeid(*defensieArray[i])==typeid(Cornerback))
            dynamic_cast<Cornerback*>(defensieArray[i])->Print();
        else
            if (typeid(*defensieArray[i])==typeid(Linebacker))
                dynamic_cast<Linebacker*>(defensieArray[i])->Print(); 
            else
                dynamic_cast<Tackle*>(defensieArray[i])->Print();
        if(i+1!=defensieArray.size()) cout<<endl;
        }
 }
/*************************************/
void Simulation::PrintFirstGener(){
     for(DefensiePacket* t:defensieArray)
         t->PrintTheOldOne();
    cout<<endl;
 }
/*************************************/
void Simulation::UpDataPwoer(){
    for(int i=0;i<this->defensieNumber;i++){
        defensieArray[i]->UpdatePower(attackArray);
    }
 }
/*************************************/
void Simulation::PrintMaxPwoer(){
    std::vector<int>::const_iterator b=MaxString.begin();
    std::vector<int>::const_iterator e=MaxString.end();
    while(b!=e){
        cout<<*b;
        b++;
        cout<<" ";
    }
    cout<<MaxKind<<endl;
 }
/*************************************/
void Simulation::UpDateEndMove(){
    for(int i=0;i<defensieNumber;i++){
    if(typeid(*defensieArray[i])==typeid(Cornerback))
            dynamic_cast<Cornerback*>(defensieArray[i])->endGeneration();
    if(typeid(*defensieArray[i])==typeid(Tackle))
            dynamic_cast<Tackle*>(defensieArray[i])->endGeneration();
    }
 }
/*************************************/
void Simulation::Run(){
    for(int i=0;i<TimeOfSimulation;i++){
        if(ChackFinis()) break;
        UpDateTeam();
        UpDateEndMove();
        UpDataPwoer();

    }
    this->PrintFinish();
 }
/*************************************/
void Simulation::UpDateTeam(){
    int i,j,iS,iE;
    i= rand()%defensieNumber;
    j = rand()%defensieNumber;
    if(i==j){
        while(i==j){
            i= rand()%defensieNumber;
            j = rand()%defensieNumber;
        }
    } //check thet i and j not egules
    DefensiePacket temp1(*defensieArray[i]);
    DefensiePacket temp2(*defensieArray[j]);
    iS = rand() % (DimOfSring-3);
    iE = rand() % (DimOfSring - iS) + iS;
    if(iE-iS<2)
        while(iE-iS<2)
             iE = rand() % (DimOfSring - iS) + iS;
    temp1.MakeSwap(temp2,iS,iE);
    temp2.MakeSwap(temp1,iS,iE);
    sort(defensieArray.begin(), defensieArray.end(), [](DefensiePacket *d1, DefensiePacket *d2) {
        return d1->GetPwoer() < d2->GetPwoer();
    });
    this->UpdateMax();
    defensieArray[0]->Loser();
    defensieArray[1]->Loser();
    defensieArray[0]->SetPepe(temp1);   
    defensieArray[1]->SetPepe(temp2);
 }
/*************************************/
void Simulation::UpdateMax(){
    if(MaxPower<(defensieArray[defensieNumber-1]->GetPwoer())){
        MaxPower=defensieArray[defensieNumber-1]->GetPwoer();
        MaxString.clear();
        MaxString.assign(defensieArray[defensieNumber-1]->GetString().begin(),defensieArray[defensieNumber-1]->GetString().end());
        if(typeid(*defensieArray[defensieNumber-1])==typeid(Tackle)) MaxKind='T';
        if(typeid(*defensieArray[defensieNumber-1])==typeid(Linebacker)) MaxKind='L';
        if(typeid(*defensieArray[defensieNumber-1])==typeid(Cornerback)) MaxKind='C';
    }
 }
/*************************************/
bool Simulation::ChackFinis(){
    if(MaxPower==DimOfSring) return true;
    else return false;
}
/*************************************/
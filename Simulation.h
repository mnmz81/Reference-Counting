
#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <vector>
#include "CyberPackage.h"
#include "AttackPackage.h"
#include "Cornerback.h"
#include "Linebacker.h"
#include "Tackle.h"
#include<iterator>
#include <cstdlib>
#include <fstream>   	
#include <algorithm>
#include <string>
#include <typeinfo>


class Simulation
{
private:
    int attackNumber;
    int defensieNumber;
    vector<AttackPackage> attackArray;
    vector<DefensiePacket*> defensieArray;
    int DimOfSring;
    int TimeOfSimulation;
    vector<int> MaxString;
    char MaxKind;
    int MaxPower;
    void PrintTheLastGener();//help print defensieArray;
    void PrintFirstGener();//help print PrintFirstGener;
    void UpDataPwoer();//help to pupdate the power of all defensieArray
    void PrintMaxPwoer();//print the max power;
    void UpDateTeam();//
    void UpDateEndMove();
    void UpdateMax();//update Max Power
    bool ChackFinis();//check if Max Power is egules DimOfSring
public:
    Simulation();//c'tor
    Simulation(char* a,char* b);//c'tor
    ~Simulation();//d'tor
    void PrintFinish() ;//print the finish Simulation
    void Run();//steart Simulation
};
   
#endif //


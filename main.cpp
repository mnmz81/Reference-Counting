
#include <iostream>
#include <cstdlib>
#include "Simulation.h"


//this is the main function
int  main(int argv,char* argc[])
{
    srand(time(0));
    if(argv !=3) throw "ERROR: Invalid input.";
    try{
        Simulation temp(argc[1],argc[2]);
        temp.Run();
        }
    catch (const char *e){
        cerr << e << endl;
        exit(1);
    }
    return 0;

}
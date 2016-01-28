#include <iostream>
#include <stdio.h>
#include "DownwardInstruction/startTransaction.h"
#include "DownwardInstruction/stopTransaction.h"
#include "UplinkInstruction/periodicReadRegisters.h"
#include "UplinkInstruction/readState_gun.h"
#include "UplinkInstruction/readState_fault.h"


using namespace std;

int main ()
{

//        printf("StartTransaction begin\n");
//        StartTransaction startTransaction;
//        startTransaction.startexecute();

//        printf("StopTransaction begin\n");
//        StopTransaction stopTransaction;
//        stopTransaction.stopexecute();

        printf("PeriodicReadRegisters begin\n");
        PeriodicReadRegisters periodicReadRegisters;
        periodicReadRegisters.readRegistersexecute();

//        printf("ReadStateGun begin\n");
//        ReadStateGun readStateGun;
//        readStateGun.readStateGunexecute();

        ReadStateFault readStateFault;
        readStateFault.readStateFaultexecute();


}
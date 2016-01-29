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


//        printf("StopTransaction begin\n");
//        StopTransaction stopTransaction;
//        stopTransaction.stopexecute();

        printf("PeriodicReadRegisters begin\n");
        PeriodicReadRegisters periodicReadRegisters;
        periodicReadRegisters.readRegistersexecute();


//        printf("StartTransaction begin\n");
//        StartTransaction startTransaction;
//        startTransaction.startexecute();

        printf("ReadStateGun begin\n");
        ReadStateGun readStateGun;
        readStateGun.readStateGunexecute();

        printf("ReadStateFault begin\n");
        ReadStateFault readStateFault;
        readStateFault.readStateFaultexecute();


}
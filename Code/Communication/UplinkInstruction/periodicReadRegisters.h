//
// Created by zhaoguoqing on 16/1/27.
//

#ifndef ARMLIBMODUS_PERIODICREADREGISTERS_H
#define ARMLIBMODUS_PERIODICREADREGISTERS_H
#include <modbus.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>

class PeriodicReadRegisters {

public:
    void init();
    void readRegistersexecute();
    void inputRegistersexecute();
};


#endif //ARMLIBMODUS_PERIODICREADREGISTERS_H

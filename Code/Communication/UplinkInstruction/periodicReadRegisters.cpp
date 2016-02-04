//
// Created by zhaoguoqing on 16/1/27.
//

#include "periodicReadRegisters.h"

void PeriodicReadRegisters::init() {



}
void PeriodicReadRegisters::readRegistersexecute() {

    modbus_t *ctx;
    uint16_t tab_input_reg_output[16] = {};

    float avgVLL = -1;;
    int res = 0;
    int rc;
    int i;
    uint32_t tv_sec = 0;
    uint32_t tv_usec = 0;

    ctx = modbus_new_rtu("/dev/ttySP2", 9600, 'N', 8, 1);

    if (NULL == ctx) {
        printf("Unable to create libmodbus context\n");
        res = 1;
    }
    else {
        printf("created libmodbus context\n");
        modbus_set_debug(ctx, TRUE);
        rc = modbus_set_slave(ctx, 1);//读或者写操作，注意要先设置0:r 1:w
        printf("modbus_set_slave return: %d\n", rc);
        if (rc != 0) {
            printf("modbus_set_slave: %s \n", modbus_strerror(errno));
        }

        //This code is for version 3.1.2
        modbus_get_response_timeout(ctx, &tv_sec, &tv_usec);
        printf("Default response timeout:%d sec %d usec \n", tv_sec, tv_usec);

        tv_sec = 60;
        tv_usec = 0;

        modbus_set_response_timeout(ctx, tv_sec, tv_usec);
        modbus_get_response_timeout(ctx, &tv_sec, &tv_usec);
        printf("Set response timeout:%d sec %d usec \n", tv_sec, tv_usec);

        rc = modbus_connect(ctx);
        printf("modbus_connect: %d \n", rc);

        if (rc == -1) {
            printf("Connection failed: %s\n", modbus_strerror(errno));
            res = 1;
        }

        //2:操作寄存器
        std::cout << "--------write_register() and modbus_read_registers()---begin-------------------" << std::endl;
        //name:写入寄存器[MODBUS_FC_WRITE_SINGLE_REGISTER]0x06
        //名称              地址   读写类型    数据长度    寄存器数      说明
        //w_id_pile        0-7    读写       8x16      8            充电桩桩号
        //w_set_maxpower   8      读写       8x2       1            0-1000功率千分比
        //w_class_gun      9      读写       8x2       1            枪连接类型,0:A连接,1:B连接,2:C连接
        uint16_t w_id_pile[8] = {12, 13, 14, 15, 16, 17, 18, 19};
        uint16_t w_set_maxpower[1] = {500}; //千分比
        uint16_t w_class_gun[1] = {2};
        uint16_t w_addr_charge[1] = {1};

        //rc = modbus_write_registers(ctx, 0, sizeof(w_id_pile), w_id_pile);
        rc = modbus_write_register(ctx, 8, 500);
        rc = modbus_write_register(ctx,9,2);
        //rc = modbus_write_register(ctx,10,1);

        //name:读取寄存器[MODBUS_FC_READ_HOLDING_REGISTERS] 0x03
        //nb 不能大于125
        rc = modbus_read_registers(ctx, 0, 8, w_id_pile);
        rc = modbus_read_registers(ctx, 8, 1, w_set_maxpower);
        rc = modbus_read_registers(ctx, 9, 1, w_class_gun);
        rc = modbus_read_registers(ctx,10, 1, w_addr_charge);

        for (i = 0; i < 8; i++) {
            printf("w_id_pile:reg[%d]=%d (0x%X)\n", i, w_id_pile[i], w_id_pile[i]);
        }
        for (i = 0; i < 1; i++) {
            printf("w_set_maxpower:reg[%d]=%d (0x%X)\n", i, w_set_maxpower[i], w_set_maxpower[i]);
        }
        for (i = 0; i < 1; i++) {
            printf("w_class_gun:reg[%d]=%d (0x%X)\n", i, w_class_gun[i], w_class_gun[i]);
        }
        for (i = 0; i < 1; i++) {
            printf("w_addr_charge:reg[%d]=%d (0x%X)\n", i, w_addr_charge[i], w_addr_charge[i]);
        }

        std::cout << "--------modbus_write_register() and modbus_read_registers()---end-------------------" <<
        std::endl;

    }

}

void PeriodicReadRegisters::inputRegistersexecute() {



}
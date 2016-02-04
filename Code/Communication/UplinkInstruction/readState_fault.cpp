//
// Created by zhaoguoqing on 16/1/27.
//

#include "readState_fault.h"

void ReadStateFault::readStateFaultexecute() {

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
        rc = modbus_set_slave(ctx, 1);
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

        //读取故障的状态[1]区输入继电器读功能码 0x02
        uint16_t r_state_fault[8]={0,0,0,0,0,0,0,0};
        uint16_t r_state_charge[1]={0};
        rc = modbus_read_input_registers(ctx,8,1,r_state_charge);
        rc = modbus_read_input_registers(ctx,9,8,r_state_fault);

        //枪充电状态：
        // 0-未连接；
        // 1-连接车辆；
        // 2-充电引导结束；
        // 3-充电中；
        // 4-充电结束；
        // 5-错误。
        for (i = 0; i < 1; i++) {
            printf("r_state_charge:registers[%d]=%d (0x%X)\n", i, r_state_charge[i], r_state_charge[i]);
        }
        for (i = 0; i < 8; i++) {
            printf("r_state_fault:registers[%d]=%d (0x%X)\n", i, r_state_fault[i], r_state_fault[i]);
        }


    }

}

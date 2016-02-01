//
// Created by zhaoguoqing on 16/1/25.
//

#include "startTransaction.h"


void StartTransaction::startexecute() {
    modbus_t *ctx;
    uint16_t tab_input_reg_output[16] = {};

    float avgVLL = -1;;
    int res = 0;
    int rc;
    int i;
    uint32_t tv_sec = 0;
    uint32_t tv_usec = 0;

    ctx = modbus_new_rtu("/dev/ttySP3", 9600, 'N', 8, 1);

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

        //1:操作继电器
        std::cout << "--------modbus_write_bit() and modbus_read_bits()---begin-------------------" << std::endl;
        //name:写入继电器[MODBUS_FC_WRITE_SINGLE_REGISTER]0x06
        //名称              地址   读写类型    数据长度    寄存器数      说明
        //w_mode_opera     0.0    读写       1bit                   充电运行方式                  0:独立1:在线
        //w_en_charge      1.0    读写       1bit                   允许禁止桩充电打开接触器        0:关闭1:打开
        //w_en_lock        1.1    读写       1bit                   电子锁动作                    0:闭合1:打开
        //w_reset_pile     2.0    读写       1bit                   复位桩操作                    0:无效1:有效
        //w_reset_par      2.1    读写       1bit                   恢复默认值操作                 0:无效1:有效


        //开始充电-16进制
//        rc = modbus_write_bit(ctx,0X0000, 1);//0.0---0X0000
//        rc = modbus_write_bit(ctx,0X0008, 1);//接触器不打开是不能充电的//1.0---0X0008
//        rc = modbus_write_bit(ctx,0X0009, 0);//1.1----0X0009
//        rc = modbus_write_bit(ctx,0X0010, 0);//2.0----0X0010
//        rc = modbus_write_bit(ctx,0X0011, 0);//2.1----0X0011
        //开始充电-10进制
        rc = modbus_write_bit(ctx,0, 1);//0.0---0X0000
        rc = modbus_write_bit(ctx,8, 1);//接触器不打开是不能充电的//1.0---0X0008
        rc = modbus_write_bit(ctx,9, 0);//1.1----0X0009
        rc = modbus_write_bit(ctx,16, 0);//2.0----0X0010
        rc = modbus_write_bit(ctx,17, 0);//2.1----0X0011


        //读取继电器
        uint8_t  w_mode_opera[1] = {0};
        uint8_t  w_en_charge[1] = {0};
        uint8_t  w_en_lock[1] = {0};
        uint8_t  w_reset_pile[1] = {0};
        uint8_t  w_reset_par[1] = {0};

        rc = modbus_read_bits(ctx,0,1,w_mode_opera);
        rc = modbus_read_bits(ctx,8,1,w_en_charge);
        rc = modbus_read_bits(ctx,9,1,w_en_lock);
        rc = modbus_read_bits(ctx,16,1,w_reset_pile);
        rc = modbus_read_bits(ctx,17,1,w_reset_par);

        printf("w_mode_opera:bit[%d]=%d (0x%X)\n", i, w_mode_opera[0], w_mode_opera[0]);
        printf("w_en_charge:bit[%d]=%d (0x%X)\n", i, w_en_charge[0], w_en_charge[0]);
        printf("w_en_lock:bit[%d]=%d (0x%X)\n", i, w_en_lock[0], w_en_lock[0]);
        printf("w_reset_pile:bit[%d]=%d (0x%X)\n", i, w_reset_pile[0], w_reset_pile[0]);
        printf("w_reset_par:bit[%d]=%d (0x%X)\n", i, w_reset_par[0], w_reset_par[0]);




    }
}

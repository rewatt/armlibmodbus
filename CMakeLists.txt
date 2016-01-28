cmake_minimum_required(VERSION 3.4)
project(armlibmodus)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_C_COMPILER   /Volumes/arm-x/bin/arm-none-linux-gnueabi-gcc)
SET(CMAKE_CXX_COMPILER /Volumes/arm-x//bin/arm-none-linux-gnueabi-g++)

include_directories("${MDB_DIR}/include/modbus")
link_directories("${MDB_DIR}/lib")
list(APPEND extra_libs "modbus")

# Boost
find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    list(APPEND extra_libs ${Boost_LIBRARIES})
    #    target_link_libraries(hello ${Boost_LIBS})
endif()

#DownwardInstruction-启动充电
set(SOURCE_FILES Code/Communication/main.cpp Code/Communication/DownwardInstruction/startTransaction.cpp Code/Communication/DownwardInstruction/startTransaction.h Code/Communication/DownwardInstruction/stopTransaction.cpp Code/Communication/DownwardInstruction/stopTransaction.h Code/Communication/UplinkInstruction/periodicReadRegisters.cpp Code/Communication/UplinkInstruction/periodicReadRegisters.h Code/Communication/UplinkInstruction/readState_gun.cpp Code/Communication/UplinkInstruction/readState_gun.h Code/Communication/UplinkInstruction/readState_fault.cpp Code/Communication/UplinkInstruction/readState_fault.h)



#232 电表
set(armlibmodus_Code
    Code/Communication/comm_interface.cc
    Code/Communication/comm_adapter_interface.cc
    Code/Communication/Ethernet/qtcp_socket_adapter.cc
    Code/Communication/Ethernet/tcp_socket.cc
    Code/Communication/RTU/serial_portrs_232.cc
)


add_executable(armlibmodus ${SOURCE_FILES})

target_link_libraries(armlibmodus ${extra_libs})
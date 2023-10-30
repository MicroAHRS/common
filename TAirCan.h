/*!
 *
 *
 * @section author Author
 *
 * Written by Evgeny Pronin titan.the.proger@gmail.com
 *
 * @section license License
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
#ifndef TAIRCAN_H
#define TAIRCAN_H

#include <stdint.h>

#ifndef CAN_5KBPS
    #define CAN_5KBPS           1
    #define CAN_10KBPS          2
    #define CAN_20KBPS          3
    #define CAN_25KBPS          4
    #define CAN_31K25BPS        5
    #define CAN_33KBPS          6
    #define CAN_40KBPS          7
    #define CAN_50KBPS          8
    #define CAN_80KBPS          9
    #define CAN_83K3BPS         10
    #define CAN_95KBPS          11
    #define CAN_100KBPS         12
    #define CAN_125KBPS         13
    #define CAN_200KBPS         14
    #define CAN_250KBPS         15
    #define CAN_500KBPS         16
    #define CAN_666KBPS         17
    #define CAN_1000KBPS        18
#endif

class TMCPCan;
class TCanMessageBase;

class TAirCan
{

public:
    TAirCan(int chip_select_pin, int speed);
    ~TAirCan();

    bool init();
    bool sendMessage(TCanMessageBase* message );

private:

    TMCPCan* m_can;
    int      m_speed;
    bool     m_ok;
};

#endif

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
#include "TAirCan.h"

#include "TMCPCan.h"

#include "shared/CanMessage/TCanMessageBase.h"

TAirCan::TAirCan(int chip_select_pin, int speed)
{
    m_speed = speed;
    m_can = new TMCPCan(chip_select_pin);
    m_ok = false;
}

TAirCan::~TAirCan()
{
    delete m_can;
}

bool TAirCan::init()
{
    if(m_can->begin(m_speed, MCP_8MHz) != CAN_OK)
        return false;
    m_ok = true;
    return true;
}

bool TAirCan::sendMessage(TCanMessageBase* message )
{
    if(!m_ok)
        return false;
    message->encode();
    m_can->sendMsgBuf(message->m_id, false, message->m_len, message->m_data);
    return true;
}




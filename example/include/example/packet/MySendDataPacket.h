#ifndef SENDDATAPACKET_H
#define SENDDATAPACKET_H


#include "packet/SendDataPacketInterface.h"
#include <memory>

using namespace Torosamy;

class MySendDataPacket : public SendDataPacketInterface{
public:
    MySendDataPacket(const int& id);
    int writeData(unsigned char* dataArr,const int& startIndex) override;

    float2uchar yourFloat;
    short2uchar yourNum;
    bool2uchar yourBool;
};


#endif //SENDDATAPACKET_H

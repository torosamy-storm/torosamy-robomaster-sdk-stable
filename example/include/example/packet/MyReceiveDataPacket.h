#ifndef RECEIVEDATAPACKET_H
#define RECEIVEDATAPACKET_H

#include "packet/ReceiveDataPacketInterface.h"
#include <memory>

using namespace Torosamy;

class MyReceiveDataPacket : public ReceiveDataPacketInterface {
public:
    MyReceiveDataPacket(const int& id);
    int readData(const unsigned char* const dataArr,const int& startIndex) override;


    float2uchar myFloat;
    short2uchar myNum;
    bool2uchar myBool;
};



#endif

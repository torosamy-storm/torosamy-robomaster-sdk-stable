#ifndef RECEIVEDATAPACKET_H
#define RECEIVEDATAPACKET_H

#include "packet/ReceiveDataPacketInterface.h"
#include <memory>

class MyReceiveDataPacket : public Torosamy::ReceiveDataPacketInterface {
    using float2uchar = Torosamy::float2uchar;
    using short2uchar = Torosamy::short2uchar;
    using bool2uchar = Torosamy::bool2uchar;
public:
    MyReceiveDataPacket(const int& id);
    int readData(const unsigned char* const dataArr,const int& startIndex) override;
    void initData() override;

    float2uchar myFloat;
    short2uchar myNum;
    bool2uchar myBool;
};



#endif

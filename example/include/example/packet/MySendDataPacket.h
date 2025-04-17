#ifndef SENDDATAPACKET_H
#define SENDDATAPACKET_H


#include "packet/SendDataPacketInterface.h"
#include <memory>

class MySendDataPacket : public Torosamy::SendDataPacketInterface{
    using float2uchar = Torosamy::float2uchar;
    using short2uchar = Torosamy::short2uchar;
    using bool2uchar = Torosamy::bool2uchar;
public:
    MySendDataPacket(const int& id);
    int writeData(unsigned char* dataArr,const int& startIndex) override;
    void initData() override;
    float2uchar yourFloat;
    short2uchar yourNum;
    bool2uchar yourBool;
};


#endif //SENDDATAPACKET_H

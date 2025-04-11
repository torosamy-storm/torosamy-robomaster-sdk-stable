#ifndef RECEIVEDATAPACKETINTERFACE_H
#define RECEIVEDATAPACKETINTERFACE_H



#include "DataPacket.h"
namespace Torosamy {
    class ReceiveDataPacketInterface : public DataPacket {
    public:
        ReceiveDataPacketInterface(const int& id);
        virtual int readData(const unsigned char* const dataArr,const int& startIndex) = 0;
    };
}


#endif
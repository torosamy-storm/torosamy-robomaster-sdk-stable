#ifndef SENDDATAPACKETINTERFACE_H
#define SENDDATAPACKETINTERFACE_H




#include "DataPacket.h"
namespace Torosamy {
    class SendDataPacketInterface : public DataPacket {
    public:
        SendDataPacketInterface(const int& id);
        virtual int writeData(unsigned char* dataArr,const int& startIndex) = 0;
    };
}


#endif


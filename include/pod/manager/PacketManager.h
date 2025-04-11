#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H
#include "packet/ReceiveDataPacketInterface.h"
#include "packet/SendDataPacketInterface.h"
#include <memory>
#include <iostream>
#include <vector>
#include <mutex>
namespace Torosamy {
    class PacketManager {
    public:
        std::shared_ptr<PacketManager> addReceivePacket(const std::shared_ptr<ReceiveDataPacketInterface>& packetPtr);
        std::shared_ptr<PacketManager> addSendPacket(const std::shared_ptr<SendDataPacketInterface>& packetPtr);
        std::shared_ptr<PacketManager> addPacket(const std::shared_ptr<DataPacket>& packetPtr);
    
        int getSendPacketSize() const;
        int getReceivePacketSize() const;
        static std::shared_ptr<PacketManager> getInstance();
        template <typename T>
        std::shared_ptr<T> getSendPacketById(const int& id) const;
    
        template <typename T>
        std::shared_ptr<T> getReceivePacketById(const int& id) const;
    
        template <typename T>
        std::shared_ptr<T> getPacketById(const int& id) const;
    
    private:
        PacketManager();
        static std::once_flag initFlag;
        static std::shared_ptr<PacketManager> instance;
        std::vector<std::shared_ptr<DataPacket>> mDataPacketPtrs;
        std::vector<std::shared_ptr<SendDataPacketInterface>> mSendDataPacketPtrs;
        std::vector<std::shared_ptr<ReceiveDataPacketInterface>> mReceiveDataPacketPtrs;
    };
        
}

#include "PacketManager.hpp"

#endif //PACKETMANAGER_H

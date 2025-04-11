#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

#include "PacketManager.h"
#include <stdexcept>
#include <iostream>

namespace Torosamy {
    template <typename T>
    std::shared_ptr<T> PacketManager::getReceivePacketById(const int& id) const{
        for (const std::shared_ptr<ReceiveDataPacketInterface>& ptr : mReceiveDataPacketPtrs) {
            if (ptr->getId() == id) {
                return std::dynamic_pointer_cast<T>(ptr);
            }
        }

        try {
            throw std::out_of_range("packet not found with id: " + std::to_string(id));
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
        return nullptr; 
    }


    template <typename T>
    std::shared_ptr<T> PacketManager::getSendPacketById(const int& id) const{
        for (const std::shared_ptr<SendDataPacketInterface>& ptr : mSendDataPacketPtrs) {
            if (ptr->getId() == id) {
                return std::dynamic_pointer_cast<T>(ptr);
            }
        }

        try {
            throw std::out_of_range("packet not found with id: " + std::to_string(id));
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
        return nullptr;

    }


    template <typename T>
    std::shared_ptr<T> PacketManager::getPacketById(const int& id) const{
        for (const std::shared_ptr<DataPacket>& ptr : mDataPacketPtrs) {
            if (ptr->getId() == id) {
                return std::dynamic_pointer_cast<T>(ptr);
            }
        }

        try {
            throw std::out_of_range("packet not found with id: " + std::to_string(id));
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
         return nullptr;
    }
}

#endif //PACKETMANAGER_HPP
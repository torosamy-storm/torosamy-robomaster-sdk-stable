#ifndef SERIALPORT_H
#define SERIALPORT_H


#include "utils/DataUtils.h"
#include <iostream>
#include <map>
#include <termios.h>


namespace Torosamy {
    class SerialPort {
    public:
        SerialPort(const YAML::Node& fileReader, const int& fd);
        int getFd() const;
        void sendData();
        void receiveData();
        void stopSend();
        void stopReceive();
        void stop();
        // std::function<void()> sendData;
        // std::function<void()> receiveData;
        static uint8_t crc8Check(uint8_t *addr, int len);
    private:
        bool init();
        bool initOptions();
        bool initSpeed();
        bool initParity();
        bool mSendRunning;
        bool mReceiveRunning;
        static speed_t mSpeedArr[];
        static speed_t mNameArr[];
        termios mOptions;
        const int mBaudSpeed;
        const int mFd;
        const std::string mUsbPath;
        std::map<int,std::pair<unsigned char, unsigned char>> mSendSelect;
        class ReceiveOption {
        public:
            ReceiveOption(const YAML::Node& fileReader, const int& id);
            int getId() const;
            const unsigned char getHead() const;
            const unsigned char getTail() const;
            bool isCheckHead() const;
            bool isCheckCrc() const;
            bool isCheckTail() const;
        private:
            const int mId;
            const unsigned char mHead;
            const unsigned char mTail;
            const bool mCheckHead;
            const bool mCheckTail;
            const bool mCheckCrc; 
        };
        std::vector<ReceiveOption> mReceiveSelect;

        //setParity
        const int mDatabits;
        const int mStopbits;
        const int mParity;
    
        bool mIsInit;
    };
}



#endif //SERIALPORT_H

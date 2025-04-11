#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H
#include <memory>
#include <thread>
#include "pod/SerialPort.h"
#include <mutex>

namespace Torosamy {
    class SerialPortManager {
    public:
        std::shared_ptr<SerialPortManager> addSeritalPort(const std::shared_ptr<SerialPort>& seritalPortPtr);
        
        void detachTasks();
        bool detachSendTasks();
        bool detachReceiveTasks();
        
        void stopTasks();
        void stopSendTasks();
        void stopReceiveTasks();
        void reloadSerialPorts();
        void releaseSerialPorts();
        void loadSerialPorts();
    
        bool loadSendTasks(std::vector<std::thread>& tasks);
        bool loadReceiveTasks(std::vector<std::thread>& tasks);
        int getSize() const;
        static std::shared_ptr<SerialPortManager> getInstance();
    private:
        static std::shared_ptr<SerialPortManager> instance;
        static std::once_flag initFlag;
        bool isSendTaskLoaded;
        bool isReceiveTaskLoaded;
        SerialPortManager();
        std::vector<std::shared_ptr<SerialPort>> mSeritalPortPtrs;
    };
        
}


#endif // SERIALPORTMANAGER_H

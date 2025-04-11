#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H


#include <thread>
#include <iostream>
#include <mutex>
#include "pod/camera/Camera.h"

namespace Torosamy {
    class CameraManager {
    public:
        std::shared_ptr<CameraManager> addCamera(const std::shared_ptr<Camera>& cameraPtr);
        int getSize() const;
        bool detachTasks();
        bool loadTasks(std::vector<std::thread>& tasks);
        bool openCameras();
        
        bool startTasks();
        bool startUpdateCameras();
        bool stopUpdateCameras();
        bool stopCameras();
    
    
        
        template <typename T>
        std::shared_ptr<T> getCameraById(const int& id) const;
        
        static std::shared_ptr<CameraManager> getInstance();
        ~CameraManager() = default;
    private:
        bool isOpened;
        bool isLoaded;
        static std::shared_ptr<CameraManager> instance;
        static std::once_flag initFlag;
    
        std::vector<std::shared_ptr<Camera>> mCameraPtrs;
    
        CameraManager();
        
    };
}

#endif
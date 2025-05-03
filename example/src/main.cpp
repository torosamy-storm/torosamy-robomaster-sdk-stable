
#include "pod/manager/PacketManager.h"
#include "pod/manager/ModuleManager.h"
#include "pod/manager/SerialPortManager.h"
#include "pod/manager/CameraManager.h"
#include "packet/ColorType.h"
#include "pod/camera/VideoCamera.h"
#include "example/MyModule.h"
#include "example/packet/MyReceiveDataPacket.h"
#include "example/packet/MySendDataPacket.h"
int main() {
    using namespace Torosamy;
    CameraManager::getInstance()->openCameras();
    CameraManager::getInstance()->startUpdateCameras();
    PacketManager::getInstance()
        ->addReceivePacket(std::make_shared<MyReceiveDataPacket>(0))
        ->addSendPacket(std::make_shared<MySendDataPacket>(0));

    SerialPortManager::getInstance()->detachTasks();

    
    // ModuleManager::getInstance()
    //     ->addModules(MyModule::makeModules())
    //     ->detachTasks();

    if (targetColor == ColorType::RED) {
        std::cout<<"the target color: red"<<std::endl;
    }
    
    cv::Mat img;
    std::shared_ptr<VideoCamera> camera = CameraManager::getInstance()->getCameraById<VideoCamera>(0);
    while(true) {
        camera->updateSrc();
        camera->cloneSrc(img);
        // std::cout<<"you can do other things "<<std::endl;
        if(!img.empty())imshow("my img", img);
        cv::waitKey(camera->getTimeOff());
    }
    return 0;
}

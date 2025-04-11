
#include "pod/manager/PacketManager.h"
#include "pod/manager/ModuleManager.h"
#include "pod/manager/SerialPortManager.h"
#include "pod/manager/CameraManager.h"
#include "example/MyModule.h"
#include "example/packet/MyReceiveDataPacket.h"
#include "example/packet/MySendDataPacket.h"
int main() {
    using namespace Torosamy;
    CameraManager::getInstance()->openCameras();

    PacketManager::getInstance()
        ->addReceivePacket(std::make_shared<MyReceiveDataPacket>(0))
        ->addSendPacket(std::make_shared<MySendDataPacket>(0));

    SerialPortManager::getInstance()->detachTasks();

    
    ModuleManager::getInstance()
        ->addModules(MyModule::makeModules())
        ->detachTasks();


    cv::Mat img;
    std::shared_ptr<VideoCamera> camera = CameraManager::getInstance()->getCameraById<VideoCamera>(0);
    while(true) {
        camera->updateSrc();
        camera->cloneSrc(img);
        std::cout<<"you can do other things "<<std::endl;
        imshow("my img", img);
        cv::waitKey(camera->getTimeOff());
    }
    return 0;
}

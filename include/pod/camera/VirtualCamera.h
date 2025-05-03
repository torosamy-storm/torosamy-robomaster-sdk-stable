#ifndef VIRTUALCAMERA_H
#define VIRTUALCAMERA_H
#include "Camera.h"

namespace Torosamy {
    class VirtualCamera:public Camera {
    public:
        VirtualCamera(const YAML::Node& fileReader, const int& id);
        bool updateSrc() override;
        bool openCamera() override;
        bool releaseCamera() override;
        // bool cloneSrc(cv::Mat& outSrc) const override;
        bool cloneSrc(cv::Mat& outSrc) override;
        bool setSize();
    
        static int getListIndexById(const int& id);
    private:
        static std::vector<int> mIds;
        cv::VideoCapture mVideoCapture;
        bool mSendedUpdateBufferMsg;
    };
        
}




#endif // VIRTUALCAMERA_H

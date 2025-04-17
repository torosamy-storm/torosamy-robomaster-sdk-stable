#ifndef VIDEOCAMERA_H
#define VIDEOCAMERA_H

#include "Camera.h"


namespace Torosamy {
    class VideoCamera:public Camera {
    public:
        VideoCamera(const YAML::Node& fileReader, const int& id);
        bool updateSrc() override;
        bool openCamera() override;
        void releaseCamera() override;
        // bool cloneSrc(cv::Mat& outSrc) const override;
        bool cloneSrc(cv::Mat& outSrc) override;
        bool setSize();
    
        static int getListIndexById(const int& id);
    private:
        bool mSendedUpdateBufferMsg;
        static std::vector<int> mIds;
        cv::VideoCapture mVideoCapture;
        const std::string mFileName;
    
    };
}







#endif // VIDEOCAMERA_H

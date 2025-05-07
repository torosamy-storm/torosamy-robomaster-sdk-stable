#ifndef DAHUACAMERA_H
#define DAHUACAMERA_H
#include "pod/camera/Camera.h"
#include "pod/camera/DahuaCamera/GenICam/Camera.h"

namespace Torosamy {
    class DahuaCamera : public Camera{
    public:
        DahuaCamera(const YAML::Node& fileReader, const int& id);
        bool updateSrc() override;
        bool openCamera() override;
        bool releaseCamera() override;
        // bool cloneSrc(cv::Mat& outSrc) const override;
        bool cloneSrc(cv::Mat& outSrc) override;
        bool checkUSB() const;
        const unsigned char* getBuffer() const;
        bool restartCamera();
        bool displayDeviceInfo() const;
        void setCameraIP();
        bool setCameraParam();
        bool setGrabMode(const bool& bContious);
        bool setExposureTime(const bool& bAutoExposure);
        bool setStreamThread();
        bool setROI(const int64_t& nX, const int64_t& nY, const int64_t& nWidth, const int64_t& nHeight);
        static int getListIndexById(const int& id);
        static void printAllSn();
    private:
        const int mBufferWaitTime;
        const std::string mUsbPath;
        const std::string mSerialNumber;
        static std::vector<int> mIds;
        Dahua::GenICam::ICameraPtr mCameraSptr;
        Dahua::GenICam::IStreamSourcePtr mImgGetThread;
        Dahua::GenICam::CFrame mFrame;
        int mnBGRBufferSize;
        unsigned char* mpBGRbuffer;
        const int mExposure;
        const double mRgbBlue;
        const double mRgbGreen;
        const double mRgbRed;
    };
        
}


#endif // DAHUACAMERA_H

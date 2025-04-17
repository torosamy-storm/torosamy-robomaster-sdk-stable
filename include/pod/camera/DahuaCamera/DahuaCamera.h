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
        void releaseCamera() override;
        // bool cloneSrc(cv::Mat& outSrc) const override;
        bool cloneSrc(cv::Mat& outSrc) override;
        
        const unsigned char* getBuffer() const;
        void restartCamera();
        bool findDevice();
        bool displayDeviceInfo() const;
        void setCameraIP();
        bool setCameraParam();
        bool setGrabMode(const bool& bContious);
        bool setExposureTime(const bool& bAutoExposure);
        bool setStreamThread();
        bool setROI(const int64_t& nX, const int64_t& nY, const int64_t& nWidth, const int64_t& nHeight);
        static int getListIndexById(const int& id);
        
    private:
        static Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> mCameraPtrList;
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

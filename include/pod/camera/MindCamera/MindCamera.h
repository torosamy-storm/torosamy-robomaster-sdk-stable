#ifndef MINDCAMERA_H
#define MINDCAMERA_H
#include "pod/camera/Camera.h"
#include "CameraDefine.h"
#include "opencv2/opencv.hpp"

namespace Torosamy {
    class MindCamera : public Camera {
    public:
        MindCamera(const YAML::Node& fileReader, const int& id);
        // 启动相机
        bool openCamera() override;
        void releaseCamera() override;
        // bool cloneSrc(cv::Mat& outSrc) const override;
        bool cloneSrc(cv::Mat& outSrc) override;
        // 更新现实原始图像
        bool updateSrc() override;
    
    
        // 重启摄像机
        bool restartCamera();
        //设置锐度
        bool setSharpness();
        bool setCameraParam();
        // 设置曝光时间
        bool setExposureTime() const;
        // 设置图像增益
        bool setGain() const;
        // 设置伽马
        bool setGamma() const;
        bool setSize();
        bool setFrameSpeed() const;
        static int getListIndexById(const int& id);
    
        const unsigned char* getBuffer() const;
    private:
        // 曝光时间
        const double mExposureTime;
        // 曝光增益
        const int mExposureValue;
        // R gain
        const int mGainRed;
        // G gain
        const int mGainGreen;
        // B Gain
        const int mGainBlue;
        // 相机伽马
        const int mCameraGamma;
        // 锐度
        const int mSharpness;

        const int mFrameSpeedInt;
        int mCameraCountsInt;
        int mChannel;
        // 相机的句柄
        int mCameraHandle;


    
        static std::vector<int> mIds;
    
        BYTE* mPbyBuffer;
        // 处理后数据缓存区
        unsigned char* mGpRgbBuffer;
        //IplImage* mIplImage;
    
        tSdkImageResolution mResolution;
        tSdkCameraDevInfo mCameraList[10];
        tSdkFrameHead mFrameHead;
        // 设备描述信息
        tSdkCameraCapbility mCapability;
    };
}




#endif //MINDCAMERA_H

#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>
#include <yaml-cpp/yaml.h>
#include <mutex>
namespace Torosamy {

    enum class CameraType {
        DAHUA = 0,
        MIND = 1,
        DAHENG = 2,
        VIRTUAL = 3,
        VIDEO = 4
    };
    
    class Camera{
    public:
        Camera(const YAML::Node& fileReader, const int& id);
        virtual ~Camera() = default;
        virtual bool updateSrc() = 0;
        virtual bool openCamera() = 0;
        virtual void releaseCamera() = 0;
    
        // virtual bool cloneSrc(cv::Mat& outSrc) const = 0;
        virtual bool cloneSrc(cv::Mat& outSrc) = 0;
        
        void stopRunning();
        void startRunning();
        void stopUpdateSrc();
        void startUpdateSrc();
        void printInfo() const;
        void setCameraMatrix(const std::vector<double>& matrix);
        void setDistCoeffs(const std::vector<double>& matrix);
        void setRectificationMatrix(const std::vector<double>& matrix);
        void setProjectionMatrix(const std::vector<double>& matrix);
    
        int getId() const;
        int getTimeOff() const;
        int getWidth() const;
        int getHeight() const;
        const cv::Mat& getCameraMatrix() const;
        const cv::Mat& getDistCoeffs() const;
        const cv::Mat& getRectificationMatrix() const;
        const cv::Mat& getProjectionMatrix() const;
        CameraType getType() const;
        bool isRunning() const;
        bool updateEnabled() const;
    protected:
        std::mutex mBufferMutex;
        const bool mCloneSafe;
        bool mRunning;
        bool mUpdateEnable;
        const int mId;
        cv::Mat mCameraMatrix;
        cv::Mat mDistCoeffs;
        cv::Mat mRectificationMatrix;
        cv::Mat mProjectionMatrix;
        const CameraType mCameraType;
        const int mTimeOff;
        const int mWidth;
        const int mHeight;
    };
    
}


#endif //CAMERA_H

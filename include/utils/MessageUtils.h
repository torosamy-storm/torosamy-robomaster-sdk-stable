#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H
#include <iostream>
#include <opencv2/opencv.hpp>
namespace Torosamy {
    using TIME = std::chrono::steady_clock::time_point ;
    class MessageUtils {
    public:
        static void circle(cv::Mat& outSrc, const cv::Point2f& point);
        static void circle(cv::Mat& outSrc, const cv::Point2f& point, const int& color);
        static void putText(cv::Mat& outSrc, const std::string& info, const cv::Point2f& point);
        static void line(cv::Mat& outSrc, const cv::Point2f& point1, const cv::Point2f& point2);
        static TIME getTimePoint();
        static double getTimeByPoint(const TIME& startTime, const TIME& endTime);
        static double getTimeByPoint(const TIME& startTime);
        static double getFpsByTime(const double& time);
        static double getFpsByTimePoint(const TIME& startTime);
    private:
        MessageUtils() = default;
        ~MessageUtils() = delete;
        MessageUtils(const MessageUtils&) = delete;
        MessageUtils& operator=(const MessageUtils&) = delete;
        MessageUtils(MessageUtils&&) = delete;
        MessageUtils& operator=(MessageUtils&&) = delete;
    };
}


#endif // MESSAGEUTILS_H

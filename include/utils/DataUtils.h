#ifndef DATAUTILS_H
#define DATAUTILS_H
#include <iostream>
#include <chrono>
#include <yaml-cpp/yaml.h>

namespace Torosamy {
    class DataUtils {
    public:
        static unsigned char unsignedChar(const int& value);
    private:
        DataUtils() = default;
        ~DataUtils() = delete;
        DataUtils(const DataUtils&) = delete;
        DataUtils& operator=(const DataUtils&) = delete;
        DataUtils(DataUtils&&) = delete;
        DataUtils& operator=(DataUtils&&) = delete;
    };
}


#endif // DATAUTILS_H

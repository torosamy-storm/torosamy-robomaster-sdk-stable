#ifndef COLORTYPE_H
#define COLORTYPE_H

#include <yaml-cpp/yaml.h>

namespace Torosamy{
    enum class ColorType {
        RED,
        BLUE
    };


    extern const ColorType targetColor;
}

#endif
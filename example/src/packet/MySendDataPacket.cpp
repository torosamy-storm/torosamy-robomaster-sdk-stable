#include "example/packet/MySendDataPacket.h"
#include "opencv2/opencv.hpp"
#include <iostream>


MySendDataPacket::MySendDataPacket(const int& id):
    SendDataPacketInterface(id) {
    this->mSize = 7;
    initData();
}
void MySendDataPacket::initData() {
    yourFloat.f = 0;
    yourNum.s = 0;
    yourBool.b = false;
}



int MySendDataPacket::writeData(unsigned char* dataArr,const int& startIndex) {
    int index = 0;
    dataArr[startIndex + index++] = this->yourFloat.c[0];
    dataArr[startIndex + index++] = this->yourFloat.c[1];
    dataArr[startIndex + index++] = this->yourFloat.c[2];
    dataArr[startIndex + index++] = this->yourFloat.c[3];

    dataArr[startIndex + index++] = this->yourNum.c[0];
    dataArr[startIndex + index++] = this->yourNum.c[1];

    dataArr[startIndex + index++] = this->yourBool.c[0];

    return mSize;
}



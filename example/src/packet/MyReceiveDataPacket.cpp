#include "example/packet/MyReceiveDataPacket.h"
#include <iostream>
MyReceiveDataPacket::MyReceiveDataPacket(const int& id):
    ReceiveDataPacketInterface(id){
    this->mSize = 7;
    initData();
}


void MyReceiveDataPacket::initData() {
    myFloat.f = 0;
    myNum.s = 0;
    myBool.b = false;
}

int MyReceiveDataPacket::readData(const unsigned char* const dataArr,const int& startIndex) {
    int index = 0;
    this->myFloat.c[0] = dataArr[startIndex + index++];
    this->myFloat.c[1] = dataArr[startIndex + index++];
    this->myFloat.c[2] = dataArr[startIndex + index++];
    this->myFloat.c[3] = dataArr[startIndex + index++];


    this->myNum.c[0] = dataArr[startIndex + index++];
    this->myNum.c[1] = dataArr[startIndex + index++];


    this->myBool.c[0] = dataArr[startIndex + index++];

    
    return mSize;
}

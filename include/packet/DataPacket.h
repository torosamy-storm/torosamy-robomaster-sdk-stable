#ifndef DATAPACKET_H
#define DATAPACKET_H


namespace Torosamy{
    typedef union {
        short s;
        unsigned char c[2];
    } short2uchar;
    
    typedef union {
        bool b;
        unsigned char c[1];
    } bool2uchar;
    
    typedef union {
        float f;
        unsigned char c[4];
    } float2uchar;
    
    
    class DataPacket {
    public:
        DataPacket(const int& id);
    
        int getSize() const;
        int getId() const;
        virtual void initData() = 0;
        virtual ~DataPacket() = default;
    protected:
        const int mId;
        int mSize;
    };
    
}

#endif

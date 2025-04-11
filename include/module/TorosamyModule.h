#ifndef TOROSAMYMODULE_H
#define TOROSAMYMODULE_H
#include <iostream>

namespace Torosamy {
    class TorosamyModule {
    public:
        TorosamyModule(const int& id);
        virtual void run() = 0;
        virtual ~TorosamyModule() = default;
        static std::string getConfigLocation(const std::string& moudleName);
        static std::string getConfigLocation();
        void stopTask();
        void startTask();
        int getId() const;
    protected:
        bool mRunning;
        int mId;
    };
}



#endif

//
// Created by torosamy on 24-11-12.
//

#ifndef MyModule_H
#define MyModule_H

#include "module/TorosamyModule.h"
#include <memory>

class MyModule : public Torosamy::TorosamyModule{
public:
    MyModule(const int& id);
    void run() override;
    static std::vector<std::shared_ptr<Torosamy::TorosamyModule>> makeModules();
    static std::vector<int> mIds;
private:
    int mNum;
    std::string mName;
    bool mBoolean;
    float mScore;
    double mDoubleScore;
};

#endif //MyModule_H

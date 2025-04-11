#include "example/MyModule.h"


#include "utils/MessageUtils.h"
#include "pod/manager/CameraManager.h"
#include "pod/manager/PacketManager.h"
#include "example/packet/MyReceiveDataPacket.h"

std::vector<int> MyModule::mIds;


void MyModule::run() {
    std::shared_ptr<MyReceiveDataPacket> rPacket = PacketManager::getInstance()->getReceivePacketById<MyReceiveDataPacket>(0);
    while (mRunning) {
        std::cout<<rPacket->myNum.s<<std::endl;
        std::cout<<mName<<" "<<mNum<<" "<<mBoolean<<std::endl;
    }
}



std::vector<std::shared_ptr<Torosamy::TorosamyModule>> MyModule::makeModules() {
    std::vector<std::shared_ptr<TorosamyModule>> result;

    const YAML::Node fileReader = YAML::LoadFile(getConfigLocation("example")+"config.yml");

    std::vector<int> ids;
    for(const auto& idNode : fileReader["LoadIds"]) {
        ids.push_back(idNode.as<int>());
    }


    if(ids.empty()) {
        std::cout<<"not found any id"<<std::endl;
        return result;
    }

    for(const int& id : ids) {
        result.push_back(std::make_shared<MyModule>(id));
        mIds.push_back(id);
    }

    return result;
}

MyModule::MyModule(const int& id) : 
    Torosamy::TorosamyModule(id){
	std::string stringId = std::to_string(id);

    const YAML::Node fileReader = YAML::LoadFile(TorosamyModule::getConfigLocation("example")+ "config.yml")[stringId];

    mName = fileReader["name"].as<std::string>();
    mNum = fileReader["num"].as<int>();


    mBoolean = fileReader["boolean"].as<bool>();
    mScore = fileReader["score"].as<float>();
    mDoubleScore = fileReader["my_score"].as<double>();
}

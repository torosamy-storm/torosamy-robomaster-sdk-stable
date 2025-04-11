#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H
#include <thread>
#include <vector>
#include <memory>
#include <mutex>
#include "module/TorosamyModule.h"

namespace Torosamy {
    class ModuleManager {
    public:
        std::shared_ptr<ModuleManager> addModules(const std::vector<std::shared_ptr<TorosamyModule>>& modulePtrs);
        std::shared_ptr<ModuleManager> addModule(const std::shared_ptr<TorosamyModule>& modulePtr);
        bool detachTasks();
        void startTasks();
        void stopTasks();
        bool loadTasks(std::vector<std::thread>& tasks);
        int getSize() const;
        bool isRepeat(const int& id) const;
        static std::shared_ptr<ModuleManager> getInstance();
    
        template <typename T>
        std::shared_ptr<T> getModuleById(const int& id) const;
    
    private:
        static std::shared_ptr<ModuleManager> instance;
        static std::once_flag initFlag;
        ModuleManager();
        bool isLoaded;
        std::vector<std::shared_ptr<TorosamyModule>> mModulePtrs;
    };
}


#include "ModuleManager.hpp"

#endif //MODULEMANAGER_H

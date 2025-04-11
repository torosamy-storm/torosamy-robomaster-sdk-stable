#ifndef MODULEMANAGER_HPP
#define MODULEMANAGER_HPP

#include "ModuleManager.h"

namespace Torosamy {
    template <typename T>
    std::shared_ptr<T> ModuleManager::getModuleById(const int& id) const{
        for (const std::shared_ptr<TorosamyModule>& ptr : mModulePtrs) {
            if (ptr->getId() == id) {
                return std::dynamic_pointer_cast<T>(ptr);
            }
        }
    
        try {
            throw std::out_of_range("module not found with id: " + std::to_string(id));
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
            return nullptr;
        }
        return nullptr; 
    }
}



#endif //MODULEMANAGER_HPP

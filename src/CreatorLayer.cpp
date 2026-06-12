#include <Geode/Bindings.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include "ListManager.h"

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init())
            return false;
            
        ListManager::isSupremeSearching = false;
        return true;
    }
};
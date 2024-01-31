#include <Geode/Bindings.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include "ListManager.h"

class $modify(CreatorLayer) {
    bool init() {
        CreatorLayer::init();
        ListManager::isSupremeSearching = false;
        return true;
    }
};
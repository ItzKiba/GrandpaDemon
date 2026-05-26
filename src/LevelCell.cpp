#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelCell.hpp>
#include "ListManager.h"
#include "EffectsManager.h"

using namespace geode::prelude;

class $modify(LevelCell) {
    // use m_mainLayer as parent
    void loadCustomLevelCell() {
        LevelCell::loadCustomLevelCell();;

        // find everything
        CCNode* layer = m_mainLayer->getChildByID("grd-demon-icon-layer");
        CCSprite* originalIcon = nullptr;

        if (layer) {
            for (auto obj : CCArrayExt<CCObject*>(layer->getChildren()))
                if (CCSprite* spr = dynamic_cast<CCSprite*>(obj))
                    if (spr->getZOrder() == 3) {
                        originalIcon = spr;
                        break;
                    }
        } else for (auto obj : CCArrayExt<CCObject*>(m_mainLayer->getChildren()))
            if (CCNode* newObj = dynamic_cast<CCNode*>(obj))
                if (newObj->getZOrder() == 2) {
                    newObj->setID("grd-demon-icon-layer");
                    layer = newObj;
                    for (auto obj2 : CCArrayExt<CCObject*>(newObj->getChildren()))
                        if (CCSprite* newObj2 = dynamic_cast<CCSprite*>(obj2))
                            if (newObj2->getZOrder() == 3) {
                                originalIcon = newObj2;
                                break;
                            }
                }
        
        // clean up the modded stuff just in case this level cell got recycled to a different level
        if (layer) {
            if (auto oldCustomIcon = layer->getChildByID("grd-custom-icon"))
                oldCustomIcon->removeFromParentAndCleanup(true);
            if (auto oldInfinity = layer->getChildByID("grd-infinity"))
                oldInfinity->removeFromParentAndCleanup(true);

            std::vector<CCNode*> children;
            for (auto obj : CCArrayExt<CCObject*>(layer->getChildren()))
                if (CCNode* node = dynamic_cast<CCNode*>(obj))
                    if (node->getTag() == 133769420) children.push_back(node);
            for (auto node : children) node->removeFromParentAndCleanup(true);
        }
        if (originalIcon){
            std::vector<CCSprite*>children;
            for (auto clearObj : CCArrayExt<CCObject*>(originalIcon->getChildren()))
                if (CCSprite* newObj = dynamic_cast<CCSprite*>(clearObj))
                    if (newObj->getTag() == 133769420)
                        children.push_back(newObj);
            for (auto newObj : children)
                newObj->removeFromParentAndCleanup(true);

            originalIcon->setVisible(true);
        }
        
        // add in the mod stuff (if possible)
        if (ListManager::demonIDList.size() == 0 || m_level->m_stars != 10) return;
        if (originalIcon == nullptr || layer == nullptr) return;

        int aredlPos = ListManager::getPositionOfID(m_level->m_levelID);
        if (aredlPos == -1 || aredlPos > 499) return;

        CCSprite* newIcon = ListManager::getSpriteFromPosition(aredlPos, false);
        if (!newIcon) return;
        newIcon->setID("grd-custom-icon");

        auto newPos = originalIcon->getPosition();
        newIcon->setPosition(newPos);
        newIcon->setZOrder(originalIcon->getZOrder() + 25);

        std::vector<CCNode*> children;
        for (auto iconObj : CCArrayExt<CCObject*>(originalIcon->getChildren()))
            if (CCSprite* newObj = dynamic_cast<CCSprite*>(iconObj))
                children.push_back(newObj);
        for (auto newObj : children) {
            newObj->setTag(133769420);
            layer->addChild(newObj);
            newObj->setPosition(newPos);
        }

        originalIcon->setVisible(false);
        layer->addChild(newIcon);

        if (aredlPos <= 24) EffectsManager::addInfinitySymbol(newIcon->getPosition(), layer, aredlPos);
    }
};
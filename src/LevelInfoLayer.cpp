#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <vector>
#include <string>
#include "ListManager.h"
#include "EffectsManager.h"
#include "ParticleManager.h"

using namespace geode::prelude;

class $modify(GrDInfoLayer, LevelInfoLayer) {

    struct Fields {
        bool m_hasBeenOpened = false;
    };
    
    void updateDifficultyFace() {

        int aredlPos = ListManager::getPositionOfID(m_level->m_levelID);
        if (aredlPos == -1 || aredlPos > 499) {
            return;
        }

        // Get the original difficulty icon
        CCSprite* originalIcon = nullptr;
        bool iconFound = false;

        // Iterate through every object that is a direct child of the layer to find the difficulty face.
        CCObject* obj;
        CCARRAY_FOREACH(this->getChildren(), obj) {
            // Check to see if the object is a sprite.
            if (CCSprite* newObj = dynamic_cast<CCSprite*>(obj)) {
                // Check to see if the object is the demon difficulty icon
                // Note that the child-index "stars-icon" doesn't appear to work all the time.
                // Instead of using an absolute index, get the object that fits the following criteria:
                if (newObj->getPosition() == m_difficultySprite->getPosition()
                && newObj->getZOrder() == 3) {
                    //newObj->setColor({0, 255, 0});
                    originalIcon = newObj;
                    iconFound = true;
                    break;
                }
            }
        }

        // If the demon face somehow isn't found, notify the user.
        if (originalIcon == nullptr || !iconFound) {
            auto alert = FLAlertLayer::create("Error", "There was a problem loading the demon difficulty face.\nYour sceen resolution may not be supported.\n\n<cb>-Grandpa Demon</c>", "OK");
            alert->m_scene = this;
            alert->show();
            return;
        }

        CCSprite* newIcon = ListManager::getSpriteFromPosition(aredlPos, true);
        //CCSprite* newIcon = CCSprite::createWithSpriteFrameName("GrD_demon0_text.png"_spr);
        newIcon->setID("grd-difficulty");
        
        auto newPos = originalIcon->getPosition();
        newIcon->setPosition(originalIcon->getPosition());
        newIcon->setZOrder(originalIcon->getZOrder()+10);
        

        CCObject* clearObj;
        CCARRAY_FOREACH(originalIcon->getChildren(), clearObj) {
            if (CCSprite* newObj = dynamic_cast<CCSprite*>(clearObj)) {
                if (newObj->getTag() == 69420) {
                    newObj->removeFromParentAndCleanup(true);
                }
            }
        }

        CCObject* iconObj;
        CCARRAY_FOREACH(originalIcon->getChildren(), iconObj) {
            if (CCSprite* newObj = dynamic_cast<CCSprite*>(iconObj)) {
                newObj->setTag(69420);
                this->addChild(newObj);
                newObj->setPosition(newPos);
            }
        }

        originalIcon->setVisible(false);

        this->addChild(newIcon);
        
        if (m_fields->m_hasBeenOpened) {
            return;
        }

        if (aredlPos <= 24) {
            EffectsManager::infinityBackground(this, aredlPos);
            EffectsManager::addInfinitySymbol(newIcon->getPosition(), this, aredlPos);

            if (!Mod::get()->getSettingValue<bool>("particles-disable")) {
                bool isGrandpa = false;

                if (aredlPos == 0 && !Mod::get()->getSettingValue<bool>("grandpa-demon-disable")) {
                    isGrandpa = true;
                }

                auto particle1 = ParticleManager::infiniteParticles1(50, isGrandpa);
                particle1->setPosition({newIcon->getPositionX(), newIcon->getPositionY() + 5.f});
                this->addChild(particle1);

                auto particle2 = ParticleManager::infiniteParticles2(50);
                particle2->setPosition({newIcon->getPositionX(), newIcon->getPositionY() + 5.f});
                this->addChild(particle2);
            }

        }

        if (aredlPos <= 74 && aredlPos > 24) {
            EffectsManager::mythicalBackground(this, aredlPos);

            if (!Mod::get()->getSettingValue<bool>("particles-disable")) {
                auto particle = ParticleManager::mythicalParticles(50);
                particle->setPosition({newIcon->getPositionX(), newIcon->getPositionY() + 5.f});
                this->addChild(particle);
            }
            
        }

        if (aredlPos <= 149 && aredlPos > 74) {
            EffectsManager::legendaryBackground(this, aredlPos);

            if (!Mod::get()->getSettingValue<bool>("particles-disable")) {
                auto particle = ParticleManager::legendaryParticles(50);
                particle->setPosition({newIcon->getPositionX(), newIcon->getPositionY() + 5.f});
                this->addChild(particle);
            }
      
        }
        
        m_fields->m_hasBeenOpened = true;
        return;
    }

    void updateLabelValues() {
        LevelInfoLayer::updateLabelValues();
        if (ListManager::demonIDList.size() == 0) {
            return;
        }

        if (this->m_level->m_stars != 10) {
            return;
        }
        
        updateDifficultyFace();
    }
};
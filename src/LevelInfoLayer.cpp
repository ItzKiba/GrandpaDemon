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

        if (m_fields->m_hasBeenOpened) {
            return;
        }

        int aredlPos = ListManager::getPositionOfID(m_level->m_levelID);
        if (aredlPos == -1 || aredlPos > 499) {
            return;
        }

        CCSprite* newIcon = ListManager::getSpriteFromPosition(aredlPos, true);
        //CCSprite* newIcon = CCSprite::createWithSpriteFrameName("GrD_demon0_text.png"_spr);
        newIcon->setID("grd-difficulty");
        
        newIcon->setPosition(m_difficultySprite->getPosition());
        newIcon->setZOrder(m_difficultySprite->getZOrder()+10);
        
        m_difficultySprite->setOpacity(0);

        this->addChild(newIcon);

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
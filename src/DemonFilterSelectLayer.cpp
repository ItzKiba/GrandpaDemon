#include <Geode/Bindings.hpp>
#include <Geode/modify/DemonFilterSelectLayer.hpp>
#include "ListManager.h"

class $modify(GrdDemonFilterSelectLayer, DemonFilterSelectLayer) {

    struct Fields {
        CCSprite* m_demon0Spr = nullptr;
        CCSprite* m_demon1Spr = nullptr;
        CCSprite* m_demon2Spr = nullptr;
        CCSprite* m_demon3Spr = nullptr;
        CCSprite* m_demon4Spr = nullptr;
        CCSprite* m_demon5Spr = nullptr;
    };
    

    static void onModify(auto &self) {
        (void)self.setHookPriority("DemonFilterSelectLayer::init", -1);
    }

    bool init() {
        if(!DemonFilterSelectLayer::init()) return false;

        if (ListManager::demonIDList.empty()) {
            return true;
        }

        handleTouchPriority(this);
        auto layer = this->getChildByType<CCLayer>(0);
        if(!layer) return true;

        auto s9spr = layer->getChildByType<CCScale9Sprite>(0);
        auto label = layer->getChildByType<CCLabelBMFont>(0);
        auto menu  = layer->getChildByType<CCMenu>(0);
        if(!s9spr || !label || !menu) return true;


        // Find OK Button
        CCMenuItemSpriteExtra* okButton = nullptr;
        for (auto obj_ok : menu->getChildrenExt())
            if (auto newObj = typeinfo_cast<CCMenuItemSpriteExtra*>(obj_ok))
                if (newObj->getPositionY() < 0) {
                    okButton = newObj;
                    break;
                }
        if(!okButton) return true;

        auto csize = s9spr->getContentSize();
        s9spr->setContentSize({csize.width, csize.height * 1.5f});
        auto newcsize = s9spr->getContentSize();
        label->setPositionY(newcsize.height + 0.f);
        label->setScale(0.8f);
        menu->setPositionY(newcsize.height * 0.82f);
        okButton->setPositionY(-160.f);

        handleTouchPriority(this);

        // create new menu
        auto newMenu = CCMenu::create();
        layer->addChild(newMenu);
        newMenu->setPosition({layer->getContentSize().width / 2 - 3, layer->getContentSize().height * 0.38f});
        newMenu->setLayout(RowLayout::create()
        ->setGap(-1.f)
        ->setAxisAlignment(AxisAlignment::Center));
        
        auto instantSearch = CCLabelBMFont::create("Instant Search", "bigFont.fnt");
        instantSearch->setPosition({label->getPositionX(), layer->getContentSize().height * 0.52f});
        instantSearch->setScale(0.8f);
        layer->addChild(instantSearch);
        
        // create buttons and sprites

        auto demon0Spr = CCSprite::createWithSpriteFrameName("GrD_demon0_text.png"_spr);
        this->m_fields->m_demon0Spr = demon0Spr;
        auto demon0Btn = CCMenuItemSpriteExtra::create(demon0Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton0));
        newMenu->addChild(demon0Btn);
        
        auto demon1Spr = CCSprite::createWithSpriteFrameName("GrD_demon1_text.png"_spr);
        this->m_fields->m_demon1Spr = demon1Spr;
        auto demon1Btn = CCMenuItemSpriteExtra::create(demon1Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton1));
        newMenu->addChild(demon1Btn);

        auto demon2Spr = CCSprite::createWithSpriteFrameName("GrD_demon2_text.png"_spr);
        this->m_fields->m_demon2Spr = demon2Spr;
        auto demon2Btn = CCMenuItemSpriteExtra::create(demon2Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton2));
        newMenu->addChild(demon2Btn);

        auto demon3Spr = CCSprite::createWithSpriteFrameName("GrD_demon3_text.png"_spr);
        this->m_fields->m_demon3Spr = demon3Spr;
        auto demon3Btn = CCMenuItemSpriteExtra::create(demon3Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton3));
        newMenu->addChild(demon3Btn);

        auto demon4Spr = CCSprite::createWithSpriteFrameName("GrD_demon4_text.png"_spr);
        this->m_fields->m_demon4Spr = demon4Spr;
        auto demon4Btn = CCMenuItemSpriteExtra::create(demon4Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton4));
        newMenu->addChild(demon4Btn);

        if (!(Mod::get()->getSettingValue<bool>("grandpa-demon-disable"))) {
            auto demon5Spr = CCSprite::createWithSpriteFrameName("GrD_demon5_text.png"_spr);
            this->m_fields->m_demon5Spr = demon5Spr;
            auto demon5Btn = CCMenuItemSpriteExtra::create(demon5Spr, this, menu_selector(GrdDemonFilterSelectLayer::onButton5));
            newMenu->addChild(demon5Btn);
        }   
        
        newMenu->updateLayout();
        
        return true;
    }

    void onButton0(CCObject* sender) {
        ListManager::filterType = 0;
        ListManager::isSupremeSearching = true;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(499, 249));
        geode::cocos::switchToScene(browserLayer);
    }
    void onButton1(CCObject* sender) {
        ListManager::filterType = 1;
        ListManager::isSupremeSearching = false;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(249, 149));
        geode::cocos::switchToScene(browserLayer);
    }
    void onButton2(CCObject* sender) {
        ListManager::filterType = 2;
        ListManager::isSupremeSearching = false;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(149, 74));
        geode::cocos::switchToScene(browserLayer);
    }
    void onButton3(CCObject* sender) {
        ListManager::filterType = 3;
        ListManager::isSupremeSearching = false;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(74, 24));
        geode::cocos::switchToScene(browserLayer);
    }
    void onButton4(CCObject* sender) {
        ListManager::filterType = 4;
        ListManager::isSupremeSearching = false;
        int lower = Mod::get()->getSettingValue<bool>("grandpa-demon-disable") ? -1 : 0;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(24, lower));
        geode::cocos::switchToScene(browserLayer);
    }
    void onButton5(CCObject* sender) {
        if(Mod::get()->getSettingValue<bool>("grandpa-demon-disable")) return; // just in case
        ListManager::filterType = 5;
        ListManager::isSupremeSearching = false;
        auto browserLayer = LevelBrowserLayer::create(ListManager::getSearchObject(0, -1));
        geode::cocos::switchToScene(browserLayer);
    }
};
#include <Geode/Bindings.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include "ListManager.h"

class $modify(GrDLevelBrowserLayer, LevelBrowserLayer) {

    struct Fields {
        int m_currentPage = 0;
        int m_furthestLoadedPage = 0;
        int m_lowIdx = 0;
    };

    bool init(GJSearchObject* p0) {

        if (!ListManager::isSupremeSearching) {
            LevelBrowserLayer::init(p0);
            return true;
        }

        if (p0->m_searchType != SearchType::Type19) {
            LevelBrowserLayer::init(p0);
            return true;
        }

        this->m_fields->m_currentPage = 0;
        int page = this->m_fields->m_currentPage;
        this->m_fields->m_lowIdx = page * 10;

        LevelBrowserLayer::init(ListManager::getSearchObject(499, 489));
        return true;
    }

    // TodoReturn loadPage(GJSearchObject* p0) {

    //     if (!ListManager::isSupremeSearching) {
    //         LevelBrowserLayer::loadPage(p0);
    //         return;
    //     }

    //     LevelBrowserLayer::loadPage(p0);
    //     return;
        
    // }

    void loadLevelsFinished(cocos2d::CCArray* p0, char const* p1, int p2) {
        LevelBrowserLayer::loadLevelsFinished(p0, p1, p2);
        if (!ListManager::isSupremeSearching) {
            return;
        }
        if (this->m_searchObject->m_searchType != SearchType::Type19) {
            return;
        }
        auto prevBtn = this->m_leftArrow;
        auto nextBtn = this->m_rightArrow;

        hideStuff();

        prevBtn->setVisible(true);
        nextBtn->setVisible(true);

        if (this->m_fields->m_currentPage <= 0) {
            prevBtn->setVisible(false);
        } else if (this->m_fields->m_currentPage >= 24) {
            nextBtn->setVisible(false);
        }
    }

    void onNextPage(CCObject* sender) {
        LevelBrowserLayer::onNextPage(sender);
        if (!ListManager::isSupremeSearching) {
            return;
        }
        if (this->m_searchObject->m_searchType != SearchType::Type19) {
            return;
        }

        if (this->m_fields->m_currentPage < 24) {
            this->m_fields->m_currentPage += 1;
        }
        nextBtnActions();
        
    }

    void onPrevPage(CCObject* sender) {
        LevelBrowserLayer::onPrevPage(sender);
        if (!ListManager::isSupremeSearching) {
            return;
        }
        if (this->m_searchObject->m_searchType != SearchType::Type19) {
            return;
        }
        if (this->m_fields->m_currentPage > 0) {
            this->m_fields->m_currentPage -= 1;
        }
        nextBtnActions();
        
    }

    void nextBtnActions() {
        hideStuff();
        LevelBrowserLayer::loadPage(ListManager::getSearchObject(499 - this->m_fields->m_currentPage * 10, 489 - this->m_fields->m_currentPage * 10));
    }

    void hideStuff() {
        this->m_pageBtn->setVisible(false);
        this->m_countText->setString(fmt::format("{} to {} of 250", this->m_fields->m_currentPage * 10 + 1, this->m_fields->m_currentPage * 10 + 10).c_str());
    }
};


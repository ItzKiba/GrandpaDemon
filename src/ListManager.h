#ifndef LISTMANAGER_H
#define LISTMANAGER_H
#include <vector>
#include <string>
#include <matjson.hpp>

using namespace geode::prelude;

class ListManager {
    public:
        inline static std::vector<int> demonIDList;
        inline static bool firstTimeOpen;
        inline static int filterType;
        inline static bool isSupremeSearching;

        inline static void parseRequestString(std::string const& str) {
            demonIDList.clear();

            auto jsonRes = matjson::parse(str);
            if (!jsonRes) return;

            auto json = jsonRes.unwrap();
            if (!json.isArray()) return;

            for (auto& item : json.asArray().unwrap()) {
                if (!item.isObject()) continue;

                auto& obj = item;

                auto idRes = obj["level_id"].asInt();
                if (!idRes) continue;

                demonIDList.push_back(idRes.unwrap());
            }
        }

        inline static int getPositionOfID(int id) {
            for (unsigned int i = 0; i < demonIDList.size(); i++) {
                if (demonIDList.at(i) == id) return i;
            }

            return -1;
        }

        inline static CCSprite* getSpriteFromPosition(int pos, bool hasText) {
            if (pos <= 499 &&
                pos > 249) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon0_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon0.png"_spr);
                    }
                }

            if (pos <= 249 &&
                pos > 149) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon1_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon1.png"_spr);
                    }
                }

            if (pos <= 149 &&
                pos > 74) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon2_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon2.png"_spr);
                    }
                }
            if (pos <= 74 &&
                pos > 24) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon3_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon3.png"_spr);
                    }
                }
            if (pos <= 24 &&
                pos > 0) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon4_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon4.png"_spr);
                    }
                }
            if (pos == 0) {
                if ((Mod::get()->getSettingValue<bool>("grandpa-demon-disable"))) {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon4_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon4.png"_spr);
                    }
                } else {
                    if (hasText) {
                        return CCSprite::createWithSpriteFrameName("GrD_demon5_text.png"_spr);
                    } else {
                        return CCSprite::createWithSpriteFrameName("GrD_demon5.png"_spr);
                    }
                }
            } 
            
            return nullptr;
        }

        inline static GJSearchObject* getSearchObject(int upper, int lower) {
            std::stringstream download;
            bool first = true;
            if (!(upper == 0 && lower == 0)) {
                for (unsigned int i = upper; i > lower; i--) {
                    if (!first) {
                        download << ",";
                    }
                    download << std::to_string(ListManager::demonIDList.at(i));
                    first = false;
                }
            } else {
                download << std::to_string(ListManager::demonIDList.at(0));
            }
            
            download << "&gameVersion=22";
            GJSearchObject* searchObj = GJSearchObject::create(SearchType::Type19, download.str());
            return searchObj;
        }   

        
};


#endif

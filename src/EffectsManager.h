#ifndef EFFECTSMANAGER_H
#define EFFECTSMANAGER_H

using namespace geode::prelude;

class EffectsManager {
    public:
        inline static void addInfinitySymbol(CCPoint iconPos, CCNode* layer, int aredlPos) {

            if (aredlPos == 0 && !Mod::get()->getSettingValue<bool>("grandpa-demon-disable")) {
                return;
            }
                
            if (layer->getChildByID("grd-infinity") != nullptr) {
                return;
            }

            CCSprite* infinityBase = CCSprite::createWithSpriteFrameName("GrD_demon4_infinity.png"_spr);
            infinityBase->setZOrder(30);
            infinityBase->setColor({ 255, 233, 136 });
            infinityBase->setPositionX(iconPos.x - 0.4);
            infinityBase->setPositionY(iconPos.y + 14);

            infinityBase->setOpacity(100);
            infinityBase->setScale(0.4f);

            auto fadein = CCEaseSineInOut::create(CCFadeTo::create(1.5f, 200));
            auto fadeout = CCEaseSineInOut::create(CCFadeTo::create(1.5f, 60));
            auto sequence1 = CCSequence::create(fadein, fadeout, nullptr);
            auto repeatSequence1 = CCRepeatForever::create(sequence1);

            auto scalein = CCEaseSineInOut::create(CCScaleTo::create(1.5f, 0.45f));
            auto scaleout = CCEaseSineInOut::create(CCScaleTo::create(1.5f, 0.35f));
            auto sequence2 = CCSequence::create(scalein, scaleout, nullptr);
            auto repeatSequence2 = CCRepeatForever::create(sequence2);

            infinityBase->runAction(repeatSequence1);
            infinityBase->runAction(repeatSequence2);

            ccBlendFunc blending = {GL_ONE, GL_ONE};
            infinityBase->setBlendFunc(blending);

            infinityBase->setID("grd-infinity");

            layer->addChild(infinityBase);
        }

        inline static void infinityBackground(LevelInfoLayer* layer, int aredlPos) {
            
            if (Mod::get()->getSettingValue<bool>("infinite-demon-disable")) {
                return;
            }

            if (layer->getChildByID("grd-infinity") != nullptr) {
                return;
            }

            CCSprite* bg = nullptr;

            CCObject* obj;
            CCARRAY_FOREACH(layer->getChildren(), obj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(obj)) {
                    if (spr->getScaledContentSize().width >= CCDirector::sharedDirector()->getWinSize().width - 5) {
                        bg = spr;
                    }
                }
            }

            bg->setZOrder(-10);
            bg->setColor({75, 75, 0});

            auto winSize = CCDirector::sharedDirector()->getWinSize();
            ccBlendFunc blending = {GL_ONE, GL_ONE};

            float bg1_maxAlpha = 90.f;
            float bg1_offsetAlpha = 90.f;

            float bg2_maxAlpha = 90.f;
            float bg2_offsetAlpha = 50.f;

            CCObject* rObj;
            CCARRAY_FOREACH(layer->getChildren(), rObj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(rObj)) {
                    if (spr->getPositionY() < 1) {
                        spr->setOpacity(50);
                    }
                    
                }
            }

            // BG 1

            CCSprite* bg1 = CCSprite::create("GrD_demon4_bg.png"_spr);
            bg1->setBlendFunc(blending);
            float bg1_scale = winSize.width / bg1->getContentSize().width; 
            bg1->setOpacity(0);
            bg1->setScale(bg1_scale);
            bg1->setColor({ 249, 249, 165 });
            layer->addChild(bg1);
            bg1->setAnchorPoint({0.5, 0});
            bg1->setPosition({winSize.width / 2, 0});
            bg1->setZOrder(-5);
            float bg1_height = bg1->getScaledContentSize().height;
            auto movedown1 = CCMoveTo::create(20, {winSize.width / 2, bg1_height * -0.15f});

            auto moveup1 = CCMoveTo::create(0, {winSize.width / 2, 0});
            auto move_seq1 = CCSequence::create(movedown1, moveup1, nullptr);
            auto move_rseq1 = CCRepeatForever::create(move_seq1);

            // lol
            auto alpha_seq1 = CCSequence::create(
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, 0.f),
                nullptr
            );

            auto alpha_rseq1 = CCRepeatForever::create(alpha_seq1);
            bg1->runAction(move_rseq1);
            bg1->runAction(alpha_rseq1);



            // BG 2

            CCSprite* bg2 = CCSprite::create("GrD_demon4_bg.png"_spr);
            bg2->setBlendFunc(blending);
            bg2->setOpacity(0);
            bg2->setScale(bg1_scale * 2.f);
            bg2->setColor({ 231, 231, 195 });
            layer->addChild(bg2);
            bg2->setAnchorPoint({0.5, 0});
            bg2->setPosition({winSize.width / 2, 0});
            bg2->setZOrder(-4);
            float bg2_height = bg2->getScaledContentSize().height;
            auto movedown2 = CCMoveTo::create(30, {winSize.width / 2, bg2_height * -0.75f});

            auto moveup2 = CCMoveTo::create(0, {winSize.width / 2, 0});
            auto move_seq2 = CCSequence::create(movedown2, moveup2, nullptr);
            auto move_rseq2 = CCRepeatForever::create(move_seq2);

            // lol 2
            auto alpha_seq2 = CCSequence::create(
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, CCRANDOM_MINUS1_1() * bg2_maxAlpha + bg2_offsetAlpha),
                CCFadeTo::create(1.5f, 0.f),
                nullptr
            );

            auto alpha_rseq2 = CCRepeatForever::create(alpha_seq2);
            bg2->runAction(move_rseq2);
            bg2->runAction(alpha_rseq2);

            if (aredlPos == 0 && !Mod::get()->getSettingValue<bool>("grandpa-demon-disable")) {
                bg1->setColor({ 121, 80, 255 });
                bg2->setColor({ 233, 200, 255 });
                bg->setColor({ 31, 0, 75 });
            }
        }




        inline static void mythicalBackground(LevelInfoLayer* layer, int aredlPos) {
            
            if (Mod::get()->getSettingValue<bool>("infinite-demon-disable")) {
                return;
            }

            CCSprite* bg = nullptr;

            CCObject* obj;
            CCARRAY_FOREACH(layer->getChildren(), obj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(obj)) {
                    if (spr->getScaledContentSize().width >= CCDirector::sharedDirector()->getWinSize().width - 5) {
                        bg = spr;
                    }
                }
            }

            bg->setZOrder(-10);
            bg->setColor({ 65, 41, 142 });

            auto winSize = CCDirector::sharedDirector()->getWinSize();
            ccBlendFunc blending = {GL_ONE, GL_ONE};

            float bg1_maxAlpha = 50.f;
            float bg1_offsetAlpha = 130.f;

            CCObject* rObj;
            CCARRAY_FOREACH(layer->getChildren(), rObj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(rObj)) {
                    if (spr->getPositionY() < 1) {
                        spr->setOpacity(50);
                    }
                    
                }
            }

            // BG 1

            CCSprite* bg1 = CCSprite::create("GrD_demon4_bg.png"_spr);
            bg1->setBlendFunc(blending);
            float bg1_scale = winSize.width / bg1->getContentSize().width; 
            bg1->setOpacity(0);
            bg1->setScale(bg1_scale);
            bg1->setColor({ 76, 63, 118 });
            layer->addChild(bg1);
            bg1->setAnchorPoint({0.5, 0});
            bg1->setPosition({winSize.width / 2, 0});
            bg1->setZOrder(-5);
            float bg1_height = bg1->getScaledContentSize().height;
            auto movedown1 = CCMoveTo::create(20, {winSize.width / 2, bg1_height * -0.35f});

            auto moveup1 = CCMoveTo::create(0, {winSize.width / 2, 0});
            auto move_seq1 = CCSequence::create(movedown1, moveup1, nullptr);
            auto move_rseq1 = CCRepeatForever::create(move_seq1);

            // lol
            auto alpha_seq1 = CCSequence::create(
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, 0.f),
                nullptr
            );

            auto alpha_rseq1 = CCRepeatForever::create(alpha_seq1);
            bg1->runAction(move_rseq1);
            bg1->runAction(alpha_rseq1);
        }

        inline static void legendaryBackground(LevelInfoLayer* layer, int aredlPos) {
            
            if (Mod::get()->getSettingValue<bool>("infinite-demon-disable")) {
                return;
            }

            CCSprite* bg = nullptr;

            CCObject* obj;
            CCARRAY_FOREACH(layer->getChildren(), obj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(obj)) {
                    if (spr->getScaledContentSize().width >= CCDirector::sharedDirector()->getWinSize().width - 5) {
                        bg = spr;
                    }
                }
            }

            bg->setZOrder(-10);
            bg->setColor({ 207, 112, 254 });

            auto winSize = CCDirector::sharedDirector()->getWinSize();
            ccBlendFunc blending = {GL_ONE, GL_ONE};

            float bg1_maxAlpha = 40.f;
            float bg1_offsetAlpha = 100.f;

            CCObject* rObj;
            CCARRAY_FOREACH(layer->getChildren(), rObj) {
                if (CCSprite* spr = dynamic_cast<CCSprite*>(rObj)) {
                    if (spr->getPositionY() < 1) {
                        spr->setOpacity(50);
                    }
                    
                }
            }

            // BG 1

            CCSprite* bg1 = CCSprite::create("GrD_demon4_bg.png"_spr);
            bg1->setBlendFunc(blending);
            float bg1_scale = winSize.width / bg1->getContentSize().width; 
            bg1->setOpacity(0);
            bg1->setScale(bg1_scale);
            bg1->setColor({ 55, 48, 78 });
            layer->addChild(bg1);
            bg1->setAnchorPoint({0.5, 0});
            bg1->setPosition({winSize.width / 2, 0});
            bg1->setZOrder(-5);
            float bg1_height = bg1->getScaledContentSize().height;
            auto movedown1 = CCMoveTo::create(20, {winSize.width / 2, bg1_height * -0.25f});

            auto moveup1 = CCMoveTo::create(0, {winSize.width / 2, 0});
            auto move_seq1 = CCSequence::create(movedown1, moveup1, nullptr);
            auto move_rseq1 = CCRepeatForever::create(move_seq1);

            // lol
            auto alpha_seq1 = CCSequence::create(
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, CCRANDOM_MINUS1_1() * bg1_maxAlpha + bg1_offsetAlpha),
                CCFadeTo::create(1.f, 0.f),
                nullptr
            );

            auto alpha_rseq1 = CCRepeatForever::create(alpha_seq1);
            bg1->runAction(move_rseq1);
            bg1->runAction(alpha_rseq1);
        }
};

#endif
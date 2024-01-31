#pragma once
#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class ParticleManager {
    public:

    inline static CCParticleSystem* legendaryParticles(int numParticles) {
            auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

            dict->setObject(CCString::create("1"), "emitterType");
            dict->setObject(CCString::create("-1"), "duration");
            dict->setObject(CCString::createWithFormat("%i", numParticles), "maxParticles");
            dict->setObject(CCString::create("1.5"), "particleLifespan");
            dict->setObject(CCString::create("0.5"), "particleLifespanVariance");
            dict->setObject(CCString::create("90"), "angle");
            dict->setObject(CCString::create("180"), "angleVariance");
            dict->setObject(CCString::create("0"), "sourcePositionx");
            dict->setObject(CCString::create("0"), "sourcePositiony");
            dict->setObject(CCString::create("0"), "sourcePositionVariancex");
            dict->setObject(CCString::create("0"), "sourcePositionVariancey");
            dict->setObject(CCString::create("0"), "maxRadius");
            dict->setObject(CCString::create("30"), "minRadius");
            dict->setObject(CCString::create("3"), "startParticleSize");
            dict->setObject(CCString::create("1"), "finishParticleSize");
            dict->setObject(CCString::create("1"), "startParticleSizeVariance");
            dict->setObject(CCString::create("10"), "speed");
            dict->setObject(CCString::create("5"), "speedVariance");
            dict->setObject(CCString::create("0"), "gravityx");
            dict->setObject(CCString::create("0"), "gravityy");
            dict->setObject(CCString::create("0.65"), "startColorRed");
            dict->setObject(CCString::create("0"), "startColorGreen");
            dict->setObject(CCString::create("1"), "startColorBlue");
            dict->setObject(CCString::create("0.5"), "startColorAlpha");
            dict->setObject(CCString::create("0.1"), "startColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "startColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "startColorVarianceGreen");
            dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
            dict->setObject(CCString::create("1"), "finishColorRed");
            dict->setObject(CCString::create("1"), "finishColorGreen");
            dict->setObject(CCString::create("1"), "finishColorBlue");
            dict->setObject(CCString::create("0"), "finishColorAlpha");
            dict->setObject(CCString::create("0.3"), "finishColorVarianceRed");
            dict->setObject(CCString::create("0.3"), "finishColorVarianceBlue");
            dict->setObject(CCString::create("0.3"), "finishColorVarianceGreen");
            dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");
            dict->setObject(CCString::create("40"), "rotatePerSecond");
            dict->setObject(CCString::create("10"), "rotatePerSecondVariance");
            dict->setObject(CCString::create("270"), "rotationEndVariance");

            dict->setObject(CCString::create("square.png"), "textureFileName");

            auto emitter = CCParticleSystemQuad::create();
            emitter->initWithDictionary(dict, false);
            
            return emitter;
        }



        inline static CCParticleSystem* mythicalParticles(int numParticles) {
            auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

            dict->setObject(CCString::create("1"), "emitterType");
            dict->setObject(CCString::create("-1"), "duration");
            dict->setObject(CCString::createWithFormat("%i", numParticles), "maxParticles");
            dict->setObject(CCString::create("1.5"), "particleLifespan");
            dict->setObject(CCString::create("0.5"), "particleLifespanVariance");
            dict->setObject(CCString::create("90"), "angle");
            dict->setObject(CCString::create("180"), "angleVariance");
            dict->setObject(CCString::create("0"), "sourcePositionx");
            dict->setObject(CCString::create("0"), "sourcePositiony");
            dict->setObject(CCString::create("0"), "sourcePositionVariancex");
            dict->setObject(CCString::create("0"), "sourcePositionVariancey");
            dict->setObject(CCString::create("0"), "maxRadius");
            dict->setObject(CCString::create("40"), "minRadius");
            dict->setObject(CCString::create("4"), "startParticleSize");
            dict->setObject(CCString::create("1"), "finishParticleSize");
            dict->setObject(CCString::create("2"), "startParticleSizeVariance");
            dict->setObject(CCString::create("15"), "speed");
            dict->setObject(CCString::create("7"), "speedVariance");
            dict->setObject(CCString::create("0"), "gravityx");
            dict->setObject(CCString::create("0"), "gravityy");
            dict->setObject(CCString::create("0.4"), "startColorRed");
            dict->setObject(CCString::create("0.4"), "startColorGreen");
            dict->setObject(CCString::create("1"), "startColorBlue");
            dict->setObject(CCString::create("0.7"), "startColorAlpha");
            dict->setObject(CCString::create("0.1"), "startColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "startColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "startColorVarianceGreen");
            dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
            dict->setObject(CCString::create("1"), "finishColorRed");
            dict->setObject(CCString::create("1"), "finishColorGreen");
            dict->setObject(CCString::create("1"), "finishColorBlue");
            dict->setObject(CCString::create("0"), "finishColorAlpha");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceGreen");
            dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");
            dict->setObject(CCString::create("60"), "rotatePerSecond");
            dict->setObject(CCString::create("20"), "rotatePerSecondVariance");
            dict->setObject(CCString::create("360"), "rotationEndVariance");

            dict->setObject(CCString::create("square.png"), "textureFileName");

            auto emitter = CCParticleSystemQuad::create();
            emitter->initWithDictionary(dict, false);
            
            return emitter;
        }



        inline static CCParticleSystem* infiniteParticles1(int numParticles, bool isGrandpa) {
            auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

            dict->setObject(CCString::create("1"), "emitterType");
            dict->setObject(CCString::create("-1"), "duration");
            dict->setObject(CCString::createWithFormat("%i", numParticles), "maxParticles");
            dict->setObject(CCString::create("1.5"), "particleLifespan");
            dict->setObject(CCString::create("0.5"), "particleLifespanVariance");
            dict->setObject(CCString::create("90"), "angle");
            dict->setObject(CCString::create("180"), "angleVariance");
            dict->setObject(CCString::create("0"), "sourcePositionx");
            dict->setObject(CCString::create("0"), "sourcePositiony");
            dict->setObject(CCString::create("0"), "sourcePositionVariancex");
            dict->setObject(CCString::create("0"), "sourcePositionVariancey");
            dict->setObject(CCString::create("0"), "maxRadius");
            dict->setObject(CCString::create("50"), "minRadius");
            dict->setObject(CCString::create("3"), "startParticleSize");
            dict->setObject(CCString::create("1"), "finishParticleSize");
            dict->setObject(CCString::create("1"), "startParticleSizeVariance");
            dict->setObject(CCString::create("20"), "speed");
            dict->setObject(CCString::create("7"), "speedVariance");
            dict->setObject(CCString::create("0"), "gravityx");
            dict->setObject(CCString::create("0"), "gravityy");
            if (!isGrandpa) {
                dict->setObject(CCString::create("1"), "startColorRed");
                dict->setObject(CCString::create("0.85"), "startColorGreen");
                dict->setObject(CCString::create("0"), "startColorBlue");
            } else {
                dict->setObject(CCString::create("0.95"), "startColorRed");
                dict->setObject(CCString::create("0.3"), "startColorGreen");
                dict->setObject(CCString::create("0.95"), "startColorBlue");
            }
            

            dict->setObject(CCString::create("0.7"), "startColorAlpha");
            dict->setObject(CCString::create("0.1"), "startColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "startColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "startColorVarianceGreen");
            dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
            dict->setObject(CCString::create("1"), "finishColorRed");
            dict->setObject(CCString::create("1"), "finishColorGreen");
            dict->setObject(CCString::create("1"), "finishColorBlue");
            dict->setObject(CCString::create("0"), "finishColorAlpha");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceGreen");
            dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");
            dict->setObject(CCString::create("90"), "rotatePerSecond");
            dict->setObject(CCString::create("30"), "rotatePerSecondVariance");
            dict->setObject(CCString::create("360"), "rotationEndVariance");

            dict->setObject(CCString::create("square.png"), "textureFileName");

            auto emitter = CCParticleSystemQuad::create();
            emitter->initWithDictionary(dict, false);
            
            return emitter;
        }

        inline static CCParticleSystem* infiniteParticles2(int numParticles) {
            auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

            dict->setObject(CCString::create("1"), "emitterType");
            dict->setObject(CCString::create("-1"), "duration");
            dict->setObject(CCString::createWithFormat("%i", numParticles), "maxParticles");
            dict->setObject(CCString::create("1.5"), "particleLifespan");
            dict->setObject(CCString::create("0.5"), "particleLifespanVariance");
            dict->setObject(CCString::create("90"), "angle");
            dict->setObject(CCString::create("180"), "angleVariance");
            dict->setObject(CCString::create("0"), "sourcePositionx");
            dict->setObject(CCString::create("0"), "sourcePositiony");
            dict->setObject(CCString::create("0"), "sourcePositionVariancex");
            dict->setObject(CCString::create("0"), "sourcePositionVariancey");
            dict->setObject(CCString::create("10"), "maxRadius");
            dict->setObject(CCString::create("30"), "minRadius");
            dict->setObject(CCString::create("12"), "startParticleSize");
            dict->setObject(CCString::create("3"), "finishParticleSize");
            dict->setObject(CCString::create("5"), "startParticleSizeVariance");
            dict->setObject(CCString::create("20"), "speed");
            dict->setObject(CCString::create("7"), "speedVariance");
            dict->setObject(CCString::create("0"), "gravityx");
            dict->setObject(CCString::create("0"), "gravityy");
            dict->setObject(CCString::create("0.95"), "startColorRed");
            dict->setObject(CCString::create("0.95"), "startColorGreen");
            dict->setObject(CCString::create("0.95"), "startColorBlue");
            dict->setObject(CCString::create("1"), "startColorAlpha");
            dict->setObject(CCString::create("0.1"), "startColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "startColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "startColorVarianceGreen");
            dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
            dict->setObject(CCString::create("1"), "finishColorRed");
            dict->setObject(CCString::create("1"), "finishColorGreen");
            dict->setObject(CCString::create("1"), "finishColorBlue");
            dict->setObject(CCString::create("0"), "finishColorAlpha");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceRed");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceBlue");
            dict->setObject(CCString::create("0.1"), "finishColorVarianceGreen");
            dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");
            dict->setObject(CCString::create("0"), "rotatePerSecond");
            dict->setObject(CCString::create("60"), "rotatePerSecondVariance");
            dict->setObject(CCString::create("360"), "rotationEndVariance");

            dict->setObject(CCString::create("sun.png"), "textureFileName");

            auto emitter = CCParticleSystemQuad::create();
            emitter->initWithDictionary(dict, false);
            
            return emitter;
        }
};
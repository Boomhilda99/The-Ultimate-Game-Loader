#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <string>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    // Signature is `bool MenuLayer::init()`
    bool init() {
        if (!MenuLayer::init())
            return false;
        
        auto value = Mod::get()->getSavedValue<int>("gameLoaded");
        auto stringLabel = "Times game loaded: " + std::to_string(value);
		// @geode-ignore(unknown-resource)
		auto label = CCLabelBMFont::create(stringLabel.c_str(), "bigFont.fnt");
        label->setScale(0.8f);
        label->setPosition(getContentSize().width / 2, 90);
		this->addChild(label);


        return true;
    }
    
};  

$on_mod(Loaded) {
    auto mod = Mod::get();
    mod->setSavedValue<int>(
        "gameLoaded",
        mod->getSavedValue<int>("gameLoaded") + 1
    );
};
//
//  NoNetLayer.cpp
//  ActionGame-kzzr
//
//  Created by ShenQinfen on 16/8/4.
//
//  Modified by ff on 2016-08-09 15:17:22.
//

#include "NoNetLayer.h"
#include "logic/ClientLogic.h"
#include "ELProtocol.h"


NoNetLayer* NoNetLayer::createCCBNodeAndAnmitionmanage(const char *pCCBFileName, const char *pNodeName){
    NodeLoaderLibrary *cNodeLoader = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    cNodeLoader->registerNodeLoader(pNodeName, NoNetLayerLoader::loader());
    CCBReader *ccbReader = new CCBReader(cNodeLoader);
    ccbReader->autorelease();
    NoNetLayer *node = (NoNetLayer *)ccbReader->readNodeGraphFromFile(pCCBFileName);
    return node;
}

NoNetLayer::NoNetLayer(){
    
//    moreGameBtn = NULL;
    isActionEnd = false;
    
}

NoNetLayer::~NoNetLayer(){
//    CC_SAFE_RELEASE_NULL(moreGameBtn);
    
}

bool NoNetLayer::init(){
    
    if (!Layer::init()) {
        return false;
    }
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(NoNetLayer::onTouchBegan, this);
    listener->setSwallowTouches(true);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}


void NoNetLayer::onNodeLoaded(cocos2d::Node *node, cocosbuilder::NodeLoader *nodeLoader){
    
    
}
bool NoNetLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char *pMemberVariableName, cocos2d::Node *pNode){
    
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"moreGameBtn", ControlButton *,moreGameBtn);
    return false;
}
bool NoNetLayer::onAssignCCBCustomProperty(cocos2d::Ref *pTarget, const char *pMemberVariableName, const cocos2d::Value &pCCBValue){
    return false;
}


SEL_MenuHandler NoNetLayer::onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char *pSelectorName){
    
    
    
    return NULL;
}
Control::Handler NoNetLayer::onResolveCCBCCControlSelector(cocos2d::Ref *pTarget, const char *pSelectorName){
    
    
//    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onMoreGame", NoNetLayer::onMoreGame);
    return NULL;
}
SEL_CallFuncN NoNetLayer::onResolveCCBCCCallFuncSelector(cocos2d::Ref *pTarget, const char *pSelectorName){
    
    
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCycle", NoNetLayer::onCycle);
    return NULL;
}
CCBAnimationManager* NoNetLayer::getAnimationManager(){
    
    return (CCBAnimationManager *)getUserObject();
    
}

bool NoNetLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    if (isActionEnd)
    {
        E2L_CLICK_LOGIN info;
        info.eProtocol = e2L_unconnected_click;
        ClientLogic::instance()->ProcessUIRequest(&info);
    }
    return true;
}

void NoNetLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    
}

void NoNetLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    
}


void NoNetLayer::onCycle(Node *pSender){
    isActionEnd = true;
}

//
//  LoginLayer
//  LolDota
//
//  Created by caifei on 2015-11-09 17:51:02.
//
//  Modified by ff on 2016-08-09 15:07:32.
//

#include "LoginLayer.h"
#include "logic/ClientLogic.h"
#include "ELProtocol.h"


LoginLayer* LoginLayer::createCCBNodeAndAnmitionmanage(const char *pCCBFileName, const char *pNodeName){
    NodeLoaderLibrary *cNodeLoader = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    cNodeLoader->registerNodeLoader(pNodeName, LoginLayerLoader::loader());
    CCBReader *ccbReader = new CCBReader(cNodeLoader);
    ccbReader->autorelease();
    LoginLayer *node = (LoginLayer *)ccbReader->readNodeGraphFromFile(pCCBFileName);
    return node;
}

LoginLayer::LoginLayer(){
 
    isActionEnd = false;

}

LoginLayer::~LoginLayer(){
    

}

void LoginLayer::onEnter(){
//    BaseTouchLayer::onEnter();
    Layer::onEnter();
}

void LoginLayer::onExit(){
    
//    BaseTouchLayer::onExit();
    Layer::onExit();
}

bool LoginLayer::init(){
    
    if (!Layer::init()) {
        return false;
    }

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(LoginLayer::onTouchBegan, this);
    listener->setSwallowTouches(true);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);
    return true;
}

void LoginLayer::onNodeLoaded(cocos2d::Node *node, cocosbuilder::NodeLoader *nodeLoader){


}
bool LoginLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char *pMemberVariableName, cocos2d::Node *pNode){
    

    return false;
}
bool LoginLayer::onAssignCCBCustomProperty(cocos2d::Ref *pTarget, const char *pMemberVariableName, const cocos2d::Value &pCCBValue){
    return false;
}


SEL_MenuHandler LoginLayer::onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char *pSelectorName){



    return NULL;
}
Control::Handler LoginLayer::onResolveCCBCCControlSelector(cocos2d::Ref *pTarget, const char *pSelectorName){
    

    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onMoreGame", LoginLayer::onMoreGame);
    return NULL;
}
SEL_CallFuncN LoginLayer::onResolveCCBCCCallFuncSelector(cocos2d::Ref *pTarget, const char *pSelectorName){


    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCycle", LoginLayer::onCycle);
    return NULL;
}
CCBAnimationManager* LoginLayer::getAnimationManager(){

   return (CCBAnimationManager *)getUserObject();

}

bool LoginLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    
    if (isActionEnd) {
//        int step_id =  PlayerService::getInstance()->getPlayerData()->getPlayerInfo()->getNg_id();
//        if (step_id == 0) {
//            auto stage = StageInfoTableObject::create(9999);
//            auto heroObject= HeroObject::createForHeroId(5);
//            heroObject->getHeroInfo()->setLevel(1);
//            heroObject->changeArtifactId(4);
//            auto scene = BattleScene::scene(heroObject, NULL, stage);
//            Director::getInstance()->replaceScene(scene);
//        }else{
//            auto layer = HomeLayer::createCCBNodeAndAnmitionmanage("HomeLayer", "HomeLayer");
//            auto scene = Scene::create();
//            scene->addChild(layer);
//            Director::getInstance()->replaceScene(scene);
//        }
        E2L_CLICK_LOGIN info;
        info.eProtocol = e2l_login_click;
        ClientLogic::instance()->ProcessUIRequest(&info);
    }
    return true;
}

void LoginLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){

}

void LoginLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
        
}
void LoginLayer::onTouch_1(Node *pSender){
    
}
void LoginLayer::onTouch_2(Node *pSender){
    
}
void LoginLayer::initData(Node *pSender){
    
}
void LoginLayer::onCycle(Node *pSender){
    isActionEnd = true;
}

void LoginLayer::onMoreGame(cocos2d::Ref *pSender, Control::EventType pCCControlEvent){
//    PayService::moreGame();
}


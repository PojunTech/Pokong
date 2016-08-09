//
//  NoNetLayer.h
//  ActionGame-kzzr
//
//  Created by ShenQinfen on 16/8/4.
//
//  Modified by ff on 2016-08-09 15:17:22.
//

#ifndef NoNetLayer_h
#define NoNetLayer_h

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
using namespace cocosbuilder;
USING_NS_CC;
USING_NS_CC_EXT;
class NoNetLayer:public Layer
,   public CCBSelectorResolver
,   public CCBMemberVariableAssigner
,   public NodeLoaderListener{
public:
    /**
     *  ����
     */
    NoNetLayer();
    /**
     *  ����
     */
    ~NoNetLayer();
    /**
     *  ����CCBLayer��
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(NoNetLayer,create);
    
    static NoNetLayer * createCCBNodeAndAnmitionmanage(const char *pCCBFileName, const char *pNodeName);
    /**
     *  ��ʼ��
     *
     *  @return �ɹ����
     */
    virtual bool init();

    /**
     *  CCB��ʼ����ɺ�ص�����
     *
     *  @param pNode
     *  @param pNodeLoader
     */
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
    /**
     *  ����CCBNode����
     *
     *  @param target
     *  @param memberVariableName
     *  @param node
     *
     *  @return
     */
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    
    virtual bool onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue);
    /**
     *  ����Menu�¼�����
     *
     *  @param pTarget
     *  @param pSelectorName
     *
     *  @return
     */
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    /**
     *  ����CCControlButt�¼�
     *
     *  @param pTarget
     *  @param pSelectorName
     *
     *  @return
     */
    virtual Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    /**
     *  ����CallFuncN�¼�
     *
     *  @param pTarget
     *  @param pSelectorName
     *
     *  @return
     */
    virtual SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    CCBAnimationManager * getAnimationManager();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
//    void onTouch_1(Node *pSender);
//    void onTouch_2(Node *pSender);
//    void initData(Node *pSender);
    void onCycle(Node *pSender);
//    void onMoreGame(Ref *pSender,Control::EventType pCCControlEvent);
    
    bool isActionEnd;
    
//    ControlButton * moreGameBtn;
    
    
};

class NoNetLayerLoader : public NodeLoader{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NoNetLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(NoNetLayer);
    
};

#endif /* NoNetLayer_h */

//
// Created by farmer on 2018/6/24.
//

#include "ViewControl.h"
#include "ViewObject.h"
#include "HelloWorldScene.h"
#include "GameSceneManager.h"
#include "HelloLayer.h"
#include "GameLayer.h"

ViewControl::ViewControl(int index) {
    auto scene = HelloWorld::createScene();
    GameSceneManager::getInstance()->setScene(scene, index);
    onViewNotify(NULL);
    switch (index) {
        case 0:
            __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(
                    ViewControl::onViewNotify), ccNd_ViewNotify0, NULL);
            break;
        case 1:
            __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(
                    ViewControl::onViewNotify), ccNd_ViewNotify1, NULL);
            break;
        case 2:
            __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(
                    ViewControl::onViewNotify), ccNd_ViewNotify2, NULL);
            break;
        case 3:
            __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(
                    ViewControl::onViewNotify), ccNd_ViewNotify3, NULL);
            break;
        default:
            __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(
                    ViewControl::onViewNotify), ccNd_ViewNotify, NULL);
    }
    m_index = index;
}

ViewControl::~ViewControl() {
    __NotificationCenter::getInstance()->removeAllObservers(this);
}

/**
 *  界面控制
 * @param render
 */
void ViewControl::onViewNotify(Ref *render) {
    if (render == NULL){    //进入游戏
        HelloLayer *pLayer = HelloLayer::create();
        pLayer->setIndex(m_index);
        GameSceneManager::getInstance()->setRootLayer(pLayer->GetLayer(), m_index);
        return;
    }
    cocos2d::log("ViewControl notify %p %p", this, render);
    ViewObject *pObject = (ViewObject *) render;
    if (pObject->m_MainString == VIEW_SWITCH_MAIN_LAYER) {
        if (pObject->m_subString == "GameLayer") {    //切换到游戏视图
            GameLayer *pGameLayer = GameLayer::create();
            pGameLayer->SetChairIndex(m_index);
            cocos2d::log("View Control on view notify %p, %p", this, render);
            GameSceneManager::getInstance()->setRootLayer(pGameLayer->GetLayer(), m_index);
        }
    }

}

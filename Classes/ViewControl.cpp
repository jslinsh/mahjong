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
    __NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ViewControl::onViewNotify), ccNd_ViewNotify, NULL);
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
        GameSceneManager::getInstance()->setRootLayer(HelloLayer::create()->GetLayer(), m_index);
        return;
    }
    ViewObject *pObject = (ViewObject *) render;
    if (pObject->m_MainString == VIEW_SWITCH_MAIN_LAYER){
        if (pObject->m_subString == "GameLayer"){    //切换到游戏视图
            GameLayer* pGameLayer = GameLayer::create();
            pGameLayer->SetChairIndex(m_index);
            GameSceneManager::getInstance()->setRootLayer(pGameLayer->GetLayer(), m_index);
        }
    }

}

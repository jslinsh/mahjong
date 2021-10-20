//
// Created by farmer on 2018/6/24.
//

#ifndef PROJ_ANDROID_VIEWCONTROL_H
#define PROJ_ANDROID_VIEWCONTROL_H

#include "cocos2d.h"

#define ccNd_ViewNotify "ccNd_ViewNotify"
#define ccNd_ViewNotify0 "ccNd_ViewNotify0"
#define ccNd_ViewNotify1 "ccNd_ViewNotify1"
#define ccNd_ViewNotify2 "ccNd_ViewNotify2"
#define ccNd_ViewNotify3 "ccNd_ViewNotify3"


using namespace cocos2d;

/**
 * 视图控制类
 */
class ViewControl : public Node{

public:
    ViewControl(int index);
    ~ViewControl();

    /**
     * 通知到观察者
     * @param render
     */
    void onViewNotify(Ref* render);

private:
    int m_index = 0;

};


#endif //PROJ_ANDROID_VIEWCONTROL_H

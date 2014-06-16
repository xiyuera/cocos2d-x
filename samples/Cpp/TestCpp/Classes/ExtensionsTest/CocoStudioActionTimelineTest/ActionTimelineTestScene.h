#ifndef __ACTION_TIMELINE_SCENE_H__
#define __ACTION_TIMELINE_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../VisibleRect.h"
#include "../../testBasic.h"

class TimelineTestScene : public TestScene
{
public: 
    TimelineTestScene(bool bPortrait = false);

    virtual void runThisTest();

    // The CallBack for back to the main menu scene
    virtual void MainMenuCallback(CCObject* pSender);
};

enum {
    TEST_ACTION_TIMELINE = 0,

    TEST_ACTION_LAYER_COUNT
};

class TimelineTestLayer : public CCLayer
{
public:
    virtual void onEnter();
    virtual void onExit();

    virtual std::string title();
    virtual std::string subtitle();

    virtual void restartCallback(CCObject* pSender);
    virtual void nextCallback(CCObject* pSender);
    virtual void backCallback(CCObject* pSender);

    virtual void draw();

protected:
    CCMenuItemImage *restartItem;
    CCMenuItemImage *nextItem;
    CCMenuItemImage *backItem;
};


class TestActionTimeline : public TimelineTestLayer
{
public:
    virtual void onEnter();
    virtual std::string title();
};

#endif  // __ACTION_TIMELINE_SCENE_H__
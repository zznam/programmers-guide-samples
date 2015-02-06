#include "Chapter7_1.h"
#include "Chapter7.h"

USING_NS_CC;

Scene* Chapter7_1::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();

    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("Label", "Arial", 24);
    label->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2).x,
                       Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7::createScene());
    });
    
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2( visibleRect.origin.x+visibleRect.size.width - 80, visibleRect.origin.y + 25) );
    scene->addChild(menu, 1);
    
    // return the scene
    return scene;
}

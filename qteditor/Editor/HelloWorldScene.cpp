#include "HelloWorldScene.h"
#include "WindowBox.h"
#include "QC_GLView.h"
#include "ui/UIScale9Sprite.h"

USING_NS_CC;

HelloWorld::HelloWorld()
: _root(nullptr)
, _boxNode(nullptr)
{
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
        return false;

	_root = Node::create();
	_root->setContentSize(Size(400, 400));
	addChild(_root);

	Sprite* sp = Sprite::create("HelloWorld.png");
	_root->addChild(sp);

	_boxNode = new WindowBox(sp, true);
	_boxNode->autorelease();
	_boxNode->setGlobalZOrder(99999);
	_boxNode->setLocalZOrder(99999);
	addChild(_boxNode);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	onResize(visibleSize.width, visibleSize.height);

	QCGLView::getInstance()->setBox(_boxNode);

    return true;
}

void HelloWorld::onResize(int width, int height)
{
	_root->setPosition(width / 2 - _root->getContentSize().width / 2, height / 2 - _root->getContentSize().height / 2);
	_boxNode->Reset();
}

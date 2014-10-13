#include "HelloWorldScene.h"

#ifdef MD5_QUICK
#include "quick/QuickMD5.h"
#else
#include "cell/CellMD5.h"
#endif


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("image.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

const char* text_file		= "text.txt" ;
const char* text_zip		= "text.zip" ;

const char* image_file		= "image.png" ;
const char* image_zip		= "image.zip" ;


void testMD5()
{
#ifdef MD5_QUICK
	log("------------     testQuickMD5  start     ------------") ;
	const std::string textMD5 = QuickMD5::getInstance()->MD5File(text_file) ;
	const std::string textZipMD5 = QuickMD5::getInstance()->MD5File(text_zip) ;
	const std::string imageMD5 = QuickMD5::getInstance()->MD5File(image_file) ;
	const std::string imageZipMD5 = QuickMD5::getInstance()->MD5File(image_zip) ;
	log("***   md5 = %s   ***   filename = %s   ***", textMD5.c_str(), text_file) ;
	log("***   md5 = %s   ***   filename = %s   ***", textZipMD5.c_str(), text_zip) ;
	log("***   md5 = %s   ***   filename = %s   ***", imageMD5.c_str(), image_file) ;
	log("***   md5 = %s   ***   filename = %s   ***", imageZipMD5.c_str(), image_zip) ;
	log("------------     testQuickMD5  end       ------------") ;
#else
	log("------------     testCellMD5  start     ------------") ;
	const std::string textMD5 = CellMD5::getInstance()->MD5File(text_file) ;
	const std::string textZipMD5 = CellMD5::getInstance()->MD5File(text_zip) ;
	const std::string imageMD5 = CellMD5::getInstance()->MD5File(image_file) ;
	const std::string imageZipMD5 = CellMD5::getInstance()->MD5File(image_zip) ;
	log("***   md5 = %s   ***   filename = %s   ***", textMD5.c_str(), text_file) ;
	log("***   md5 = %s   ***   filename = %s   ***", textZipMD5.c_str(), text_zip) ;
	log("***   md5 = %s   ***   filename = %s   ***", imageMD5.c_str(), image_file) ;
	log("***   md5 = %s   ***   filename = %s   ***", imageZipMD5.c_str(), image_zip) ;
	log("------------     testCellMD5  end       ------------") ;
#endif
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    testMD5() ;
}

#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "SceneManager.hpp"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("MyPlane", Rect(0, 0, 400, 600));
#else
        glview = GLViewImpl::create("MyPlane");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
    Size frameSize = glview->getFrameSize();
    
    vector<string> searchPath;

    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {
        searchPath.push_back(smallResource.directory);
        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    
    FileUtils::getInstance()->setSearchPaths(searchPath);
    
    register_all_packages();

    /*
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);
    */
    
    director->setDisplayStats(true);
     
    SceneManager::getInstance()->changeScene(SceneManager::LoadingScene);

    CCLOG("frameSize:%f-%f",frameSize.width,frameSize.height);
    Size winSize = director->getWinSize();
    CCLOG("winSize:%f-%f",winSize.width,winSize.height);
    Size visibleSize = director->getVisibleSize();
    CCLOG("visibleSize:%f-%f",visibleSize.width,visibleSize.height);
    Point visibleOrigin = director->getVisibleOrigin();
    CCLOG("visibleOrigin:%f-%f",visibleOrigin.x,visibleOrigin.y);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

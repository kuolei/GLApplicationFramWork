/**
 *  GLDeckViewController.h
 *  GLApplication
 *
 *  Created by new_ctrip on 13-5-6.
 *  Copyright (c) 2013年 kuolei. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "GLDeckViewControllerDelegate.h"
#import "GLDeckSubViewControllerMode.h"
#import "GLDeckDefine.h"

/**
    \def glViewCenterHiddenCanTapClose(interactivity)
    \param interactivity 用户交互方式
    \brief  判断Center ViewController是否可以点击关闭
 */
#define glViewCenterHiddenCanTapClose(interactivity) ((interactivity) == GLVIEW_HIDDEN_NOT_USER_INTERACTIVE_WITH_TAPCLOSE || (interactivity) == GLVIEW_HIDDEN_NOT_USER_INTERACTIVE_WITH_TAPCLOSE_BOUNCING)

/**
    \def glViewCenterHiddenIsInteractive(interactivity)
    \param interactivity 用户交互方式
    \brief 判断是否支持用户交互
 */
#define glViewCenterHiddenIsInteractive(interactivity) ((interactivity) == GLVIEW_HIDDEN_USER_INTERACTIVE)

/**
    \fn extern NSString* stringFromGLViewSide(__enum_GLVIEWSIDE side)
    \brief 根据View的位置返回相应的字符串
    \param side view所处DeckViewController的位置
    \return 返回值位NSString的指针，位置名称：left, right, top, bottom, no, unkown
    \see __enum_GLVIEWSIDE
 */
extern NSString* stringFromGLViewSide(__enum_GLVIEW_SIDE side);

/**
    \fn extern __enum_GLVIEW_ORIENTATION orientationFromGLViewSize(__enum_GLVIEWSIDE side)
    \brief 根据View的位置返回此View的方位
    \param side View所处DeckViewController的位置
    \return __enum_GLVIEW_ORIENTATION
    \see __enum_GLVIEW_ORIENTATION
 */
extern __enum_GLVIEW_ORIENTATION orientationFromGLViewSize(__enum_GLVIEW_SIDE side);

/**
    \class GLDeckViewController
    \brief 主要有5部分ViewController组成：上、下、左、右、中；支持Navigation、手势滑动
 */
@interface GLDeckViewController : UIViewController
{
@private
    CGPoint                     m_panOrigin_;                                   /**< pan view的原始坐标*/
    UInt32                      m_viewAppeared_;                                /**< 已经显示出来view的index*/
    BOOL                        m_viewFirstAppeared_;                           /**< 是否是第一次显示*/
    UInt32                      m_sideAppeared_[6];                             /**< 记录各个viewcontroller之间切换*/
    CGFloat                     m_ledge_[5];                                    /**< 用于比较ledge是否有变化对于各个ledge*/
    UIViewController            *m_viewControllers_[6];                         /**< DeckViewController所包含viewController最多6个*/
    CGFloat                     m_offset_;                                      /**< 偏移量*/
    CGFloat                     m_maxLedge_;                                    /**< 最大ledge数*/
    CGSize                      m_preRotationSize_;                             /**< 先前转换的大小*/
    CGSize                      m_preRotationCenterSize_;                       /**< 先前CenterView的转化大小*/
    BOOL                        m_preRotationIsLandscape_;                      /**< 先前转化的是否是横屏*/
    __enum_GLVIEW_ORIENTATION   m_offsetOrientation_;                           /**< 横竖屏标示 /see __enum_GLVIEW_ORIENTATION*/
    UIInterfaceOrientation      m_willAppearShouldArrangeViewAfterRotation_;    /**< 即将出现View的设备物理方位*/
    CGPoint                     m_willAppearoffset_;                            /**< 即将出现View偏移量大小*/
    NSMutableArray              *m_finishTransitionBlocks_;                     /**< 转化block函数数据*/
    int                         m_disableUserInteraction_;                      /**< 是否是用户交互失效*/
}

typedef void (^GLDeckViewControllerBlock) (GLDeckViewController *controllor, BOOL success);
typedef void (^GLDeckViewControllerBaounceBlock) (GLDeckViewController *controller);

@property (nonatomic, weak) id<GLDeckViewControllerDelegate> delegate_;
@property (nonatomic, assign) __enum_GLVIEW_DELEGATE_MODE delegateMode_;
@property (nonatomic, strong, readonly) NSArray *viewController_;
@property (nonatomic, strong) UIViewController *centerViewController_;
@property (nonatomic, strong) UIViewController *leftViewController_;
@property (nonatomic, strong) UIViewController *rightViewController_;
@property (nonatomic, strong) UIViewController *topViewController_;
@property (nonatomic, strong) UIViewController *bottomViewController_;
@property (nonatomic, weak, readonly) UIViewController *slidingViewController_;
@property (nonatomic, strong) UIView *panningView_;
@property (nonatomic, weak) id<UIGestureRecognizerDelegate> panningGestureDelegate_;

@property (nonatomic, assign, getter = isEnabled) BOOL enabled_;
@property (nonatomic, assign, getter = isElastic) BOOL elastic_;

@property (nonatomic, assign) CGFloat leftSize_;
@property (nonatomic, assign, readonly) CGFloat leftViewSize_;
@property (nonatomic, assign, readonly) CGFloat leftLedgeSize_;

@property (nonatomic, assign) CGFloat rightSize_;
@property (nonatomic, assign, readonly) CGFloat rightViewSize_;
@property (nonatomic, assign, readonly) CGFloat rightLedgeSize_;

@property (nonatomic, assign) CGFloat topSize_;
@property (nonatomic, assign, readonly) CGFloat topViewSize_;
@property (nonatomic, assign, readonly) CGFloat topLedgeSize_;

@property (nonatomic, assign) CGFloat bottomSize_;
@property (nonatomic, assign, readonly) CGFloat bottomViewSize_;
@property (nonatomic, assign, readonly) CGFloat bottomLedgeSize_;

@property (nonatomic, assign) CGFloat maxSize_;
@property (nonatomic, assign) BOOL resizesCenterView_;

@property (nonatomic, assign) __enum_GLVIEW_PANNING_MODE panningMode_;
@property (nonatomic, assign) BOOL panningCancelTouchesInView_;

@property (nonatomic, assign) __enum_GLVIEW_CENTER_VIEWCONTROLLER_HIDDEN_INTERACTIVITY centerHiddenInteractivity_;
@property (nonatomic, assign) __enum_GLVIEW_NAVIGATION_CONTROLLER_BEHAVIOR navigationControllerBehavior_;

@property (nonatomic, assign) BOOL autoUpdateTabbarItems_;
@property (nonatomic, assign) __enum_GLVIEW_SIZE_MODE sizeMode_;

@property (nonatomic, assign) CGFloat bounceDurationFactor_;
@property (nonatomic, assign) CGFloat bounceOpenSideDurationFactor_;

@property (nonatomic, assign) CGFloat openSlideAnimationDuration_;
@property (nonatomic, assign) CGFloat closeSlideAnimationDuration_;
@property (nonatomic, assign) CGFloat parallaxAmount_;

@property (nonatomic, strong) NSString *centerTapperAccessibilityLabel_;
@property (nonatomic, strong) NSString *centerTapperAccessibilityHint_;

-(id) initWithViewControllers:(GLDeckSubViewControllerMode *)subViewControllers;

-(void) setLeftSize:(CGFloat) leftSize completion:(void(^)(BOOL finished)) completion;
-(void) setrightSize:(CGFloat) rightSize completion:(void(^)(BOOL finished)) completion;
-(void) setTopSize:(CGFloat) topSize completion:(void(^)(BOOL finished)) completion;
-(void) setBottomSize:(CGFloat) bottomSize completion:(void(^)(BOOL finished)) completion;
-(void) setMaxSize:(CGFloat) maxSize completion:(void(^)(BOOL finished)) completion;

-(BOOL) toggleLeftView;
-(BOOL) openLeftView;
-(BOOL) closeLeftView;
-(BOOL) toggleLeftViewAnimated:(BOOL)animated;
-(BOOL) toggleLeftViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openLeftViewAnimated:(BOOL)animated;
-(BOOL) openLeftViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openLeftViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) openLeftViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeLeftViewAnimated:(BOOL)animated;
-(BOOL) closeLeftViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeLeftViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) closeLeftViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;

-(BOOL) toggleRightView;
-(BOOL) openRightView;
-(BOOL) closeRightView;
-(BOOL) toggleRightViewAnimated:(BOOL)animated;
-(BOOL) toggleRightViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openRightViewAnimated:(BOOL)animated;
-(BOOL) openRightViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openRightViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) openRightViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeRightViewAnimated:(BOOL)animated;
-(BOOL) closeRightViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeRightViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) closeRightViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;

-(BOOL) toggleTopView;
-(BOOL) openTopView;
-(BOOL) closeTopView;
-(BOOL) toggleTopViewAnimated:(BOOL)animated;
-(BOOL) toggleTopViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openTopViewAnimated:(BOOL)animated;
-(BOOL) openTopViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openTopViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) openTopViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeTopViewAnimated:(BOOL)animated;
-(BOOL) closeTopViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeTopViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) closeTopViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;

-(BOOL) toggleBottomView;
-(BOOL) openBottomView;
-(BOOL) closeBottomView;
-(BOOL) toggleBottomViewAnimated:(BOOL)animated;
-(BOOL) toggleBottomViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openBottomViewAnimated:(BOOL)animated;
-(BOOL) openBottomViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) openBottomViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) openBottomViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeBottomViewAnimated:(BOOL)animated;
-(BOOL) closeBottomViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeBottomViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) closeBottomViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;

-(BOOL) toggleOpenView;
-(BOOL) toggleOpenViewAnimated:(BOOL)animated;
-(BOOL) toggleOpenViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;

-(BOOL) closeOpenView;
-(BOOL) closeOpenViewAnimated:(BOOL)animated;
-(BOOL) closeOpenViewAnimated:(BOOL)animated completion:(GLDeckViewControllerBlock) completed;
-(BOOL) closeOpenViewAnimated:(BOOL)animated duration:(NSTimeInterval) duration completion:(GLDeckViewControllerBlock)completed;
-(BOOL) closeOpenViewBouncing:(GLDeckViewControllerBaounceBlock) bounced;
-(BOOL) closeOpenViewBouncing:(GLDeckViewControllerBaounceBlock) bounced completion:(GLDeckViewControllerBlock) completed;

-(BOOL) previewBounceView:(__enum_GLVIEW_SIDE) side;
-(BOOL) previewBounceView:(__enum_GLVIEW_SIDE) side completion:(GLDeckViewControllerBlock) completed;
-(BOOL) previewBounceView:(__enum_GLVIEW_SIDE)side toDistance:(CGFloat) distance duration:(NSTimeInterval)duration callDelegate:(BOOL)callDelegate completion:(GLDeckViewControllerBlock)completed;
-(BOOL) previewBounceView:(__enum_GLVIEW_SIDE)side toDistance:(CGFloat) distance duration:(NSTimeInterval)duration  numberOfBounces:(CGFloat) numberOfBouces dampingFactor:(CGFloat)zeta callDelegate:(BOOL)callDelegate completion:(GLDeckViewControllerBlock)completed;

-(BOOL) canRightViewPushViewControllerOverCenterController;
-(void) rightViewPushViewControllerOverCenterController:(UIViewController*)controller;

-(BOOL) isSideClosed:(__enum_GLVIEW_SIDE) viewSide;
-(BOOL) isSideOpen:(__enum_GLVIEW_SIDE) viewSide;
-(BOOL) isAnySideOpen;

-(CGFloat) statusBarHeight;
-(__enum_GLVIEW_SIDE) sideForController:(UIViewController*)controller;

@end

@interface UIViewController(GLViewDeckItem)

@property (nonatomic, strong, readonly) GLDeckViewController *deckViewController;

@end























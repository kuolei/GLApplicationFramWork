/*
 *  GLDeckConst.h
 *  GLApplication
 *
 *  Created by kuolei on 13-5-10.
 *  Copyright (c) 2013年 kuolei. All rights reserved.
 */

#ifndef GLApplication_GLDeckConst_h
#define GLApplication_GLDeckConst_h

static const UInt16 __GLVIEW_MAX_VIEWCONTROLLER_SIZE  = 6; ///< 定义最大支持的ViewController的数量

/**
 枚举类型
 标示当前ViewController所在的位置
 */
typedef enum
{
    GLVIEWSIDE_LEFT     = 0x1, /**< 在屏幕的左侧*/
    GLVIEWSIDE_RIGHT    = 0x2, /**< 在屏幕的右侧*/
    GLVIEWSIDE_TOP      = 0x3, /**< 在屏幕的顶部*/
    GLVIEWSIDE_BOTTOM   = 0x4, /**< 在屏幕的底部*/
} __enum_GLVIEW_SIDE;

/**
 枚举类型
 标示当前ViewController是垂直或者水平，和设备相关
 */
typedef enum
{
    GLVIEW_ORIENTATION_HORIZONTAL   = 0x1, /**< 水平*/
    GLVIEW_ORIENTATION_VERTICAL     = 0x2, /**< 垂直*/
    GLVIEW_ORIENTATION_NO           = 0x0, /**< 没有任何方位*/
} __enum_GLVIEW_ORIENTATION;

/**
 枚举类型
 表示Panning的模式
 */
typedef enum
{
    GLVIEW_PANNING_NO                       = 0x0,  /**< 没有Panning*/
    GLVIEW_PANNING_FULLSCREEN               = 0x1,  /**< 全屏模式*/
    GLVIEW_PANNING_NAVIGATION_BAR           = 0x2,  /**< 带Navigation Bar*/
    GLVIEW_PANNING_NAVIGATION_BAR_CENTER    = 0x3,  /**< 仅中间的ViewController带Navigation Bar*/
    GLVIEW_PANNING_VIEW                     = 0x4,  /**< 仅作用在View上*/
    GLVIEW_PANNING_ALL_VIEW                 = 0x5,  /**< 作用在所有View上*/
    GLVIEW_PANNING_WITH_DELEGATE            = 0x6,  /**< 带Delegate*/
} __enum_GLVIEW_PANNING_MODE;

/**
 枚举类型
 标示中间的Viewcontroller的隐藏交互模式
 */
typedef enum
{
    GLVIEW_HIDDEN_USER_INTERACTIVE                              = 0x1, /**< 保留用户交互*/
    GLVIEW_HIDDEN_NOT_USER_INTERACTIVE                          = 0x2, /**< 隐藏用户交互*/
    GLVIEW_HIDDEN_NOT_USER_INTERACTIVE_WITH_TAPCLOSE            = 0x3, /**< 隐藏用户交互，但是点击时可以关闭*/
    GLVIEW_HIDDEN_NOT_USER_INTERACTIVE_WITH_TAPCLOSE_BOUNCING   = 0x4, /**< 同GLVIEW_HIDDEN_NOT_USER_INTERACTIVE_WITH_TAPCLOSE 但是带有反弹效果*/
}  __enum_GLVIEW_CENTER_VIEWCONTROLLER_HIDDEN_INTERACTIVITY;

/**
 枚举类型
 标示中间ViewController的NavigationController装载方式
 */
typedef enum
{
    GLVIEW_NAVIGATION_CONTROLLER_CONTAINED      = 0x0,  /**< Center ViewController 包含了任何ViewController的Push和Pop事件*/
    GLVIEW_NAVIGATION_CONTROLLER_INTERGRATED    = 0x1,  /**< 所有的ViewCotroller都集成在DeckViewController中*/
} __enum_GLVIEW_NAVIGATION_CONTROLLER_BEHAVIOR;

/**
 枚举类型
 标示旋转时View的大小模式
 */
typedef enum
{
    GLVIEW_SIZE_LEDGE  = 0x0,  /**< 当设备旋转时，保持框架的大小（并且其他view可视）*/
    GLVIEW_SIZE_VIEW   = 0x1,  /**< 当设备旋转时，保持View的大小（但是框架的大小也随之改变）*/
} __enum_GLVIEW_SIZE_MODE;

/**
 枚举类型
 表示调用代理的模式
 */
typedef enum
{
    GLVIEW_DELEGATE_ONLY            = 0x0,  /**< 仅调用代理*/
    GLVIEW_DELEGATE_SUBCONTROLLERS  = 0x1,  /**< 子ViewController也调用此代理*/
} __enum_GLVIEW_DELEGATE_MODE;


enum {
    GLVIEW_DECK_NOSIDE = 0x0,
    GLVIEW_DECK_CENTERSIDE = 0x5,
};

enum {
    GLVIEW_DECK_NOORIENTATION = 0x0,
};

        
#define GL_CGRectOffsetLeftAndShrink(rect, offset)                      \
({__typeof__(rect) __r = (rect);                                        \
__typeof__(offset) __o = (offset);                                      \
(CGRect) {                                                              \
__r.origin.x + __o, __r.origin.y, __r.size.width-__o, __r.size.height   \
};                                                                      \
})

#define GL_CGRectShrink(rect, w, h)                             \
({                                                            \
__typeof__(rect) __r = (rect);                              \
__typeof__(w) __w = (w);                                    \
__typeof__(h) __h = (h);                                    \
(CGRect) {  __r.origin,                                     \
{ __r.size.width - __w, __r.size.height - __h}   \
};                                                 \
})

#define GL_CGRectOffsetBottomAndShrink(rect, offset)        \
({                                                        \
__typeof__(rect) __r = (rect);                          \
__typeof__(offset) __o = (offset);                      \
(CGRect) { { __r.origin.x, __r.origin.y },              \
{ __r.size.width, __r.size.height - __o}     \
};                                             \
})

#define GL_CGRectOffsetTopAndShrink(rect, offset)           \
({                                                        \
__typeof__(rect) __r = (rect);                          \
__typeof__(offset) __o = (offset);                      \
(CGRect) { { __r.origin.x,   __r.origin.y    + __o },   \
{ __r.size.width, __r.size.height - __o }    \
};                                             \
})

#define GL_CGRectOffsetRightAndShrink(rect, offset)         \
({                                                        \
__typeof__(rect) __r = (rect);                          \
__typeof__(offset) __o = (offset);                      \
(CGRect) {  { __r.origin.x, __r.origin.y },            \
{ __r.size.width - __o, __r.size.height }  \
};                                            \
})

#define GL_FLOAT_EQUAL(x, y) (((x) - (y)) == 0.0f)
#define GL_STRING_EQUAL(a, b) ((a == nil && b == nil) || (a != nil && [a isEqualToString:b]))


#endif

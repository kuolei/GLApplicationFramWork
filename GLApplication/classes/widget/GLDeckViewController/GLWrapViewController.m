//
//  GLWrapController.m
//  GLApplication
//
//  Created by new_ctrip on 13-5-16.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import "GLWrapViewController.h"
#import <objc/runtime.h>
#import <objc/message.h>
#import "GLDeckDefine.h"

@interface UIViewController (WrappedItem_Internal)
-(void)setWrapViewController:(GLWrapViewController *)wrapController;
@end

@interface GLWrapViewController ()

@end

@implementation GLWrapViewController
@synthesize m_wrappedViewController_;
@synthesize onViewDidLoad;
@synthesize onViewWillAppear;
@synthesize onViewDidAppear;
@synthesize onViewDidDisappear;
@synthesize onViewWillDisappear;

#pragma mark wrapViewController init fro ARC
-(id)initWithViewController:(UIViewController *)controller
{
    self = [super init];
    if (self != nil) {
        m_wrappedViewController_ = controller;
        [controller setWrapViewController:self];
    }
    return self;
}

-(CGFloat) statusBarHeight
{
    return UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)
                                             ? [UIApplication sharedApplication].statusBarFrame.size.width
                                             : [UIApplication sharedApplication].statusBarFrame.size.height;
}

-(void) loadView
{
    self.view = [[UIView alloc] initWithFrame:GL_CGRectOffsetTopAndShrink(m_wrappedViewController_.view.frame, [self statusBarHeight])];
    self.view.autoresizingMask = m_wrappedViewController_.view.autoresizingMask;
    m_wrappedViewController_.view.frame = self.view.bounds;
    m_wrappedViewController_.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    if ([self respondsToSelector:@selector(addChildViewController:)]) { // for ios 5
        [self addChildViewController:self.m_wrappedViewController_];
    }
    
    [self.view addSubview:self.m_wrappedViewController_.view];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
    if ([m_wrappedViewController_ respondsToSelector:@selector(didMoveToParentViewController:)]) {
        [m_wrappedViewController_ didMoveToParentViewController:self];
    }
    
    if (self.onViewDidLoad) {
        self.onViewDidLoad(self);
    }
}

-(void)viewDidUnload
{
    [super viewDidUnload];
    [self.m_wrappedViewController_.view removeFromSuperview];
}

-(void)dealloc
{
    if ([m_wrappedViewController_ respondsToSelector:@selector(willMoveToParentViewController:)]) {
        [m_wrappedViewController_ willMoveToParentViewController:nil];
    }
    
    if ([m_wrappedViewController_ respondsToSelector:@selector(removeFromParentViewController)]) {
        [m_wrappedViewController_ removeFromParentViewController];
    }
    
    if ([m_wrappedViewController_ respondsToSelector:@selector(didMoveToParentViewController:)]) {
        [m_wrappedViewController_ didMoveToParentViewController:nil];
    }
    
    m_wrappedViewController_ = nil;
}

-(UITabBarItem *)tabBarItem
{
    return m_wrappedViewController_.tabBarItem;
}

-(void)setTabBarItem:(UITabBarItem *)tabBarItem
{
    [m_wrappedViewController_ setTabBarItem:tabBarItem];
}

-(void)setHidesBottomBarWhenPushed:(BOOL)hidesBottomBarWhenPushed
{
    [m_wrappedViewController_ setHidesBottomBarWhenPushed:hidesBottomBarWhenPushed];
}

-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if (self.onViewWillAppear) {
        self.onViewWillAppear(self, animated);
    }
    
    [self.m_wrappedViewController_ viewWillAppear:animated];
}

-(void)viewDidAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if (self.onViewDidAppear) {
        self.onViewDidAppear(self, animated);
    }
    
    [self.m_wrappedViewController_ viewDidAppear:animated];
}

-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    if (self.onViewWillDisappear) {
        self.onViewWillDisappear(self, animated);
    }
    
    [self.m_wrappedViewController_ viewWillDisappear:animated];
}

-(void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    if (self.onViewDidDisappear) {
        self.onViewDidDisappear(self, animated);
    }
    
    [self.m_wrappedViewController_ viewDidDisappear:animated];
}

- (BOOL)shouldAutorotate {
    return [self.m_wrappedViewController_ shouldAutorotate];
}

- (NSUInteger)supportedInterfaceOrientations {
    return [self.m_wrappedViewController_ supportedInterfaceOrientations];
}

- (BOOL)automaticallyForwardAppearanceAndRotationMethodsToChildViewControllers {
    return NO;
}

- (BOOL)shouldAutomaticallyForwardAppearanceMethods {
    return NO;
}

- (BOOL)shouldAutomaticallyForwardRotationMethods {
    return NO;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return [self.m_wrappedViewController_ shouldAutorotateToInterfaceOrientation:interfaceOrientation];
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willAnimateRotationToInterfaceOrientation:toInterfaceOrientation duration:duration];
    [self.m_wrappedViewController_ willAnimateRotationToInterfaceOrientation:toInterfaceOrientation duration:duration];
}

- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willAnimateFirstHalfOfRotationToInterfaceOrientation:toInterfaceOrientation duration:duration];
    [self.m_wrappedViewController_ willAnimateFirstHalfOfRotationToInterfaceOrientation:toInterfaceOrientation duration:duration];
}

- (void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willAnimateSecondHalfOfRotationFromInterfaceOrientation:fromInterfaceOrientation duration:duration];
    [self.m_wrappedViewController_ willAnimateSecondHalfOfRotationFromInterfaceOrientation:fromInterfaceOrientation duration:duration];
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willRotateToInterfaceOrientation:toInterfaceOrientation duration:duration];
    [self.m_wrappedViewController_ willRotateToInterfaceOrientation:toInterfaceOrientation duration:duration];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
    [self.m_wrappedViewController_ didRotateFromInterfaceOrientation:fromInterfaceOrientation];
}

- (void)didReceiveMemoryWarning {
    [self.m_wrappedViewController_ didReceiveMemoryWarning];
}

- (id)forwardingTargetForSelector:(SEL)aSelector {
    if ([self.m_wrappedViewController_ respondsToSelector:aSelector])
        return self.m_wrappedViewController_;
    return nil;
}

- (BOOL)respondsToSelector:(SEL)aSelector {
    if ([super respondsToSelector:aSelector]) return YES;
    return [self.m_wrappedViewController_ respondsToSelector:aSelector];
}

@end


@implementation UIViewController (WrapControllerItem)

@dynamic m_wrapController_;

static const char* wrapControllerKey = "WrapController";

- (GLWrapViewController*)wrapController_core {
    return objc_getAssociatedObject(self, wrapControllerKey);
}

- (GLWrapViewController*)wrapController {
    id result = [self wrapController_core];
    if (!result && self.navigationController)
        return [self.navigationController wrapController];
    
    return result;
}

- (void)setWrapController:(GLWrapViewController*)wrapController {
    objc_setAssociatedObject(self, wrapControllerKey, wrapController, OBJC_ASSOCIATION_ASSIGN);
}

- (UINavigationController*)wc_navigationController {
    UIViewController* controller = self.wrapController_core ? self.wrapController_core : self;
    return [controller wc_navigationController]; // when we get here, the wc_ method is actually the old, real method
}

- (UINavigationItem*)wc_navigationItem {
    UIViewController* controller = self.wrapController_core ? self.wrapController_core : self;
    return [controller wc_navigationItem]; // when we get here, the wc_ method is actually the old, real method
}


+ (void)wc_swizzle {
    SEL nc = @selector(navigationController);
    SEL wcnc = @selector(wc_navigationController);
    method_exchangeImplementations(class_getInstanceMethod(self, nc), class_getInstanceMethod(self, wcnc));
    
    SEL ni = @selector(navigationItem);
    SEL wcni = @selector(wc_navigationItem);
    method_exchangeImplementations(class_getInstanceMethod(self, ni), class_getInstanceMethod(self, wcni));
}

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        @autoreleasepool {
            [self wc_swizzle];
        }
    });
}

@end



























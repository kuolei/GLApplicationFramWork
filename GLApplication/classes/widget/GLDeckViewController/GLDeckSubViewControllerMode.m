//
//  GLDeckSubViewControllerMode.m
//  GLApplication
//
//  Created by new_ctrip on 13-5-10.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import "GLDeckSubViewControllerMode.h"

@implementation GLDeckSubViewControllerMode
@synthesize centerViewController_ = m_centerViewController_;
@synthesize leftViewController_ = m_leftViewController_;
@synthesize rightViewController_ = m_rightViewController_;
@synthesize topViewController_ = m_topViewController_;
@synthesize bottomViewController_ = m_bottomViewController_;

-(id) init
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = nil;
        self.leftViewController_ = nil;
        self.rightViewController_ = nil;
        self.topViewController_ = nil;
        self.bottomViewController_ = nil;
    }
    return self;
}

-(id) initWithViewController:(UIViewController*) centerViewController
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = centerViewController;
        self.leftViewController_ = nil;
        self.rightViewController_ = nil;
        self.topViewController_ = nil;
        self.bottomViewController_ = nil;
    }
    return self;
}

-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = centerViewController;
        self.leftViewController_ = leftViewController;
        self.rightViewController_ = nil;
        self.topViewController_ = nil;
        self.bottomViewController_ = nil;
    }
    return self;
}

-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController*)rightViewController
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = centerViewController;
        self.leftViewController_ = leftViewController;
        self.rightViewController_ = rightViewController;
        self.topViewController_ = nil;
        self.bottomViewController_ = nil;
    }
    return self;
}

-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController *)rightViewController topViewControlller:(UIViewController *)topViewController
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = centerViewController;
        self.leftViewController_ = leftViewController;
        self.rightViewController_ = rightViewController;
        self.topViewController_ = topViewController;
        self.bottomViewController_ = nil;
    }
    return self;
}

-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController *)rightViewController topViewControlller:(UIViewController *)topViewController bottomViewController:(UIViewController *)bottomViewController
{
    self = [super init];
    if (self != nil) {
        self.centerViewController_ = centerViewController;
        self.leftViewController_ = leftViewController;
        self.rightViewController_ = rightViewController;
        self.topViewController_ = topViewController;
        self.bottomViewController_ = bottomViewController;
    }
    return self;
}

-(id) initWithViewControllerArray:(NSArray *)viewControllers
{
    self = [super init];
    if (self != nil) {
        int count = [viewControllers count];
        switch (count) {
            case 1:
                {
                    self.centerViewController_ = [viewControllers objectAtIndex:0];
                    self.leftViewController_ = nil;
                    self.rightViewController_ = nil;
                    self.topViewController_ = nil;
                    self.bottomViewController_ = nil;            
                }
                break;
            case 2:
            {
                self.centerViewController_ = [viewControllers objectAtIndex:0];
                self.leftViewController_ =  [viewControllers objectAtIndex:1];
                self.rightViewController_ = nil;
                self.topViewController_ = nil;
                self.bottomViewController_ = nil;
            }
                break;
            case 3:
            {
                self.centerViewController_ = [viewControllers objectAtIndex:0];
                self.leftViewController_ =  [viewControllers objectAtIndex:1];
                self.rightViewController_ =  [viewControllers objectAtIndex:2];
                self.topViewController_ =  nil;
                self.bottomViewController_ =  nil;
            }
                break;
            case 4:
            {
                self.centerViewController_ = [viewControllers objectAtIndex:0];
                self.leftViewController_ =  [viewControllers objectAtIndex:1];
                self.rightViewController_ =  [viewControllers objectAtIndex:2];
                self.topViewController_ =  [viewControllers objectAtIndex:3];
                self.bottomViewController_ = nil;
            }
                break;
            case 5:
            {
                self.centerViewController_ = [viewControllers objectAtIndex:0];
                self.leftViewController_ =  [viewControllers objectAtIndex:1];
                self.rightViewController_ =  [viewControllers objectAtIndex:2];
                self.topViewController_ =  [viewControllers objectAtIndex:3];
                self.bottomViewController_ =  [viewControllers objectAtIndex:4];
            }
                break;
            default:
            {
                self.centerViewController_ = nil;
                self.leftViewController_ = nil;
                self.rightViewController_ = nil;
                self.topViewController_ = nil;
                self.bottomViewController_ = nil;
            }
                break;
        }
    }
    return self;
}

@end

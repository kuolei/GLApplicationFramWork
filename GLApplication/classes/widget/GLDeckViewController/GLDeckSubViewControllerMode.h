//
//  GLDeckSubViewControllerMode.h
//  GLApplication
//
//  Created by new_ctrip on 13-5-10.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GLDeckSubViewControllerMode : NSObject
{
    UIViewController *m_centerViewController_;
    UIViewController *m_leftViewController_;
    UIViewController *m_rightViewController_;
    UIViewController *m_topViewController_;
    UIViewController *m_bottomViewController_;
}

@property (nonatomic, strong) UIViewController *centerViewController_;
@property (nonatomic, strong) UIViewController *leftViewController_;
@property (nonatomic, strong) UIViewController *rightViewController_;
@property (nonatomic, strong) UIViewController *topViewController_;
@property (nonatomic, strong) UIViewController *bottomViewController_;

-(id) initWithViewController:(UIViewController*) centerViewController;
-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController;
-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController*)rightViewController;
-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController *)rightViewController topViewControlller:(UIViewController *)topViewController;
-(id) initWithViewController:(UIViewController *)centerViewController leftViewController:(UIViewController *)leftViewController rightViewController:(UIViewController *)rightViewController topViewControlller:(UIViewController *)topViewController bottomViewController:(UIViewController *)bottomViewController;

-(id) initWithViewControllerArray:(NSArray *)viewControllers;

@end

//
//  GLSideViewController.h
//  GLApplication
//
//  Created by new_ctrip on 13-5-17.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import "GLWrapViewController.h"

@interface GLSideViewController : GLWrapViewController
@property (nonatomic, assign) CGFloat constrainedSize;

-(id) initWithViewController:(UIViewController *)controller constrained:(CGFloat) constrainedSize;

-(void)shrinkSide;
-(void)shrinkSideAnimated:(BOOL)animated;

@end

@interface UIViewController(GLSideViewController)
@property(nonatomic, readonly, strong) GLSideViewController *sideViewController;
@end
//
//  GLSideViewController.m
//  GLApplication
//
//  Created by new_ctrip on 13-5-17.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import "GLSideViewController.h"
#import "GLDeckViewController.h"
#import <QuartzCore/QuartzCore.h>

@interface GLSideViewController ()

@end

@implementation GLSideViewController

- (id)initWithViewController:(UIViewController*)controller constrained:(CGFloat)constrainedSize {
    if ((self = [super initWithViewController:controller])) {
        _constrainedSize = constrainedSize;
    }
    return self;
}

- (id)initWithViewController:(UIViewController*)controller {
    if ((self = [super initWithViewController:controller])) {
        _constrainedSize = -1;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self shrinkSide];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    self.view.backgroundColor = self.m_wrappedViewController_.view.backgroundColor;
    [self shrinkSideAnimated:animated];
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    [super willAnimateRotationToInterfaceOrientation:toInterfaceOrientation duration:duration];
    [self shrinkSideAnimated:YES];
}

- (void)setConstrainedSize:(CGFloat)constrainedSize {
    [self setConstrainedSize:constrainedSize animated:YES];
}

- (void)setConstrainedSize:(CGFloat)constrainedSize animated:(BOOL)animated {
    _constrainedSize = constrainedSize;
    [self shrinkSideAnimated:animated];
}

- (void)shrinkSide {
    [self shrinkSideAnimated:YES];
}

- (void)shrinkSideAnimated:(BOOL)animated {
    if (self.deckViewController) {
        // we don't want this animated
        [CATransaction begin];
        if (animated) {
            [UIView beginAnimations:@"shrinkSide" context:nil];
            [UIView setAnimationDuration:0.3];
            [UIView setAnimationCurve:UIViewAnimationCurveEaseInOut];
        }
        else {
            [CATransaction disableActions];
        }
        
        if (self.deckViewController.leftViewController_ == self) {
            CGFloat offset = self.view.bounds.size.width - (_constrainedSize > 0 ? _constrainedSize : self.deckViewController.leftViewSize_);
            self.m_wrappedViewController_.view.frame = GL_CGRectOffsetRightAndShrink(self.view.bounds, offset);
        }
        else if (self.deckViewController.rightViewController_ == self) {
            CGFloat offset = self.view.bounds.size.width - (_constrainedSize > 0 ? _constrainedSize : self.deckViewController.rightViewSize_);
            self.m_wrappedViewController_.view.frame = GL_CGRectOffsetLeftAndShrink(self.view.bounds, offset);
        }
        else if (self.deckViewController.topViewController_ == self) {
            CGFloat offset = self.view.bounds.size.height - (_constrainedSize > 0 ? _constrainedSize : self.deckViewController.topViewSize_);
            self.m_wrappedViewController_.view.frame = GL_CGRectOffsetBottomAndShrink(self.view.bounds, offset);
        }
        else if (self.deckViewController.bottomViewController_ == self) {
            CGFloat offset = self.view.bounds.size.height - (_constrainedSize > 0 ? _constrainedSize : self.deckViewController.bottomViewSize_);
            self.m_wrappedViewController_.view.frame = GL_CGRectOffsetTopAndShrink(self.view.bounds, offset);
        }
        
        if (animated) {
            [UIView commitAnimations];
        }
        [CATransaction commit];
    }
}

@end

//
//  GLDeckViewControllerDelegate.h
//  GLApplication
//
//  Created by new_ctrip on 13-5-8.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GLDeckDefine.h"

@class GLDeckViewController;

@protocol GLDeckViewControllerDelegate <NSObject>

@optional
-(BOOL) deckViewController:(GLDeckViewController *)deckViewController shouldPan:(UIPanGestureRecognizer *) panGuestureRecognizer;
-(void) deckViewController:(GLDeckViewController *)deckViewController applyShadow:(CALayer *) shadowLayer withBounds:(CGRect) rect;
-(void) deckViewController:(GLDeckViewController *)deckViewController didChangeOffset:(CGFloat) offset orientation:(__enum_GLVIEW_ORIENTATION) orientation panning:(BOOL) panning;
-(void) deckViewController:(GLDeckViewController *)deckViewController didBounceViewSide:(__enum_GLVIEW_SIDE) deckViewSide openingController:(UIViewController *) openingController;
-(void) deckViewController:(GLDeckViewController *)deckViewController didBounceViewSide:(__enum_GLVIEW_SIDE) deckViewSide closeingController:(UIViewController *) closeingConroller;

-(BOOL) deckViewController:(GLDeckViewController *)deckViewController shouldOpenViewSide:(__enum_GLVIEW_SIDE) deckViewSide;
-(void) deckViewController:(GLDeckViewController *)deckViewController willOpenViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;
-(void) deckViewController:(GLDeckViewController *)deckViewController didOpenViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;

-(BOOL) deckViewController:(GLDeckViewController *) deckViewController shouldCloseViewSide:(__enum_GLVIEW_SIDE) deckViewSide;
-(void) deckViewController:(GLDeckViewController *) deckViewController willCloseViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;
-(void) deckViewController:(GLDeckViewController *) deckViewController didCloseViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;

-(void) deckViewController:(GLDeckViewController *) deckViewController didShowCenterViewFromSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;

-(BOOL) deckviewController:(GLDeckViewController *) deckViewController shouldPreviewBounceViewSide:(__enum_GLVIEW_SIDE) deckViewSide;
-(void) deckViewController:(GLDeckViewController *) deckViewController willPreviewBounceViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;
-(void) deckViewController:(GLDeckViewController *) deckViewController didPreviewBounceViewSide:(__enum_GLVIEW_SIDE) deckViewSide animated:(BOOL) animated;

-(CGFloat) deckViewController:(GLDeckViewController *) deckViewController changeLedge:(CGFloat) ledge forSide:(__enum_GLVIEW_SIDE) deckViewSide;

@end

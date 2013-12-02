//
//  GLWrapController.h
//  GLApplication
//
//  Created by new_ctrip on 13-5-16.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GLWrapViewController : UIViewController

@property(nonatomic, readonly, strong) UIViewController *m_wrappedViewController_;
@property(nonatomic, copy) void(^onViewDidLoad)(GLWrapViewController *controller);
@property(nonatomic, copy) void(^onViewWillAppear)(GLWrapViewController *controller, BOOL animated);
@property(nonatomic, copy) void(^onViewDidAppear)(GLWrapViewController *controller, BOOL animated);
@property(nonatomic, copy) void(^onViewWillDisappear)(GLWrapViewController *controller, BOOL animated);
@property(nonatomic, copy) void(^onViewDidDisappear)(GLWrapViewController *controller, BOOL animated);

-(id)initWithViewController:(UIViewController *)controller;
@end

@interface UIViewController (WrapControllerItem)

@property(nonatomic, readonly, weak) GLWrapViewController *m_wrapController_;

@end

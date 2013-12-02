//
//  GLUserInfo.m
//  GLApplication
//
//  Created by new_ctrip on 13-5-7.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import "GLUserInfo.h"

@implementation GLUserInfo


+(GLUserInfo*) shareInstance
{
    static GLUserInfo *userInfo;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        userInfo = [[GLUserInfo alloc] init];
    });
    
    return userInfo;
}

-(void) dealloc
{
    //单例类不能重载[super dealloc]
}

@end

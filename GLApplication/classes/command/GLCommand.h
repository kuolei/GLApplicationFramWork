//
//  GLCommand.h
//  GLApplication
//
//  Created by new_ctrip on 13-5-7.
//  Copyright (c) 2013年 kuolei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFHTTPClient.h"
#import "GLUserInfo.h"



/**
	所有command的父类，其他command必须从此类继承
	@author kuolei
    @breifs
 */
@interface GLCommand : NSObject
{
@protected
    NSDictionary * userInfo_;
}

/**
	<#Description#>
 */
@property (nonatomic, strong) NSDictionary *userInfo_;

/**
	<#Description#>
	@param  (NSError <# (NSError description#>
 */
-(void) excute:(NSDictionary *)user_info
       success:(void(^) (NSDictionary *result))sucess
       failure:(void(^) (NSError *error)) failure;
/**
	<#Description#>
 */
-(void) undo;


@end

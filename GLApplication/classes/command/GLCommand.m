/*
 *  GLCommand.m
 *  GLApplication
 *
 *  Created by kuolei on 13-5-7.
 *  Copyright (c) 2013年 kuolei. All rights reserved.
 */

#import "GLCommand.h"

@interface GLCommand()

-(NSError *) checkParameter:(NSDictionary *)user_info;

@end

@implementation GLCommand
@synthesize userInfo_;

-(NSError *) checkParameter:(NSDictionary *)user_info
{
    return nil;
}


-(void) excute:(NSDictionary *)user_info
       success:(void(^) (NSDictionary *result))sucess
       failure:(void(^) (NSError *error)) failure
{

}

-(void) undo
{

}

@end

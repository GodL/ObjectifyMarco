//
//  NSString+Objectify.m
//  ObjectifyMarco
//
//  Created by 李浩 on 2017/4/1.
//  Copyright © 2017年 GodL. All rights reserved.
//

#import "NSString+Objectify.h"

@implementation NSString (Objectify)

- (Class)om_classify
{
    return NSClassFromString(self);
}

@end

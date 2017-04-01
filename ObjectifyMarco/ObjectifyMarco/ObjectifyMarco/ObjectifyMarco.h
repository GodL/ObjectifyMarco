//
//  ObjectifyMarco.h
//  ObjectifyMarco
//
//  Created by 李浩 on 2017/4/1.
//  Copyright © 2017年 GodL. All rights reserved.
//

#ifndef ObjectifyMarco_h
#define ObjectifyMarco_h

#import "NSString+Objectify.h"

#define om_concat_(A,B) A ## B

#define om_concat(A,B) om_concat_(A,B)

#define om_stringify_(A) # A

#define om_arg(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,...) _10

#define om_argcount_(...) om_arg(__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)

#define om_argcount(...) om_argcount_(__VA_ARGS__)

#define OM_PASTEARG2(A,B) om_concat(A,B)

#define OM_PASTEARG3(A,B,C) \
    OM_PASTEARG2(OM_PASTEARG2(A,B),C)

#define OM_PASTEARG4(A,B,C,D) \
    OM_PASTEARG2(OM_PASTEARG3(A,B,C),D)

#define OM_PASTEARG5(A,B,C,D,E) \
    OM_PASTEARG2(OM_PASTEARG4(A,B,C,D),E)

#define OM_PASTEARG6(A,B,C,D,E,F) \
    OM_PASTEARG2(OM_PASTEARG5(A,B,C,D,E),F)

#define OM_PASTEARG7(A,B,C,D,E,F,G) \
    OM_PASTEARG2(OM_PASTEARG6(A,B,C,D,E,F),G)

#define OM_PASTEARG8(A,B,C,D,E,F,G,H) \
    OM_PASTEARG2(OM_PASTEARG7(A,B,C,D,E,F,G),H)

#define OM_PASTEARG9(A,B,C,D,E,F,G,H,I) \
    OM_PASTEARG2(OM_PASTEARG8(A,B,C,D,E,F,G,H),I)

#define OM_PASTEARG(...) \
    om_concat(OM_PASTEARG,om_argcount(__VA_ARGS__))(__VA_ARGS__)

#define OM_ClassForceify(obj,Class) \
    (NO && ((void)[Class class],NO),((Class*)obj))

#define OM_BasicForceity(obj,type) \
    ((type)obj)

#define OM_Init(block) \
    - (instancetype)init { \
        self = [super init]; \
        if (self) { \
            block(); \
        } \
        return self; \
    } \

#define classify(Class) \
    (((NO && ([Class class],NO)),# Class)).om_classify

#define selectorify(sel) \
    ((NO && (@selector(sel),NO)),sel)

#define initializeify(Class) \
    classify(Class).new

#define modelify(Class,JSON) \
    [@classify(Class) yy_modelWithDictionary:JSON]

#define modelsify(Class,JSON) \
    [NSArray yy_modelArrayWithClass:@classify(Class) json:JSON]

#define scheduleify_argcount_if_1(selector) \
    selector

#define scheduleify_argcount_if_2(selector,arg) \
    selector arg

#define sequentialCallify_argcount_if_1(OBJ,sel) \
    scheduleify(OBJ,sel)

#define sequentialCallify_argcount_if_2(OBJ,sel1,sel2) \
    scheduleify(scheduleify(OBJ,sel1),sel2)

#define sequentialCallify_argcount_if_3(OBJ,sel1,sel2,sel3) \
    scheduleify(scheduleify(scheduleify(OBJ,sel1),sel2),sel3)

#define sequentialCallify_argcount_if_4(OBJ,sel1,sel2,sel3,sel4) \
    scheduleify(scheduleify(scheduleify(scheduleify(OBJ,sel1),sel2),sel3) \
    ,sel4)

#define sequentialCallify_argcount_if_5(OBJ,sel1,sel2,sel3,sel4,sel5) \
    scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(OBJ,sel1),sel2) \
    ,sel3),sel4),sel5)

#define sequentialCallify_argcount_if_6(OBJ,sel1,sel2,sel3,sel4,sel5,sel6) \
    scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(OBJ,sel1) \
    ,sel2),sel3),sel4),sel5),sel6)

#define sequentialCallify_argcount_if_7(OBJ,sel1,sel2,sel3,sel4,sel5,sel6,sel7) \
    scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(OBJ \
    ,sel1),sel2),sel3),sel4),sel5),sel6),sel7)

#define sequentialCallify_argcount_if_8(OBJ,sel1,sel2,sel3,sel4,sel5,sel6,sel7,sel8) \
    scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify \
    (OBJ,sel1),sel2),sel3),sel4),sel5),sel6),sel7),sel8)

#define sequentialCallify_argcount_if_9(OBJ,sel1,sel2,sel3,sel4,sel5,sel6,sel7,sel8,sel9) \
    scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify(scheduleify( \
    scheduleify(OBJ,sel1),sel2),sel3),sel4),sel5),sel6),sel7),sel8),sel9)

#define scheduleify(OBJ,...) \
    [OBJ OM_PASTEARG2(scheduleify_argcount_if_,om_argcount(__VA_ARGS__))(__VA_ARGS__)]

#define sequentialCallify(OBJ,...) \
    OM_PASTEARG(sequentialCallify_argcount_if_,om_argcount(__VA_ARGS__))(OBJ,__VA_ARGS__)

#endif /* ObjectifyMarco_h */

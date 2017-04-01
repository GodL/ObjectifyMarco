//
//  ViewController.m
//  ObjectifyMarco
//
//  Created by 李浩 on 2017/4/1.
//  Copyright © 2017年 GodL. All rights reserved.
//

#import "ViewController.h"
#import "ObjectifyMarco/ObjectifyMarco.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //对象化
    do {
        ViewController* vc = @initializeify(ViewController);
        (void)vc;
    } while (0);
    
    
    do {
        ViewController* vc = recursionCallify(ViewController,new);
        (void)vc;
    } while (0);
    
    do {
        ViewController* vc = recursionCallify(ViewController,alloc,init);
        (void)vc;
    } while (0);
    
    do {
        UILabel* label = @initializeify(UILabel);
        sequentialCallify(label,setTag:11,setText:@"",setFont:nil,setEnabled:YES);
    } while (0);
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

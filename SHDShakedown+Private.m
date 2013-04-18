//
//  SHDShakedown+Private.m
//  Shakedown
//
//  Created by Max Goedjen on 4/18/13.
//  Copyright (c) 2013 Max Goedjen. All rights reserved.
//

#import "SHDShakedown+Private.h"
#import "SHDBugReport.h"
#import "SHDShakedownReporter.h"
#import "SHDShakedownEmailReporter.h"

@implementation SHDShakedown (Private)

- (void)submitReport:(SHDBugReport *)bugReport {
    if (self.reporter == nil) {
        self.reporter = [[SHDShakedownEmailReporter alloc] init];
        NSLog(@"SHAKEDOWN WARNING: NO REPORTER SPECIFIED, FALLING BACK TO EMAIL");
    }
    [self.reporter reportBug:bugReport];
}

@end

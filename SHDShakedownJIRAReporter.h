//
//  SHDShakedownJIRAReporter.h
//  Shakedown
//
//  Created by Max Goedjen on 4/27/13.
//  Copyright (c) 2013 Max Goedjen. All rights reserved.
//

#import "SHDShakedownReporter.h"

@interface SHDShakedownJIRAReporter : SHDShakedownReporter

@property (nonatomic, strong) NSString *apiURL;
@property (nonatomic, strong) NSString *login;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *project;

@end

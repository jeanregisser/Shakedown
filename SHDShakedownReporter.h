//
//  SHDShakedownReporter.h
//  Shakedown
//
//  Created by Max Goedjen on 4/18/13.
//  Copyright (c) 2013 Max Goedjen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SHDBugReport.h"

@protocol  SHDShakedownReporterDelegate <NSObject>

- (void)shakedownFailedToFileBug:(NSString *)message;
- (void)shakedownCancelledReportingBug;
- (void)shakedownFiledBugSuccessfullyWithLink:(NSURL *)url;

@end

@interface SHDShakedownReporter : NSObject

@property (nonatomic, weak) id <SHDShakedownReporterDelegate> delegate;
@property (nonatomic, readonly) UIViewController *topViewController;

- (void)reportBug:(SHDBugReport *)bugReport;

- (NSString *)base64StringFromString:(NSString *)string;
- (NSString *)base64StringFromData:(NSData *)data;

- (NSData *)httpBodyDataForDictionary:(NSDictionary *)dictionary attachments:(NSDictionary *)attachments boundary:(NSString *)boundary;

@end

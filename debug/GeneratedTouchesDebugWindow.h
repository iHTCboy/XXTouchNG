/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIApplication.h>
#import <AppSupport/CPDistributedMessagingCenter.h>


typedef NS_ENUM(NSUInteger, GeneratedTouchesDebugWindowRole) {
    GeneratedTouchesDebugWindowRoleClient = 0,
    GeneratedTouchesDebugWindowRoleServer,
};

@interface GeneratedTouchesDebugWindow : NSObject
@property (nonatomic, strong) CPDistributedMessagingCenter *messagingCenter;
@property (nonatomic, assign, readonly) GeneratedTouchesDebugWindowRole role;

+ (NSString *)messagingCenterName;
+ (GeneratedTouchesDebugWindow *)sharedGeneratedTouchesDebugWindow;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, assign) BOOL shouldShowTouches;

- (void)updateDebugIndicatorForTouch:(NSUInteger)index
        withPointInWindowCoordinates:(CGPoint)point
                          isTouching:(BOOL)isTouching;

- (void)makeToast:(NSString *)message
         duration:(NSTimeInterval)duration
         position:(id)position
      orientation:(UIInterfaceOrientation)orientation;
- (void)hideToasts;

- (void)showToastActivity;
- (void)hideToastActivity;

- (void)setLogBarColorInHexString:(NSString *)hexString;

@end


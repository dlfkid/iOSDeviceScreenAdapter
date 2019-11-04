//
//  DeviceScreenAdaptor.h
//  ScreenAdapterDemo
//
//  Created by LeonDeng on 2019/1/25.
//  Copyright © 2019 LeonDeng. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define DSAdaptedWidthValue(standardValue) (adaptedWidthValue(standardValue))
#define DSAdaptedHeightValue(standardValue) (adaptedHeightValue(standardValue))
#define DSStatusBarMargin (statusBarMargin())
#define DSBottomMargin (bottomMargin())
#define DSNavigationBarMargin (navigationBarMargin())


/**
 Screen type of current device
 */
typedef NS_ENUM(NSInteger, DeviceScreenType) {
    DeviceScreenTypeUnknown, /// DeviceScreenTypeUnknown: Unknown screenType, maybe a new iPhone or simulator
    DeviceScreenType3_5, /// DeviceScreenType3_5: 1, 3G, 3Gs, 4, 4s
    DeviceScreenType4_0, /// DeviceScreenType4_0: 5, 5s, 5c, se, iPod Touch 5, iPod Touch 6
    DeviceScreenType4_7, /// DeviceScreenType4_7: 6, 6s, 7, 8
    DeviceScreenType5_5, /// DeviceScreenType5_5: 6Plus, 6sPlus, 7Plus, 8Plus
    DeviceScreenType5_8, /// DeviceScreenType5_8: X, Xs
    DeviceScreenType6_1, /// DeviceScreenType6_1: XR
    DeviceScreenType6_5, /// DeviceScreenType6_5: Xs Max
    DeviceScreenType9_7, /// DeviceScreenType9_7: iPad Pro, iPad Air, iPad Air 2, iPad 4, iPad 3
    DeviceScreenType10_5, ///  DeviceScreenType10_5: iPad Pro
    DeviceScreenType11, /// DeviceScreenType11: iPad Pro
    DeviceScreenType12_9 /// DeviceScreenType12_9: iPad Pro
};


/**
 Actual type of current device, simulator not included
 */
typedef NS_ENUM(NSInteger,DeviceType) {
    
    Unknown = 0, /// Unknown: unknown type, maybe new iphone or simulator
    Simulator = 1, /// Simulator: simulator, not supported for most functions of this frameWork
    IPhone_1G = 2, /// IPhone_1G: Not supported
    IPhone_3G = 3, /// IPhone_3G: Not supported
    IPhone_3GS = 4, /// IPhone_3GS: Not supported
    IPhone_4 = 5, /// IPhone_4:  supported
    IPhone_4S = 6, /// IPhone_4S: supported
    IPhone_5 = 7, /// IPhone_5: supported
    IPhone_5C = 8, /// IPhone_5C: supported
    IPhone_5S = 9, /// IPhone_5S: supported
    IPhone_SE = 10, /// IPhone_SE: supported
    IPhone_6 = 11, /// IPhone_6: supported
    IPhone_6P = 12, /// IPhone_6P: supported
    IPhone_6S = 13, /// IPhone_6S: supported
    IPhone_6S_P = 14, /// IPhone_6S_P: supported
    IPhone_7 = 15, /// IPhone_7: supported
    IPhone_7P = 16, /// IPhone_7P: supported
    IPhone_8 = 17, /// IPhone_8: supported
    IPhone_8P = 18, /// IPhone_8P: supported
    IPhone_X = 19, /// IPhone_X: supported
    IPhone_XS = 20, /// IPhone_XS: supported
    IPhone_XSMax = 21, /// IPhone_XSMax: supported
    IPhone_XR = 22, /// IPhone_XR: supported
    IPhone_11 = 23,
    IPhone_11_Pro = 24,
    IPhone_11_Pro_Max = 25,
};


/**
 An singleton to help the developer to resolve screen related problems
 */
@interface DeviceScreenAdaptor : NSObject
/**
 Device type of current device (simulator not included)
 */
@property (nonatomic, assign, readonly) DeviceType deviceType;

/**
 Device type in string
 */
@property (nonatomic, copy, readonly) NSString *deviceTypeString;

/**
 Current screen type
 */
@property (nonatomic, assign, readonly) DeviceScreenType screenType;

/**
 Wether the screen is in landscape state
 */
@property (nonatomic, assign, readonly) BOOL isLandscape;

/**
 Return the height of status bar
 */
@property (nonatomic, assign, readonly) CGFloat statusBarMargin;

/**
 Return the bottom indicator height
 */
@property (nonatomic, assign, readonly) CGFloat bottomIndicatorMargin;

/**
 Get singleton instance

 @return the shared screen adaptor
 */
+ (DeviceScreenAdaptor *)sharedAdaptor;


/**
 Transfer the UI value to adapt other screen

 @param standardValue the value you used when coding with your develop iOS device.
 @param isWidthBased decide wether the value taransform scale is based on screen width
 @return the transfered value when running in other screen type devices.
 */
+ (CGFloat)adaptedValue:(CGFloat)standardValue ScreenWidthBased:(BOOL)isWidthBased;


/**
 Simply tell you wether the screen is in landscape.

 @return the screen is currently landscape or not
 */
+ (BOOL)isLandscape;


/**
 The screen type of current device

 @return predefined screen type enum
 */
+ (DeviceScreenType)screenType;


/**
 The type of the  current device

 @return predefined device type enum
 */
+ (DeviceType)deviceType;


/**
 The device type in string class

 @return device type string
 */
+ (NSString *)deviceTypeString;


/**
 Return the height of statusBar, NAVIGATIONBAR HEIGHT NOT INCLUDED

 @return status bar height
 */
+ (CGFloat)statusBarMargin;

/**
 Return the Height of statusBar + navigationBar
 
 @return navigationBar height
 */
+ (CGFloat)navigationBarMargin;

/**
 Return the height of bottom indicator

 @return bottom indocator
 */
+ (CGFloat)bottomIndicatorMargin;


/**
 Set the screen type you are using when developing
 @param type the screen type you choosed as standard screen
 */
- (void)setDeveloperScreenType:(DeviceScreenType)type;

@end

CG_INLINE CGFloat adaptedWidthValue(CGFloat standardValue) {
    return [DeviceScreenAdaptor adaptedValue:standardValue ScreenWidthBased:YES];
}

CG_INLINE CGFloat adaptedHeightValue(CGFloat standardValue) {
    return [DeviceScreenAdaptor adaptedValue:standardValue ScreenWidthBased:NO];
}

CG_INLINE CGFloat statusBarMargin() {
    return [DeviceScreenAdaptor statusBarMargin];
}

CG_INLINE CGFloat bottomMargin() {
    return [DeviceScreenAdaptor bottomIndicatorMargin];
}

CG_INLINE CGFloat navigationBarMargin() {
    return [DeviceScreenAdaptor navigationBarMargin];
}

/**
 Return current screen width
 */
static inline CGFloat DSScreenWidth() {
    CGFloat screenWidth = CGRectGetWidth([UIScreen mainScreen].bounds);
    
    BOOL iOSVersionGreaterThan8 = [[[UIDevice currentDevice] systemVersion] compare:@"8" options:NSNumericSearch] == NSOrderedDescending;
    
    if (iOSVersionGreaterThan8) {
        UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
        
        if (orientation ==  UIDeviceOrientationPortrait) {
            screenWidth = CGRectGetWidth([UIScreen mainScreen].bounds);
        }
        else if((orientation == UIDeviceOrientationLandscapeRight) || (orientation == UIInterfaceOrientationLandscapeLeft)) {
            screenWidth = CGRectGetHeight([UIScreen mainScreen].bounds);
        }
    }
    
    return screenWidth;
}

/**
 Return current screen height
 */
static inline CGFloat DSScreenHeight() {
    CGFloat screenHeight = CGRectGetHeight([UIScreen mainScreen].bounds);
    
    BOOL iOSVersionGreaterThan8 = [[[UIDevice currentDevice] systemVersion] compare:@"8" options:NSNumericSearch] == NSOrderedDescending;
    
    if (iOSVersionGreaterThan8) {
        UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
        
        if (orientation ==  UIDeviceOrientationPortrait) {
            screenHeight = CGRectGetHeight([UIScreen mainScreen].bounds);
        }
        else if ((orientation == UIDeviceOrientationLandscapeRight) || (orientation == UIInterfaceOrientationLandscapeLeft)) {
            screenHeight = CGRectGetWidth([UIScreen mainScreen].bounds);
        }
    }
    
    return screenHeight;
}

NS_ASSUME_NONNULL_END


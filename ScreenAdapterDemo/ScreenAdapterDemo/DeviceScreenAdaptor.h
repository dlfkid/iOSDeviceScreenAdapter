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

typedef NS_ENUM(NSInteger, DeviceScreenType) {
    /// 未知屏幕尺寸
    DeviceScreenTypeUnknown,
    
    /// 4s, 4, 3GS, 3G, 1, iPod Touch 4
    DeviceScreenType3_5,
    
    /// SE, 5s, 5c, 5, iPod Touch 5~6
    DeviceScreenType4_0,
    
    /// 6s, 6
    DeviceScreenType4_7,
    
    /// 6s Plus, 6 Plus
    DeviceScreenType5_5,
    
    /// X
    DeviceScreenType5_8,
    
    /// XR
    DeviceScreenType6_1,
    
    /// Xs max
    DeviceScreenType6_5,
    /// iPad Mini 2~4
    /// 它的分辨率与 iPad 一致, 可以忽略.
    //  IBLVersionDeviceSize7_9,
    
    /// iPad Pro, iPad Air 2, iPad Air, iPad 4, iPad 3
    DeviceScreenType9_7,
    
    DeviceScreenType10_5,
    
    /// iPad Pro
    DeviceScreenType11,
    
    /// iPad Pro
    DeviceScreenType12_9
};

typedef NS_ENUM(NSInteger,DeviceType) {
    
    Unknown = 0,
    Simulator,
    IPhone_1G,          //基本不用
    IPhone_3G,          //基本不用
    IPhone_3GS,         //基本不用
    IPhone_4,           //基本不用
    IPhone_4s,          //基本不用
    IPhone_5,
    IPhone_5C,
    IPhone_5S,
    IPhone_SE,
    IPhone_6,
    IPhone_6P,
    IPhone_6s,
    IPhone_6s_P,
    IPhone_7,
    IPhone_7P,
    IPhone_8,
    IPhone_8P,
    IPhone_X,
    IPhone_Xs,
    IPhone_XsMax,
    IPhone_XR,
};


@interface DeviceScreenAdaptor : NSObject

@property (nonatomic, assign, readonly) DeviceType deviceType;
@property (nonatomic, assign, readonly) DeviceScreenType screenType;
@property (nonatomic, assign, readonly) BOOL isLandscape;

+ (DeviceScreenAdaptor *)sharedAdaptor;

+ (CGFloat)adaptedValue:(CGFloat)standardValue;

+ (BOOL)isLandscape;

+ (DeviceScreenType)screenType;

+ (DeviceType)deviceType;

@end

NS_ASSUME_NONNULL_END

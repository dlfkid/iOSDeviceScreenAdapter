//
//  ScreenAdapterDemoViewController.m
//  ScreenAdapterDemo
//
//  Created by LeonDeng on 2019/1/25.
//  Copyright © 2019 LeonDeng. All rights reserved.
//

#import "ScreenAdapterDemoViewController.h"

#import "DeviceScreenAdaptor.h"

@interface ScreenAdapterDemoViewController ()

@property (nonatomic, strong) UILabel *currentDeviceTypeLabel;
@property (nonatomic, strong) UILabel *currentScreenTypeLabel;
@property (nonatomic, strong) UILabel *currentScreenHeightLabel;
@property (nonatomic, strong) UIButton *scanCurrentScreenButton;

@end

static NSString * const kdeviceTypeLabel = @"Current device type: ";
static NSString * const kscreenTypeLabel = @"Current screen type: ";
static NSString * const kheightLabel = @"Current screen height: ";

static CGFloat const standardHeight = 40;
static CGFloat const standardWidth = 220;

@implementation ScreenAdapterDemoViewController

- (CGFloat)viewHeight {
    return self.view.frame.size.height;
}

- (CGFloat)viewWidth {
    return self.view.frame.size.width;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"ScreenAdapterDemoViewController";
    
    UILabel* (^generateInfoLabels)(void) = ^{
        UILabel *sampleLabel = [[UILabel alloc] initWithFrame:CGRectZero];
        sampleLabel.textAlignment = NSTextAlignmentCenter;
        sampleLabel.font = [UIFont boldSystemFontOfSize:[UIFont labelFontSize]];
        sampleLabel.numberOfLines = 0;
        sampleLabel.lineBreakMode = NSLineBreakByWordWrapping;
        return sampleLabel;
    };
    
    _currentScreenTypeLabel = generateInfoLabels();
    _currentScreenHeightLabel = generateInfoLabels();
    _currentDeviceTypeLabel = generateInfoLabels();
    
    _scanCurrentScreenButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [_scanCurrentScreenButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [_scanCurrentScreenButton setTitle:@"Scan screen" forState:UIControlStateNormal];
    [_scanCurrentScreenButton addTarget:self action:@selector(scanCurrentScreenButtonDidTapped) forControlEvents:UIControlEventTouchUpInside];
    _scanCurrentScreenButton.frame = CGRectMake(([self viewWidth] - standardWidth) / 2, 80, standardWidth, standardHeight);
    [self.view addSubview:self.scanCurrentScreenButton];
    
    _currentScreenTypeLabel.frame = CGRectMake(([self viewWidth] - standardWidth) / 2, 150, standardWidth, standardHeight);
    
    _currentDeviceTypeLabel.frame = CGRectMake(([self viewWidth] - standardWidth) / 2, 200, standardWidth, standardHeight);
    
    _currentScreenHeightLabel.frame = CGRectMake(([self viewWidth] - standardWidth) / 2, 250, standardWidth, standardHeight);
    
    [self.view addSubview:_currentDeviceTypeLabel];
    [self.view addSubview:_currentScreenTypeLabel];
    [self.view addSubview:_currentScreenHeightLabel];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSLog(@"Adapted value test: %f, status bar : %f, bottom margin : %f", DSAdaptedWidthValue(1000), DSStatusBarMargin, DSBottomMargin);
}

#pragma mark - Actions

- (void)scanCurrentScreenButtonDidTapped {
    self.currentDeviceTypeLabel.text = [NSString stringWithFormat:@"%@%ld", kdeviceTypeLabel, [DeviceScreenAdaptor deviceType]];
    self.currentScreenTypeLabel.text = [NSString stringWithFormat:@"%@%ld", kscreenTypeLabel, [DeviceScreenAdaptor screenType]];
}

@end

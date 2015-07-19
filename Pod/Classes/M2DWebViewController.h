//
//  M2DWebViewController.h
//  BoostMedia
//
//  Created by Akira Matsuda on 2013/01/11.
//  Copyright (c) 2013年 akira.matsuda. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_0
#import <WebKit/WebKit.h>
#endif

@class M2DWebViewController;

typedef NS_ENUM(NSUInteger, M2DWebViewType) {
	M2DWebViewTypeUIKit,
	M2DWebViewTypeWebKit,
	M2DWebViewTypeAutoSelect
};

@interface M2DWebViewController : UIViewController <WKUIDelegate, WKNavigationDelegate, UIWebViewDelegate>

@property (nonatomic, assign) BOOL toolbarHidden;
@property (nonatomic, assign) BOOL smoothScroll;
@property (nonatomic, readonly) id webView;
@property (nonatomic, copy) void (^actionButtonPressedHandler)(NSString *pageTitle, NSURL *url);

- (instancetype)initWithURL:(NSURL *)url type:(M2DWebViewType)type;
- (instancetype)initWithURL:(NSURL *)url type:(M2DWebViewType)type backArrowImage:(UIImage *)backArrowImage forwardArrowImage:(UIImage *)forwardArrowImage;
- (void)goForward:(id)sender;
- (void)goBack:(id)sender;
- (void)refresh:(id)sender;
- (void)stop:(id)sender;
- (void)doAction:(id)sender;
- (void)loadURL:(NSURL *)url;
- (void)setSmoothScroll:(BOOL)smoothScroll;

@end

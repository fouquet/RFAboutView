//
//  RFAboutViewDetailViewController.h
//  RFAboutView
//
//  Created by René Fouquet on 10/05/15.
//  Copyright (c) 2015 René Fouquet. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface RFAboutViewDetailViewController : UIViewController

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, assign) BOOL showVerticalScrollingIndicator;

- (id)initWithDictionary:(NSDictionary *)theDict;

@end

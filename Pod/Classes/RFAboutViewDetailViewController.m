//
//  RFAboutViewDetailViewController.m
//  RFAboutView
//
//  Created by René Fouquet on 10/05/15.
//  Copyright (c) 2015 René Fouquet. All rights reserved.
//

#import "RFAboutViewDetailViewController.h"

@interface RFAboutViewDetailViewController ()
@property (nonatomic, strong) NSDictionary *infoDict;
@end

@implementation RFAboutViewDetailViewController

- (id)initWithDictionary:(NSDictionary *)theDict {

    self = [super init];
    if (self) {
        _infoDict = theDict;
    }
    return self;
}

- (void)loadView {
    [super loadView];
    
    self.view.backgroundColor = self.backgroundColor;
    self.view.tintColor = self.tintColor;
    
    self.navigationController.navigationBar.tintColor = self.view.tintColor;
    
    self.navigationItem.title = self.infoDict[@"title"];
    self.navigationController.toolbarHidden = YES;
    
    UITextView *contentTextView = [UITextView new];
    contentTextView.frame = self.view.bounds;
    contentTextView.autoresizingMask = (UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth);
    contentTextView.textContainerInset = UIEdgeInsetsMake([self sizeForPercent:3.125], [self sizeForPercent:3.125], [self sizeForPercent:3.125], [self sizeForPercent:3.125]);
    contentTextView.userInteractionEnabled = YES;
    contentTextView.selectable = YES;
    contentTextView.editable = NO;
    contentTextView.scrollEnabled = YES;
    contentTextView.showsHorizontalScrollIndicator = NO;
    contentTextView.showsVerticalScrollIndicator = self.showVerticalScrollingIndicator;
    contentTextView.backgroundColor = [UIColor clearColor];
    contentTextView.spellCheckingType = UITextSpellCheckingTypeNo;
    
    NSMutableDictionary *attrs = [@{NSFontAttributeName : [UIFont fontWithName:@"HelveticaNeue-Light" size:[self sizeForPercent:4.063]]} mutableCopy];
    
    NSMutableParagraphStyle *paragraphStyle = [NSMutableParagraphStyle new];
    paragraphStyle.hyphenationFactor = 1;
    paragraphStyle.alignment = NSTextAlignmentJustified;
    attrs[NSParagraphStyleAttributeName] = paragraphStyle;
    
    contentTextView.attributedText = [[NSAttributedString alloc] initWithString:self.infoDict[@"content"] attributes:attrs];

    [self.view addSubview:contentTextView];
}

/*!
 *  Gives a float value based on the given percentage of the screen width. For iPad, this had to change a bit because it looks wrong.
 */
- (CGFloat)sizeForPercent:(CGFloat)percent {
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        return (CGFloat)ceil((self.view.frame.size.width * 0.7) * (percent / 100));
    } else {
        return (CGFloat)ceil(self.view.frame.size.width * (percent / 100));
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

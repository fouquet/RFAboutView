//
//  RFViewController.m
//  RFAboutView
//
//  Created by René Fouquet on 05/20/2015.
//  Copyright (c) 2014 René Fouquet. All rights reserved.
//

#import "RFViewController.h"
#import "RFAboutViewController.h"

@interface RFViewController ()

@property (nonatomic, strong) M2DWebViewController *webViewController;

@end

@implementation RFViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)showAbout:(id)sender {
    // First create a UINavigationController (or use your existing one).
    // The RFAboutView needs to be wrapped in a UINavigationController.
    
    UINavigationController *aboutNavigation = [UINavigationController new];

    // Initialise the RFAboutView:
    
    RFAboutViewController *aboutView = [[RFAboutViewController alloc] initWithAppName:nil appVersion:nil appBuild:nil copyrightHolderName:@"ExampleApp, Inc." contactEmail:@"mail@example.com" titleForEmail:@"Contact us" websiteURL:[NSURL URLWithString:@"http://example.com"] titleForWebsiteURL:@"Our Website" andPublicationYear:nil];
    
    // Set some additional options:
    aboutView.headerBackgroundColor = [UIColor blackColor];
    aboutView.headerTextColor = [UIColor whiteColor];
    aboutView.blurStyle = UIBlurEffectStyleDark;
    aboutView.headerBackgroundImage = [UIImage imageNamed:@"about_header_bg.jpg"];
	aboutView.showAcknowledgements = NO;
	[aboutView setDelegate:self];
	
    // Add an additional button:
    [aboutView addAdditionalButtonWithTitle:@"Privacy Policy" subtitle:@"subtitle" andContent:@"Here's the privacy policy"];
	[aboutView addAdditionalButtonWithTitle:@"Test" subtitle:@"subtitle" andURL:[NSURL URLWithString:@"http://www.google.com"]];

    // Add the aboutView to the NavigationController:
    [aboutNavigation setViewControllers:@[aboutView]];
    
    // Present the navigation controller:
    [self presentViewController:aboutNavigation animated:YES completion:nil];
}

-(void)willOpenUrl:(NSURL *)website{
	if(!_webViewController){
		_webViewController = [[M2DWebViewController alloc] initWithURL:website type:M2DWebViewTypeAutoSelect];
	}
	[_webViewController loadURL:website];
	[self presentViewController:_webViewController animated:YES completion:nil];
}


@end

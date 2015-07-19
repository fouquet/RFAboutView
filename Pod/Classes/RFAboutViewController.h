//
//  RFAboutViewController.h
//  RFAboutView
//
//  Created by René Fouquet on 10/05/15.
//  Copyright (c) 2015 René Fouquet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
@class M2DWebViewController;

@interface RFAboutViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, MFMailComposeViewControllerDelegate>

/*!
 *  Tint color of the RFAboutViewController. Defaults to black color.
 */
@property (nonatomic, strong) UIColor *tintColor;

/*!
 *  Background color of the RFAboutViewController. Defaults to a light gray color.
 */
@property (nonatomic, strong) UIColor *backgroundColor;

/*!
 *  Background color of the header. Defaults to white color.
 */
@property (nonatomic, strong) UIColor *headerBackgroundColor;

/*!
 *  Color of the text in the header. Defaults to black color.
 */
@property (nonatomic, strong) UIColor *headerTextColor;

/*!
 *  Border color of the header. Defaults to light gray color.
 */
@property (nonatomic, strong) UIColor *headerBorderColor;

/*!
 *  Acknowledgements header text color. Defaults to black color.
 */
@property (nonatomic, strong) UIColor *acknowledgementsHeaderColor;

/**
 *  Background Color of the Navigation Bar.
 */
@property (nonatomic, strong) UIColor *navigationViewBackgroundColor;

/**
 *  Bar Tint Color of the Navigation Bar.
 */
@property (nonatomic, strong) UIColor *navigationBarBarTintColor;

/**
 *  Tint color of the Navigation Bar. Defaults to the view's default tint color.
 */
@property (nonatomic, strong) UIColor *navigationBarTintColor;

/**
 *  Color of the Navigation Bar Title. Defaults to blackColor.
 */
@property (nonatomic, strong) UIColor *navigationBarTitleTextColor;

/*!
 *  TableView background color. Defaults to white color.
 */
@property (nonatomic, strong) UIColor *tableViewBackgroundColor;

/**
 *  Color of the a selected tableview cell.
 */
@property (nonatomic, strong) UIColor *tableViewCellSelectColor;

/*!
 *  TableView text color. Defaults to black color.
 */
@property (nonatomic, strong) UIColor *tableViewTextColor;

/*!
 *  The background of the about header. Defaults to nil.
 */
@property (nonatomic, strong) UIImage *headerBackgroundImage;

/*!
 *  The image for the button to dismiss the RFAboutViewController. Defaults to image of "X".
 */
@property (nonatomic, weak) UIImage *closeButtonImage;

/*!
 *  Determines if the header background image should be blurred. Defaults to YES.
 */
@property (nonatomic, assign) BOOL blurHeaderBackground;

/*!
 *  Effect style of the header blur. Defaults to UIBlurEffectStyleLight.
 */
@property (nonatomic, assign) UIBlurEffectStyle blurStyle;

/*!
 *  Determines if diagnostic information (app title, version, build, device etc.) should be included in the email when the user taps the email link. This information can be very useful to debug certain problems and can be deleted by the user if they don't want to send this information. Defaults to YES.
 */
@property (nonatomic, assign) BOOL includeDiagnosticInformationInEmail;

/*!
 *  Determines if the acknowledgements tableview should be shown. Defaults to YES.
 */
@property (nonatomic, assign) BOOL showAcknowledgements;

/*!
 *  Determines if the main scrollview should show a scroll indicator. Defaults to YES.
 */
@property (nonatomic, assign) BOOL showsScrollIndicator;

/*!
 *  File name of the acknowledgements plist *without* extension. Defaults to "Acknowledgements".
 */
@property (nonatomic, weak) NSString *acknowledgementsFilename;

/*!
 *  The name of the app. Leave nil to use the CFBundleName.
 */
@property (nonatomic, strong) NSString *appName;

/*!
 *  The current version of the app. Leave nil to use CFBundleShortVersionString.
 */
@property (nonatomic, strong) NSString *appVersion;

/*!
 *  The current build of the app. Leave nil to use CFBundleVersion.
 */
@property (nonatomic, strong) NSString *appBuild;

/*!
 *  The name of the person or entity who should appear as the copyright holder.
 */
@property (nonatomic, strong) NSString *copyrightHolderName;

/*!
 *  The email address users can send inquiries to (for example a support email address). Leave nil to skip.
 */
@property (nonatomic, strong) NSString *contactEmail;

/*!
 *  The text to use for the email link. Leave nil to use the email address as text.
 */
@property (nonatomic, strong) NSString *contactEmailTitle;

/*!
 *  The URL for the website link. Leave nil to skip.
 */
@property (nonatomic, strong) NSURL *websiteURL;

/*!
 *  The title for the website link. Leave nil to use the website URL.
 */
@property (nonatomic, strong) NSString *websiteURLTitle;

/*!
 *  The year the app's version was published. Used in the copyright text. Leave nil to use the current year.
 */
@property (nonatomic, strong) NSString *pubYear;

/**
 *  If YES i'll use te built in browser, or Safari app. Default to YES.
 */
@property (nonatomic, assign) BOOL webBuiltIn;

/**
 *  The built in browser view controller.
 */
@property (nonatomic, strong) M2DWebViewController *webViewController;

/*!
 *  Initializes the RFAboutViewController with the given parameters.
 *
 *  @param appName              The name of the app. Leave nil to use the CFBundleName.
 *  @param appVersion           The current version of the app. Leave nil to use CFBundleShortVersionString.
 *  @param appBuild             The current build of the app. Leave nil to use CFBundleVersion.
 *  @param copyrightHolderName  The name of the person or entity who should appear as the copyright holder.
 *  @param contactEmail         The email address users can send inquiries to (for example a support email address). Leave nil to skip.
 *  @param contactEmailTitle    The text to use for the email link. Leave nil to use the email address as text.
 *  @param websiteURL           The URL for the website link. Leave nil to skip.
 *  @param websiteURLTitle      The title for the website link. Leave nil to use the website URL.
 *  @param pubYear              The year the app's version was published. Used in the copyright text. Leave nil to use the current year.
 *
 *  @return RFAboutViewController instance.
 */
- (id)initWithAppName:(NSString *)appName
           appVersion:(NSString *)appVersion
             appBuild:(NSString *)appBuild
  copyrightHolderName:(NSString *)copyrightHolderName
         contactEmail:(NSString *)contactEmail
        titleForEmail:(NSString *)contactEmailTitle
           websiteURL:(NSURL *)websiteURL
   titleForWebsiteURL:(NSString *)websiteURLTitle
   andPublicationYear:(NSString *)pubYear;

/*!
 *  Adds an additional button (as a TableView cell) below the header. Use it to supply further information, like TOS, Privacy Policy etc.
 *
 *  @param title   The title of the button
 *  @param content The text to display in the detail view
 */
- (void)addAdditionalButtonWithTitle:(NSString *)title andContent:(NSString *)content;
/**
 *  Adds an additional button (as a TableView cell) below the header. If clicked it will open the browser
 *	@see webBuiltIn
 *  @param title   The title of the button
 *  @param content Thw website to display in webview
 */
- (void)addAdditionalButtonWithTitle:(NSString *)title andURL:(NSURL *)content;

@end

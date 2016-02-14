//
//  OnboardingViewController.h
//  Onboard
//
//  Created by Mike on 8/17/14.
//  Copyright (c) 2014 Mike Amaral. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OnboardingContentViewController.h"
@import MediaPlayer;

@interface OnboardingViewController : UIViewController <UIPageViewControllerDataSource, UIPageViewControllerDelegate, UIScrollViewDelegate>

// View controllers and background image
@property (nonatomic, strong) NSArray *viewControllers;
@property (nonatomic, strong) UIImage *backgroundImage;

// Masking, blurring, fading, etc.
@property (nonatomic) BOOL shouldMaskBackground;
@property (nonatomic) BOOL shouldBlurBackground;
@property (nonatomic) BOOL shouldFadeTransitions;
@property (nonatomic) BOOL fadePageControlOnLastPage;
@property (nonatomic) BOOL fadeSkipButtonOnLastPage;

// Skipping
@property (nonatomic) BOOL allowSkipping;
@property (nonatomic, strong) dispatch_block_t skipHandler;

// Swiping
@property (nonatomic) BOOL swipingEnabled;

// Page Control
@property (nonatomic) BOOL hidePageControl;
@property (nonatomic, strong) UIPageControl *pageControl;

// Skip Button
@property (nonatomic, strong) UIButton *skipButton;

// Movie player
@property (nonatomic) BOOL stopMoviePlayerWhenDisappear;
@property (nonatomic) MPMoviePlayerController *moviePlayerController;

// Initializers
+ (instancetype)onboardWithBackgroundImage:(UIImage *)backgroundImage contents:(NSArray *)contents;
- (instancetype)initWithBackgroundImage:(UIImage *)backgroundImage contents:(NSArray *)contents;

+ (instancetype)onboardWithBackgroundVideoURL:(NSURL *)backgroundVideoURL contents:(NSArray *)contents;
- (instancetype)initWithBackgroundVideoURL:(NSURL *)backgroundVideoURL contents:(NSArray *)contents;

// Manually moving to next page
- (void)moveNextPage;

////////////////////////////////////////////////////////////////////
// These are convenience properties for content view customization, so you
// can set these properties on the master onboarding view controller and
// it will make sure they trickle down to each content view controller,
// rather than having to individually set the same values on each

@property (nonatomic) CGFloat iconSize; // set this if you want the icon to have the same width and height for all contents
@property (nonatomic) CGFloat iconHeight;
@property (nonatomic) CGFloat iconWidth;

@property (nonatomic, strong) UIColor *titleTextColor;
@property (nonatomic, strong) UIColor *bodyTextColor;
@property (nonatomic, strong) UIColor *buttonTextColor;

@property (nonatomic, strong) UIFont *font;     // to set the same font for everything

@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIFont *bodyFont;
@property (nonatomic, strong) UIFont *buttonFont;

@property (nonatomic) CGFloat topPadding;
@property (nonatomic) CGFloat underIconPadding;
@property (nonatomic) CGFloat underTitlePadding;
@property (nonatomic) CGFloat bottomPadding;
@property (nonatomic) CGFloat underPageControlPadding;

////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
// Delegate methods for internal use.
- (void)setCurrentPage:(OnboardingContentViewController *)currentPage;
- (void)setNextPage:(OnboardingContentViewController *)nextPage;
////////////////////////////////////////////////////////////////////


// Deprecated font properties
@property (nonatomic, strong) NSString *fontName       __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic, strong) NSString *buttonFontName      __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic) CGFloat buttonFontSize                __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic, strong) NSString *bodyFontName   __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic) CGFloat bodyFontSize             __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic, strong) NSString *titleFontName  __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");
@property (nonatomic) CGFloat titleFontSize            __deprecated_msg("setting fonts by name and size has been deprecated. Use UIFont properties instead");

@end

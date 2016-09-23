//
//  VMNMediaControls.h
//  VMNPlayerSample
//
//  Created by Keith Peters on 8/23/12.
//  Copyright (c) 2012 Keith Peters. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BCEventEmitter.h"
#import "VMNSlider.h"
#import "WEPopoverController.h"
@protocol BCEventEmitterProtocol;

#define CONTROLS_MODE_NORMAL 0
#define CONTROLS_MODE_AD_ONLY 1
#define CONTROLS_MODE_AD_PLUS 2
#define INDENT_X_OF_PLAYPAUSE_BUTTON 57
/// A full set of media controls for the VMNPlayer.
/// 
@interface VMNMediaControls : UIViewController <VMNSliderDelegate, WEPopoverControllerDelegate>
{
    UIView *tapView;
    UIView *topBar;
    UIView *bottomBar;
    UIView *adBar;
    UIButton *backButton;
    UIButton *playPauseButton;
    UIButton *ccButton;
    UIButton *airplayButton;
    UIButton *fullScreenButton;
    UIButton *doneButton;
    UIButton *shareButton;
	UILabel *statusLabel;
	UILabel *timeLabel;
	UILabel *resumeLabel;
    UIView *timeLabelsContainer;
	BOOL sliding;
    BOOL isPlaying;
    float time;
    float duration;
    BOOL isFullScreen;
    int adMode;
    VMNSlider *slider;
    BOOL isSocialMediaEnabled;
    BOOL isTwitterEnabled;
    BOOL isFacebookEnabled;
    BOOL isEmailEnabled;
    float seekTolerance;
    BOOL faded;
    NSTimer *timer;
    BOOL isSeeking;
}

@property (nonatomic, assign) BOOL live;
@property (nonatomic, assign) BOOL dvr;
/// The BCEventEmitter for these controls. Contains a top, bottom, and ad bar and an overlay for capturing touch events.
@property (nonatomic, retain) id<BCEventEmitterProtocol> emitter;
/// A view that can intercept and capture tap events
@property (nonatomic, retain) IBOutlet UIView *tapView;
/// A visual bar that appears at the top of the player's frame and holds sub-controls
@property (nonatomic, retain) IBOutlet UIView *topBar;
/// A visual bar that appears at the bottom of the player's frame and holds sub-controls
@property (nonatomic, retain) IBOutlet UIView *bottomBar;
/// An additional bar that contains information about the current ad playing
@property (nonatomic, retain) IBOutlet UIView *adBar;
/// A button that sends the current video back 30 seconds
@property (nonatomic, retain) IBOutlet UIButton *backButton;
/// A button that toggles between play and pause states.
@property (nonatomic, retain) IBOutlet UIButton *playPauseButton;
/// A button used to toggle closed captions, and can indicate if closed captions are available.
@property (nonatomic, retain) IBOutlet UIButton *ccButton;
/// A button used to activate the airplay device choosing UI.
@property (nonatomic, retain) IBOutlet UIButton *airplayButton;
/// A button used to enter full screen display.
@property (nonatomic, retain) IBOutlet UIButton *fullScreenButton;
/// A button shown during full screen that will cause the player to exit back to normal mode.
@property (nonatomic, retain) IBOutlet UIButton *doneButton;
/// A button used to display the sharing controls.
@property (nonatomic, retain) IBOutlet UIButton *shareButton;
/// A label used to display current status of the player/video
@property (nonatomic, retain) IBOutlet UILabel *statusLabel;
/// A label showing the current time position of the playing video.
@property (nonatomic, retain) IBOutlet UILabel *timeLabel;
/// A label showing the duration of the current video or the total duration of the playlist if it is a segmented playlist.
@property (nonatomic, weak) IBOutlet UILabel *durationLabel;
/// A label that displays a count down to video resuming while an ad is playing. i.e. "Your video will resume in xx seconds"
@property (nonatomic, retain) IBOutlet UILabel *resumeLabel;
/// A button that switches between live and dvr modes (if available).
@property (nonatomic, retain) IBOutlet UIButton *liveButton;
/// A reference to Learn more button
@property (weak, nonatomic) IBOutlet UIButton *learnMoreButton;
/// A reference to the VMNSlider.
@property (nonatomic, retain) VMNSlider *slider;
/// A view containing the time and duration labels.
@property (nonatomic, retain) IBOutlet UIView *timeLabelsContainer;
/// Sets the tolerance used in all seeking by the controls. In seconds.
@property (atomic, readwrite) float seekTolerance;
/// Indicates whether or not seeking is occuring. Is true from the time the user touches the slider, until it is released and the actual seek is complete.
@property (nonatomic, readwrite) BOOL isSeeking;

// private...
@property (nonatomic, retain) NSTimer *timer;
@property (atomic, assign) int rotationState;
@property (nonatomic) float currentSeekPosition;

+ (NSBundle *)frameworkBundle;

/// Designated initializer.
/// @param theEmitter BCEventEmitter for these controls to use.
- (id)initWithEmitter:(id<BCEventEmitterProtocol>)theEmitter;

/// Formats a time value in seconds to a properly formulated time string, i.e. "hh:mm:ss"
/// @param time The time in seconds to format.
- (NSString *)formatTime:(float)time;

/// Sets the way the controls are displayed based on ad playing and user interection. Possible values are:
/// CONTROLS_MODE_NORMAL or 0 : When playing normal content. Top bar, bottom bar, slider is interactive.
/// CONTROLS_MODE_AD_ONLY or 1 : When playing an ad. Top bar, ad bar.
/// CONTROLS_MODE_AD_PLUS or 2 : When playing an ad. Top bar, ad bar, bottom bar, slider not interactive.
/// @param mode The mode to put the controls into.
- (void)setAdMode:(int)mode;

/// Returns the current ad mode.
- (int)adMode;

/// Sets the live button to be active and able to switch between live and dvr modes.
- (void)enableLiveButton;

/// Sets the live button to disabled and not interactive.
- (void)disableLiveButton;

/// Updates the visibility, state, and 
- (void)updateUI;


// private...
- (void)setupMediaControlsEventListeners;
- (void)handlePlayPauseAds;
- (void)handlePlayPauseMedia;
- (void)stopFadeOutTimer;

- (IBAction)handleBackButton:(id)sender;
- (IBAction)handlePlayPauseButton:(id)sender;
- (IBAction)handleCCButton:(id)sender;
- (IBAction)handleAirplayButton:(id)sender;
- (IBAction)handleFullScreenButton:(id)sender;
- (IBAction)handleDoneButton:(id)sender;
- (IBAction)handleShareButton:(id)sender;
- (IBAction)handleLearnMore:(id)sender;
- (IBAction)handleLiveButton:(id)sender;


@end

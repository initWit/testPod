//
//  VMNPlayer.h
//  VMNVideoPlayer
//
//

#define VMNPLAYER_ROTATED_ZERO 0
#define VMNPLAYER_ROTATED_NINETY 90
#define VMNPLAYER_ROTATED_ONE_HUNDERD_EIGHTY 180
#define VMNPLAYER_ROTATED_TWO_HUNDRED_SEVENTY 270

#import <Foundation/Foundation.h>
#import "BCQueuePlayer.h"
#import "BCVideo.h"
#import "PlayerConfig.h"
#import "VMNServiceAPI.h"
#import "VMNVideoPlayerUtils.h"
#import "VMNMediaControls.h"
#import "VMNCaptionsLayer.h"
#import "VMNUIService.h"
#import <MessageUI/MessageUI.h>
#import "MediaGenVideoRendition.h"
#import "BCCatalog.h"
#import "PlayerSession.h"
#import "AuthenticationInfo.h"
#import "VMNPlayerConstants.h"
#import "MediaGenOverlayManager.h"

/**
 * The VMN Player manages a queue of videos to play sequentially.  
 *
 * ### Events supported by VMN Player
 *
 *  - VMNEventConfigSet - to know when the PMT config is ready. The config is applied until content is loaded.
 *  - VMNEventApplyConfig - to know when the current PMT config is applied to the player.
 *  - VMNEventPMTRequestError - to know when there was an error connecting with the PMT
 *  - VMNEventPlaylistModeSet - to know when a playlist has been loaded into the player and what type it is (editorial playlist or full episode)
 *  - VMNEventSocialSharingEnabled - to know if Social Sharing is enabled.
 *  - VMNEventTwitterSharingEnabled - to know if Twitter sharing is enabled.
 *  - VMNEventFacebookSharingEnabled - to know if Facebook sharing is enabled.
 *  - VMNEventEmailSharingEnabled - to know if Email sharing is enabled.
 *  - VMNEventSocialSharingDisabled - to know if Social sharing is disabled.
 *  - VMNEventPlaylistDidEnd - to know when the last video on a playlist ends.
 *  - VMNEventWillShareWithEmail - to know when the Email button has been tapped. 
 *  - VMNEventWillShareWithFacebook - to know when the Facebook button has been tapped.
 *  - VMNEventWillShareWithTwitter - to know when the Twitter button has been tapped.
 *  - VMNEventFullEpisodeProgress - to know the current position on a full episode
 *  - VMNEventDidDetectLiveStream - to know when a live stream is loaded.
 *  - VMNEventDidDetectDVRStream - to know when a live stream with DVR is loaded.
 *  - VMNEventWillEnableAds - to know when the player is about to request ads
 *  - VMNEventWillEnableReporting -  to know when the player will enable reporting.
 *  - VMNEventPMTProtocolError - to know when PMT includes information about an error
 *  - VMNEventPMTParseError - to know when the PMT response cannot be parsed.
 *  - VMNEventMediaGenError - to know when there is a mediaGen error
 *  - VMNEventLiveOrDVRStreamError - to know when loading a live stream fails
 *  - VMNEventVideoURINotFoundError - to know when the video cannot be found in BC Video Cloud
 *  - VMNEventPlaylistURINotFoundError - to know when a playlist cannot be found in BC Video Cloud
 *  - VMNEventCurrentItemsFailure - to know when there are no current items in the player or player cannot play the current items
 *  - VMNEventNextPlayerItemStatusFailed - to know when the next item in the queue cannot be played because its AVPlayerItem has an AVPlayerStatusFailed status.
 *  - VMNEventLiveStreamExpiredError - to know when the live stream expires
 *  - VMNEventOverlayAdDidStart - to know when an overlay ad starts playing.
 *  - VMNEventAdDidStart - to know when a video ad starts
 *  - VMNEventAdStop - to stop the current ad.
 *  - VMNEventOverlayAdDidEnd - to know when a overlay ad ends.
 *  - VMNEventAdProgress - to know the current playback position of an ad.
 *  - VMNEventConfigAutoPlayIsEnabled - to know when the player has been enabled for auto-play
 *  - VMNEventFullEpisodeSeekTo - to seek into a new playback position
 *  - VMNEventUnloadContent - to reset the content of the player
 *  - VMNEventAdDidEnd - to know when a video ad ends
 *  - VMNEventFullScreen - to set the player in full screen mode
 *  - VMNEventToggleCC - to toggle captions
 *  - VMNEventControlsFadeIn - to know when the controls fade in
 *  - VMNEventControlsFadeOut - to know when the controls fade out
 *  - VMNEventShowControls - to show the media controls in a chromed player
 *  - VMNEventHideControls - to hide the media controls in a chromed player
 *  - VMNEventAirPlayControlVisibility - to inform listeners whether airplay button should be visible or not
 *  - VMNEventWillSeekToNewSegment - to know when a full episode segment is about to be seeked into
 *  - VMNEventDidSeekToNewSegment - to know when a new segment of a full episode has been seeked into
 *  - VMNEventAdInstanceHasClickThrough - to know whether the current AdInstance has Click through url
 *  - VMNEventAdPlaybackDidStall - to know when an ad playback stalls (e.g. due to the low network bandwidth)
 */
@interface VMNPlayer : BCQueuePlayer <MFMailComposeViewControllerDelegate>
{
    BOOL adsEnabled;
    BOOL clickthroughEnabled;
    BOOL eventListenersSet;
    BOOL isFullEpisode;
    BOOL needsConfigApplied;
    BOOL playlistIsProcessing;
    BOOL reportingEnabled;
    BOOL spinnerEnabled;
    BOOL adIsPlaying;
    
    NSInteger advanceIndex;
    int currentPlaylistIndex;
    int startupBitRate;
    NSInteger videoCount;
    
    float currentSegmentStartTime;
    float playbackRate;
    float seekTolerance;
    
    long long fullEpisodeDuration;
    
    __unsafe_unretained NSString *currentRefId;
    __unsafe_unretained NSString *currentPlaylistRefId;
    __unsafe_unretained NSString *currentVideoLink;
    NSString *mgidTransformReplacement;
    NSString *mgidTransformSource;
    NSString *videoURIFromPlaylist;
    
    NSMutableArray *segmentData;
    NSMutableArray *videoList;
    
    UIView *adView;
//    UIView *overlayView;
    BCCatalog *catalog;
    
    
    
    VMNMediaControls *controls;
    VMNServiceAPI *vmnAPIServices;
    VMNUIService *uiService;
    VMNVideoPlayerUtils *utils;
    
    void (^fullScreenPreprocessor)(BOOL fullScreen);
}



@property (nonatomic, copy) void (^fullScreenPreprocessor)(BOOL fullScreen);
/// To enable or disable ads. Ads are enabled by default
@property (nonatomic) BOOL adsEnabled;
/// To enable or disable reporting. Reporting is enabled by default.
@property (nonatomic) BOOL reportingEnabled;
/// To know if the loading spinner is enabled.
@property (nonatomic) BOOL spinnerEnabled;
/// To know if an ad is playing.
@property (nonatomic) BOOL adIsPlaying;

@property (atomic, assign) VMNPlayerStatus playerStatusENUM;
/// To know if a live stream is playing
@property (atomic, assign) BOOL liveStreamPlaying;
/// To know if a live stream with DVR is playing
@property (atomic, assign) BOOL dvrIsAvailable;
/// To enable or disable the built in email sharing option.
@property (atomic, assign) BOOL isBuiltinEmailSharingEnabled;
/// To enable or disable the built in Facebook sharing option.
@property (atomic, assign) BOOL isBuiltinFacebookSharingEnabled;
/// To enable or disable the built in Twitter sharing option.
@property (atomic, assign) BOOL isBuiltinTwitterSharingEnabled;
@property (atomic, assign) BOOL isPausedForSharing;
/**
* Used to override the default, PMT-controlled autoplay behavior (auto play if form factor ID 1:1).
* Setting this value to NO will also prevent the VMNEventConfigAutoPlayIsEnabled for being emitted.
*/
@property (atomic, assign) BOOL allowConfigAutoplay;
@property (atomic, assign) int rotationState;

/// To disable video stills. Video stills are displayed by default.
@property (nonatomic, getter=isVideoStillsDisplayEnabled) BOOL videoStillsDisplayEnabled;

/// To disable error slates from being displayed.
@property (nonatomic, getter=isErrorSlateDisplayEnabled) BOOL errorSlateDisplayEnabled;

/// To disable AirPlay on the internal AVPlayer. Does not affect visibility of AirPlay button on controls. 
@property (nonatomic, assign) BOOL allowsExternalPlayback;

@property (nonatomic) int currentPlaylistIndex;
/// To know the current playback bitrate
@property (nonatomic) int startupBitRate;
/// To know the current segment start time in a full episode.
@property (nonatomic) float currentSegmentStartTime;
/// To update the AVPlayer seekTolerance. Default is zero.
@property (atomic, readwrite) float seekTolerance;
/// To know the full episode duration in seconds
@property (nonatomic) long long fullEpisodeDuration;
/// To know the current player size (CGRect)
@property (atomic, assign) CGRect currentPlayerSize;

@property (nonatomic, strong) NSString *adMode;
@property (nonatomic, strong) NSString *videoURIFromPlaylist;

/// To read an array of the current video segments in a full episode
@property (nonatomic, strong) NSMutableArray *segmentData;
@property (nonatomic, strong) NSMutableArray *videoList;

// Provider Name
@property (nonatomic, strong) NSString *providerName;

// Authentication Token
@property (nonatomic, strong) NSString *authToken;


/// To get access to the ad view used by the the FreeWheel ad player.
@property (nonatomic, strong) UIView *adView;
@property (nonatomic, strong) UIActivityIndicatorView *spinner;

@property (nonatomic, strong) BCCatalog *catalog;

/// The Player config object currently loaded into the player.
@property (nonatomic, weak) PlayerConfig *playerConfig;

/// The current media item
@property (nonatomic, readonly, assign) BOOL MRSSEnabled;
@property (nonatomic, weak) VMNContentItem *currentMediaItem;

/// Should error slates be displayed when failing to queue a video? Off by default. 
@property (nonatomic, assign) BOOL showQueueVideoErrorSlates;

@property (nonatomic, strong) MediaGenOverlayManager* mediaGenOverlayManager;

// Private
@property (atomic, strong) VMNCaptionsLayer *captions;
@property (nonatomic, strong) VMNMediaControls *controls;
@property (nonatomic, strong) VMNServiceAPI *vmnAPIServices;
@property (nonatomic, strong) VMNVideoPlayerUtils *utils;
/// The BCEventEmmiter for the VMN Player
@property (nonatomic, strong) id<BCEventEmitterProtocol> emitter;

/// View used to overlay a black overlay over the player before an ad plays or during error slates.
@property (nonatomic, strong) UIView *overlayView;
/// Label for error slates.
@property (nonatomic, strong) UILabel *overlayLabel;
/// Current layer that contains the current AVPlayer
@property (nonatomic, weak) AVPlayerLayer *currentAVPlayerLayer;
/// Current snapshot/session that is being restored
@property (nonatomic, strong) PlayerSession *currentRestoringPlayerSnapshot;

- (NSDictionary *) getVideoSegmentsPlayedAds;


/// Makes a request to the PMT and configures the player with the response.
/// @param mediaURIValue The mgid for the content.
/// @param appNameValue The app name that matches a PMT context. 
- (void)configure:(NSString *)mediaURIValue appName:(NSString *)appNameValue;

/// Loads a single video into the player. You need to configure the player before calling this API. 
/// @param videoURIValue The mgid for the content to load.
/// @param tokenValue The Brightcove Media API read token.
- (void)loadVideo:(NSString *)videoURIValue mediaAPIToken:(NSString *)tokenValue;

/// Loads a single video into the player. You need to configure the player before calling this API.
/// @param videoURIValue The mgid for the content to load.
/// @param tokenValue The Brightcove Media API read token.
/// @param authTokenId The authentication token id
/// @param providerName The provider name
- (void)loadVideo:(NSString *)videoURIValue
    mediaAPIToken:(NSString *)tokenValue
        authToken:(NSString *)authTokenValue
         providerName:(NSString *)providerName;

/// Loads a playlist or full episode into the player. You need to configure the player before calling this API.
/// @param playlistURIValue The mgid for the content to load.
/// @param videoURIValue This is an optional parameter to indicate that if the playlist should start playing from this video uri.
/// @param tokenValue The Brightcove Media API read token.
- (void)loadPlaylist:(NSString *)playlistURIValue videoURIValue:(NSString *)videoURIValue mediaAPIToken:(NSString *)tokenValue;

/// Destroys the player. Call this when closing the player view.
- (void)destroy;


/// Set the frame size for the player and internal components. This should be used instead of player.view.frame to ensure that
/// internal views such as captions are sized correctly. 
/// @param frame CGRect with the frame size
- (void)setFrame:(CGRect)frame;


/// Configures and loads a video into the player.
/// @param mediaURIValue The mgid for the content.
/// @param appNameValue The app name that matches a PMT context. 
/// @param mediaTokenValue The Brightcove Media API read token.
- (void)initWithVideoWithURI:(NSString *)mediaURIValue WithAppName:(NSString *)appNameValue
              WithMediaToken:(NSString *)mediaTokenValue;

/// Configures and loads a video into the player.
/// @param mediaURIValue The mgid for the content.
/// @param appNameValue The app name that matches a PMT context.
/// @param mediaTokenValue The Brightcove Media API read token.
/// @param authTokenId Required for user access validation to stream. Only supported as Cookie.
/// @param providerName Required for Freewheel, value is MVPD provider encoded as md5 hash on the player side.	
- (void)initWithVideoWithURI:(NSString *) mediaURIValue
                 WithAppName:(NSString *) appNameValue
              WithMediaToken:(NSString *) mediaTokenValue
               WithAuthToken:(NSString *) authTokenValue
            WithProviderName:(NSString *) providerName;


/// Configures and loads a playlist or a full episode into the player.
/// @param mediaURIValue The mgid for the content.
/// @param appNameValue The app name that matches a PMT context.
/// @param mediaTokenValue The Brightcove Media API read token.

- (void)initWithPlaylistWithURI:(NSString *)mediaURIValue WithAppName:(NSString *)appNameValue
                 WithMediaToken:(NSString *)mediaTokenValue;

/// Player resume API
- (PlayerSession *) saveState;
- (void) loadVideo: (PlayerSession *) session;
- (void) loadVideo: (PlayerSession *) session withAuthenticationInfo:(AuthenticationInfo *) authInfo;

/** 
 *  Loads a pre-fetched content item for playback. 
 *  @param item The VMNContentItem to load.
 *  @param error Any error returned from a VMNContentItem request.
 */
- (void)loadVideo:(VMNContentItem*)item withError:(NSError*)error;


/**
 * Prepares and queues a clip for playback. Does not interrupt current playback, and does not auto-play if
 * the queue is originally empty.
 * @param playerSession A PlayerSession for the clip to enqueue.
 * @return YES if the item will attempt to be queued. Returns NO and
 * does nothing if the currently loaded item is not a single clip.
 */
- (BOOL)queueVideo:(PlayerSession*)playerSession;


/**
 * Prepares and queues a clip for playback. Does not interrupt current playback, and does not auto-play if
 * the queue is originally empty.
 * @param playerSession A PlayerSession for the clip to enqueue.
 * @param authInfo The AuthenticationInfo for this clip.
 * @return YES if the item will attempt to be queued. Returns NO and
 * does nothing if the currently loaded item is not a single clip.
 */
- (BOOL)queueVideo:(PlayerSession*)playerSession withAuthenticationInfo:(AuthenticationInfo*)authInfo;


/// Overrides the uri used to make ad requests
/// @param uri The uri to use in the next ad request
- (void)setAdUri:(NSString *)uri;

- (void)setMgidTransformSource:(NSString *)source replacement:(NSString *)replacement;
/// Initiates or resumes playback of content or video ads
- (void)universalPlay;
/// Pauses playback of content or video ads.
- (void)universalPause;

/// Indicates whether or not the content is currently playing
- (BOOL)isPlaying;


/// Indicates whether or not the default clickThrough is enabled
- (BOOL)clickthroughEnabled;

/// @param enabled The boolean value for DebugLogging Reporting
/// Whether or not Omniture will log debug statements to the console.
-(void)setReportingDebugLogging:(BOOL) enabled;

/// @param enabled The boolean value for DebugLogging Ads
/// Whether or not Ad package will log debug statements to the console.
-(void)setAdDebugLogging:(BOOL) enabled;

/// Whether or not the default clickThrough should be enabled when tapping a video ad. The default is NO.
/// @param enabled If NO, clickThrough is disabled when tapping video ads. 
- (void)setClickthroughEnabled:(BOOL)enabled;
/// Opens the click through URL in an WebAppView when a video ad is playing.
- (void)callClickthrough;
/// Resumes video ads.
- (void)resumeAd;
/// Pauses video ads.
- (void)pauseAd;
/// Sets the bottom border offset for overlay ads. This is commumnly used for moving where the overlay ad is displayed. For example
/// for handling collision detection with custom controls and captions.
/// @param border The number of pixels the bottom border should be increased.
- (void)setOverlayBottomBorder:(int)border;
/// Sets the bottom border offset for captions. This is commumnly used for moving where the captions are displayed. For example
/// for handling collision detection with custom controls and overlay ads.
/// @param border The number of pixels the bottom border should be increased.
- (void)setCaptionsBottomBorder:(int)border;
/// Indicates whether or not the loading spinner should be displayed by the player.
/// @param enabled If true the spinner is enabled. The spinner is disabled by default.
/// @param style The UIActivityIndicatorViewStyle for the spinner.
- (void)setSpinnerEnabled:(BOOL)enabled withStyle:(UIActivityIndicatorViewStyle)style;
/// Rotates the player back to 0 degrees
- (void)rotatePlayer0;
/// Rotates the player 90 degrees
- (void)rotatePlayer90;
/// Rotates the player 180 degrees
- (void)rotatePlayer180;
/// Rotates the player 270 degrees
- (void)rotatePlayer270;

- (NSString*) playerStatus;

/// Unloads current content and cleans up associated metadata
- (void)unload;

// Freewheel ad holiday API

/// Resets ad holiday clock to 0
- (void)resetCount;
/// Increments ad holiday count in milliseconds
/// @param byMilliseconds the number of milliseconds to increment the ad holiday count
- (void)incrementCount:(long long)byMilliseconds;
/// Decrements ad holiday count in milliseconds
/// @param byMilliseconds the number of milliseconds to decrement the ad holiday count
- (void)decrementCount:(long long)byMilliseconds;
/// Sets ad holiday clock to duration specified in time since last ad player setting (fulfilling ad holiday requirement, and making end user eligible for an ad)
- (void)fullCount;





// Private
//Social sharing API
- (NSDictionary *)getVideoMetadataForSharingWithService:(NSString *)service;
- (void)shareVideoWebviewWithService:(NSString *)service fluxAccountDomain:(NSString *)fluxAccountDomain mgid:(NSString *)mgid;
- (void)hideSpinner;
- (void)showSpinner;


+ (NSString*)playerVersion;

@end

//
//  VMNEvent.h
//  VMNVideoPlayer
//
//

#import <Foundation/Foundation.h>

@interface VMNEvent : NSObject

@end


///-----------------------------------------------------------------------------
/// @name Event Types
///-----------------------------------------------------------------------------

/// Dispatched when the player is about to pause the player for fetching and playing a mid-roll
extern NSString* const VMNEventWillPauseForMidRoll;
///Dispatched when an ad starts playing
extern NSString* const VMNEventAdDidStart;
extern NSString* const VMNDetailsParamVideoSegmentPlayedAd;
extern NSString* const VMNDetailsParamAdDuration;
///Dispatched when the player is about to request ads.
extern NSString* const VMNEventWillRequestAds;
extern NSString* const VMNEventAdDidEnd;
extern NSString* const VMNEventAdModeDidChange;
extern NSString* const VMNEventAdPause;
extern NSString* const VMNEventAdPlay;
// Call to stop the current ad.
extern NSString* const VMNEventAdStop;
extern NSString* const VMNEventAdProgress;
extern NSString* const VMNEventAdUriSet;
///Dispatched when the request to the PMT is back
extern NSString* const VMNEventConfigSet;
///Dispatched when a new config is applied to the player
/// which can happen way after configure is called and
/// only when loadVideo and loadPlaylist are called.
extern NSString* const VMNEventApplyConfig;
extern NSString* const VMNEventContentChanged;
extern NSString* const VMNEventControlsFadeIn;
extern NSString* const VMNEventControlsFadeOut;
extern NSString* const VMNEventDidCompleteSharingActions;
extern NSString* const VMNEventDidDetectDVRStream;
extern NSString* const VMNEventDidDetectLiveStream;
extern NSString* const VMNEventDidStartSharingActions;
extern NSString* const VMNEventDidPlaylistLoad;
extern NSString* const VMNEventVideoFound;
extern NSString* const VMNEventDismissSharingActions;
extern NSString* const VMNEventDismissCCPopover;
extern NSString* const VMNEventFullEpisodeProgress;
extern NSString* const VMNEventFullEpisodeSeekTo;
extern NSString* const VMNEventFullScreen;
extern NSString* const VMNEventLearnMore;
extern NSString* const VMNEventLiveOrDVRStreamError;
extern NSString* const VMNEventLiveButtonSelected;
extern NSString* const VMNEventMediaGenPlaylistComplete;
extern NSString* const VMNEventOverlayAdDidEnd;
extern NSString* const VMNEventOverlayAdDidStart;
extern NSString* const VMNEventPlaylistDidEnd;
extern NSString* const VMNEventPlaylistModeSet;
extern NSString* const VMNEventSetCaptionsBottomBorder;
extern NSString* const VMNEventSetFullEpisodeDuration;
extern NSString* const VMNEventSetOverlayBottomBorder;
extern NSString* const VMNEventShareWithEmail;
extern NSString* const VMNEventShareWithFacebook;
extern NSString* const VMNEventShareWithTwitter;
extern NSString* const VMNEventSocialSharingEnabled;
extern NSString* const VMNEventSocialSharingDisabled;
extern NSString* const VMNEventToggleCC;
extern NSString* const VMNEventTwitterSharingEnabled;
extern NSString* const VMNEventFacebookSharingEnabled;
extern NSString* const VMNEventEmailSharingEnabled;
extern NSString* const VMNEventWillEnableAds;
extern NSString* const VMNEventWillEnableReporting;
extern NSString* const VMNEventWillShareWithEmail;
extern NSString* const VMNEventWillShareWithFacebook;
extern NSString* const VMNEventWillShareWithTwitter;
extern NSString* const VMNEventWillSeekToNewSegment;
extern NSString* const VMNEventDidSeekToNewSegment;
extern NSString* const VMNEventReadyToPlay;
extern NSString* const VMNResizeCaptions;

extern NSString* const VMNEventSeekToZero;
extern NSString* const VMNEventDidSeekTo;
extern NSString* const VMNEventSetCurrentSeekPosition;
extern NSString* const VMNDetailsParamSeekPosition;

// AdInstance Has clickThrough?
extern NSString* const VMNEventAdInstanceHasClickThrough;
extern NSString* const VMNEventParameterHasClickThrough;
extern NSString* const VMNEventParameterClickThroughURL;

// Autoplay
extern NSString* const VMNEventConfigAutoPlayIsEnabled;

// Player rotation events
extern NSString* const VMNEventRotatePlayerZero;
extern NSString* const VMNEventRotatePlayerNinety;
extern NSString* const VMNEventRotatePlayerOneHundredEighty;
extern NSString* const VMNEventRotatePlayerTwoHundredSeventy;

// Events related to unloading content in the player
extern NSString* const VMNEventUnloadContent;
extern NSString* const VMNEventDidUnloadContent;

// Events related to queue video
extern NSString* const VMNEventDidQueueVideo;
extern NSString* const VMNEventQueueVideoError;

// Errors
extern NSString* const VMNEventMediaGenError;
extern NSString* const VMNEventVideoURINotFoundError;
extern NSString* const VMNEventPlaylistURINotFoundError;
extern NSString* const VMNEventPMTRequestError;
extern NSString* const VMNEventPMTProtocolError;
extern NSString* const VMNEventPMTParseError;
extern NSString* const VMNEventCurrentItemsFailure;
extern NSString* const VMNDetailsParamPlayerSession;
extern NSString* const VMNDetailsParamErrorCode;
extern NSString* const VMNDetailsParamErrorText;
// Fired when the ad playback is stalled due to the slow network for example.
// See https://jira.mtvi.com/browse/BRIG-1569
extern NSString* const VMNEventAdPlaybackDidStall;

// Fired when there is a AVPlayerItem next in the queue
// but with status AVPlayerStatusFailed
extern NSString* const VMNEventNextPlayerItemStatusFailed;
extern NSString* const VMNEventLiveStreamExpiredError;


// Override AVPlayer events
extern NSString* const VMNEventRateChange;

// HTTP Event Logging
extern NSString* const VMNEventEnableHTTPLogging;
extern NSString* const VMNEventDisableHTTPLoggiing;


// Ad holiday API events
extern NSString* const VMNEventAdWillResetCount;
extern NSString* const VMNEventAdWillIncrementCount;
extern NSString* const VMNEventAdWillDecrementCount;
extern NSString* const VMNEventAdWillSetFullCount;

// Controls API events
extern NSString* const VMNEventShowControls;
extern NSString* const VMNEventHideControls;
extern NSString* const VMNEventAirPlayControlVisibility;
extern NSString* const VMNDetailsParamAirPlayVisible;

// PlaybackTracker event for Mediabeacons
extern NSString* const VMNEventPlaybackTrackerCounter;

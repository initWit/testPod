#ifndef VMNPLAYER_CONSTANTS_H
#define VMNPLAYER_CONSTANTS_H

//
//  VMNPlayerConstants.h
//  VMNVideoPlayer

// Default PMT Service URL that can be overriden if passed as parameter
#define PMT_SERVICE_URL @"http://media.mtvnservices.com/pmt/e1/access/index.html?"

//Base URL to use for building the refererID header parameter for PMT requests.
// AppName set at the app level
// http://media.mtvnservices.com/player/api/mobile/iosNative/My_Mobile_App?BCIOSPlayerVersion=1.0

#define REFERER_URL @"http://media.mtvnservices.com/player/api/mobile/iosNative/{appName}?BCIOSPlayerVersion=1.5"

typedef NS_ENUM(NSInteger, VMNPlayerStatus)  {
    PS_NOTHING_PLAYING,
    PS_VIDEO_PLAYING,
    PS_VIDEO_PAUSED,
    PS_AD_PLAYING,
    PS_AD_PAUSED,
    PS_VIDEO_RESTORING
};

typedef NS_ENUM(NSInteger, AVPlayerItemErrorStatusCode)  {
    NO_RESPONSE_FOR_MEDIA = -12645,
    HTTP_403_FORBIDDEN = -12660
};

#define kPlayerStatusArray @"nothingPlaying", @"videoPlaying", @"videoPaused", @"adPlaying", @"adPaused", @"videoRestoring", nil

extern NSString *const kMediaGenErrorCode_AuthFailedTVE;
extern NSString *const kMediaGenErrorMsg_StreamExpired;
extern NSString *const kMediaGenErrorMsg_NotAuthorized;
extern NSString *const kMediaGenErrorCode_TimedOut;
extern NSString *const kMediaGenErrorMsg_TimedOut;

#endif /* VMNPLAYER_CONSTANTS_H */
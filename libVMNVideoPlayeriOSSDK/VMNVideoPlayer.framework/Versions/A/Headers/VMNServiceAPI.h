//
//  VMNServiceAPI.h
//  VMNServices
//
//

#import <Foundation/Foundation.h>
#import "PlayerConfig.h"
#import "MediaGenVideo.h"
#import "TTService.h"

@class VMNContentItem;

typedef void (^mediaItemCompletion)(VMNContentItem *item, NSError *error);

/// A wrapper for calls to the VMN Service.
@interface VMNServiceAPI : NSObject

/// This method makes a request to PMT for a uri and returns a PlayerConfig object that represents the player configuration.
/// @param uri The URI to request the config from.
/// @param appName The current application name.
/// @param completionBlock The code block to run when the request returns.
- (void) getPlayerConfigWithURI: (NSString *) uri
                    withAppName:(NSString *) appName
                 withCompletion:(void (^)(PlayerConfig *playerConfig, NSError *err)) completionBlock;

/// This methods makes a requrest to the brightcove_mediaGenRootURL URL provided in the PlayerConfig and returns the video src to the actual content.
/// @param mediaGenRootURL The base URL to request the video from.
/// @param mediaGenId The media gen id of the video to load.
/// @param bandwidth The calcutated current bandwidth.
/// @param isOverride Is this an override mgid?
/// @param block The code block to run when the request returns.
- (void) getMediaGenVideoWithMediaGenId: (NSString *) mediaGenRootURL
                             mediaGenId: (NSString *) mediaGenId 
                              bandwidth: (int) bandwidth
                             isOverride: (BOOL) isOverride
                         withCompletion: (void (^)(MediaGenVideo *mediaGenVideo, NSError *err))block;

/// This methods makes a requrest to the brightcove_mediaGenRootURL URL provided in the PlayerConfig and returns the video src to the actual content.
/// @param mediaGenRootURL The base URL to request the video from.
/// @param authTokenId The authentication token id of the video to load.
/// @param providerName The media gen id of the video to load.
/// @param siteSectionId The media gen id of the video to load.
/// @param mediaGenId The media gen id of the video to load.
/// @param bandwidth The calcutated current bandwidth.
/// @param isOverride Is this an override mgid?
/// @param block The code block to run when the request returns.
- (void) getMediaGenVideoWithMediaGenId: (NSString *) mediaGenRootURL
                             mediaGenId: (NSString *) mediaGenId
                            authTokenId: (NSString *) authTokenId
                           providerName: (NSString *) providerName
                   freewheelSiteSection: (NSString *) siteSectionId
                              bandwidth: (int) bandwidth
                             isOverride: (BOOL) isOverride
                         withCompletion: (void (^)(MediaGenVideo *mediaGenVideo, NSError *err))block;

/// This methods makes a request to the captions URL provided and returns a CaptionSet containing captions for the current video.
/// @param videoCaptionsURL The URL to load the captions from.
/// @param block The code block to run when the request returns.
- (void) getVideoCaptionsWithURL: (NSString *) videoCaptionsURL
                  withCompletion: (TTCompletion)block;


- (void)getMediaItemForMGID:(NSString*)mgid
                 withConfig:(PlayerConfig*)config andOptions:(NSDictionary*)options
              andCompletion:(mediaItemCompletion)completion;


@end

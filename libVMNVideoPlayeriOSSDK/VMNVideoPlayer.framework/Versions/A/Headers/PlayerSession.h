//
//  PlayerSnapshot.h
//  VMNVideoPlayer
//
//  Created by Mo Farajmandi on 2014-04-14.
//
//

#import <Foundation/Foundation.h>
#import "VMNFreewheelSupport.h"
#import "VMNPlayerConstants.h"

@interface PlayerSession : NSObject <NSCoding, NSCopying>

/**
 Creates a new session for initially loading a video using MRSS.
 @param appName The app name for PMT request.
 @param mgid The MGID for the requested content.
 */
-(id)initWithAppName:(NSString *)appName AndMGID:(NSString *)mgid;

/**
 Creates a new session for initially loading a video using Video Cloud.
 @param appName The app name for PMT request.
 @param mgid The MGID for the requested content.
 @param token The BrightCove Video Cloud authentication token.
 */
-(id)initWithAppName:(NSString *)appName AndMGID:(NSString *)mgid AndMediaToken:(NSString*)token ;

/// Init PlayerSession object with minimal information necessary to load video
-(id)initWithAppName:(NSString *)appName AndMediaToken:(NSString *) mediaToken AndMGID:(NSString *) mgid AndIsPlayList:(BOOL) isPlaylist
AndCurrentPlaylistIndex:(NSInteger) currentPlaylistIndex AndVideoPosition:(NSNumber *) videoPosition;

/**
 * set the playhead position relative the start of a segment
 * @param position playhead position in miliseconds relative to the segment index
 * @param index segment index to which the playhead position is relative.
 */
- (void) setPlayheadPostion: (NSNumber *) position fromSegment:(NSInteger) index;

/// appName of the VMNPlayer
@property (atomic, copy) NSString *appName;
/// mediaToken of the VMNPlayer
@property (atomic, copy) NSString *mediaToken;
/// videoName of the current video
@property (atomic, copy) NSString *videoName;
/// mgid of the restoring video
@property (atomic, copy) NSString *mgid;
/// is the restoring Item a Playlist (FullEpisodes are also considered a playlist) or not (a single video)
@property (atomic, assign) BOOL isPlaylist;
/// if playlist; what's the currentPlaylistIndex
@property (atomic, assign) NSInteger currentPlaylistIndex;
/// a flag that indicates if VideoPosition is Offset From currentPlaylistIndex
@property (atomic, assign) BOOL isVideoPositionOffsetFromSegmentIndex;
/// videoPosition in miliseconds
@property (atomic, strong) NSNumber * videoPosition;
/// videoDuration
@property (atomic, strong) NSNumber * videoDuration;
/// videoState of the VMNPlayer (VIDEO_PLAYING, VIDEO_PAUSED, AD_PLAYING, NOTHING_PLAYING, AD_PAUSED)
@property (atomic, assign) VMNPlayerStatus playerStatus;
/// Video segments that have watched ads; this is a dictionary that includes the following (key:value):
///  mgid0:NSNumber(true/false), migd1:NSNumber(true/false), mgid2:NSNumber(true/false), etc.
@property (atomic, strong) NSDictionary *videoSegmentsPlayedAds;
/// What type of ad is currently running.
@property (atomic, assign) VMNCurrentAdType currentAdType;

@end

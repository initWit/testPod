//
//  VMNMediaItem.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-07-16.
//
//

#import <Foundation/Foundation.h>
#import "PlayerConfig.h"
#import "VMNVideo.h"

@class AuthenticationInfo;

@interface VMNContentItem : NSObject

/**
 * The player configuration for this media item.
 */
@property (nonatomic, strong, readonly) PlayerConfig* playerConfig;


/**
 * The full MRSS response for the root MGID.
 */
@property (nonatomic, copy, readonly) NSDictionary* mediaRSS;


/**
 * The root MGID for this content item. May be nil.
 */
@property (nonatomic, strong) NSString *mgid;


/**
 * The AuthenticationInfo object for this item
 */
@property (nonatomic, strong) AuthenticationInfo* authInfo;


/**
 * The App Name for this item
 */
@property (nonatomic, strong) NSString* appName;


/**
 * The ordered list of VMNVideos related to this media item.
 */
@property (nonatomic, strong, readonly) NSArray* videos;


/**
 * Is this media item a playlist OR full episode?
 */
@property (nonatomic, assign, readonly) BOOL isPlaylist;


/**
 * Is this item a full episode?
 */
@property (nonatomic, assign, readonly) BOOL isFullEpisode;



/**
 * Creates a new media item with the given videos and matching MRSS response.
 * @param videos The array of VMNVideos related to an MGID
 * @param mediaRSS The complete MRSS response for an MGID
 * @param config The PlayerConfig for this media item
 */
+(instancetype)contentItemWithVideos:(NSArray*)videos
                         andMetaData:(NSDictionary*)mediaRSS
                     andPlayerConfig:(PlayerConfig*)config;


-(instancetype)initWithVideos:(NSArray*)videos
                  andMetaData:(NSDictionary*)mediaRSS
              andPlayerConfig:(PlayerConfig*)config;


- (BOOL)expired;

@end

//
//  VMNVideo.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-05-27.
//  Copyright (c) 2014 Viacom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaGenVideo.h"

@class BCVideo;

/**
 * A container object for a specific VMN segment. Stores the equivalent MediaGenVideo response, and 
 * the relevant data from the MRSS response. 
 */
@interface VMNVideo : NSObject


/**
 * The URL for the asset source.
 */
@property (nonatomic, readonly, copy) NSURL *URL;


/**
 * Any metadata about the particular video should be stored in this dictionary.
 */
@property (nonatomic, strong) NSDictionary *metadata;


/**
 * A simplified accessor to media:category items. Keyed by scheme, ex: "urn:mtvn:video_title"
 */
@property (nonatomic, strong) NSDictionary* mediaCategory;


/** 
 * The MediaGenVideo for this video item
 */
@property (nonatomic, readonly, strong) MediaGenVideo* mediaGenVideo;


/**
 * Returns a video storing an asset URL with an empty metadata dictionary.
 *
 * @param URL The source URL for the asset.
 */
+(instancetype)videoWithURL:(NSURL*)URL;


/**
 * Returns a video storing an asset URL and metadata.
 *
 * @param URL The source URL for the asset.
 * @param metadata A dictionary containing any metadata for the asset.
 */
+(instancetype)videoWithURL:(NSURL*)URL andMetaData:(NSDictionary*)metadata;


/**
 * Returns a video derived from a MediaGenVideo and metadata.
 *
 * @param mediaGen The MediaGenVideo for this asset.
 * @param metadata A dictionary containing any metadata for the asset.
 */
+(instancetype)videoWithMediaGenVideo:(MediaGenVideo*)mediaGen andMetaData:(NSDictionary*)metadata;


/**
 * Returns a BCVideo wrapper for this VMNVideo, for playback in a BCQueuePlayer.
 */
-(BCVideo*)BCVideo;



#pragma mark - Metadata Accessors

/**
 * A shortcut for the videos mgid. This can also be found through metadata[@"guid"][@"text"]
 */
@property (nonatomic, readonly, strong) NSString* mgid;


/**
 * A shortcut for the videos duration. This can also be found through metadata[@"media:group"][@"media:content"][@"duration"]
 */
@property (nonatomic, readonly, assign) NSInteger duration;


/**
 * The title of the video. Maps to metadata[@"title"][@"text"]. You probably want -videoTitle.
 */
- (NSString*)title;


/**
 * The description of the video. Maps to metadata[@"description"][@"text"], 
 * metadata[@"media:group"][@"media:description"][@"text"] or -title, in that order.
 */
- (NSString*)shortDescription;


/**
 * The video artist. Maps to mediaCategory[@"urn:mtvn:artist"]. Defaults to NO-ARTIST.
 */
- (NSString*)artist;


/**
 * The video franchise. Maps to mediaCategory[@"urn:mtvn:franchise"]. Defaults to NO-FRANCHISE.
 */
- (NSString*)franchise;


/**
 * The video title. Maps to mediaCategory[@"urn:mtvn:video_rep_title"], 
 * mediaCategory[@"urn:mtvn:video_title"] or -title, in that order.
 */
- (NSString*)videoTitle;


/**
 * The link to the video. Maps to metadata[@"link"][@"text"]
 */
- (NSString*)videoLink;


/**
 * If present, the playlist title. Maps to mediaCategory[@"urn:mtvn:playlist_rep_title"] or
 * mediaCategory[@"urn:mtvn:playlist_title"], in that order.
 */
- (NSString*)playlistTitle;


/**
 * The playlist URI. Maps to mediaCategory[@"urn:mtvn:playlist_uri"].
 */
- (NSString*)playlistURI;


/**
 * The video content type. Maps to mediaCategory[@"urn:mtvn:content_type"].
 */
- (NSString*)contentType;


/**
 * Video display SEO. Maps to mediaCategory[@"urn:mtvn:display:seo"].
 */
- (NSString*)displaySEO;


/**
 * The video rating. Maps to metadata[@"media:group"][@"media:rating"][@"text"].
 */
- (NSString*)rating;


/**
 * The EN captions URL. Maps to metadata[@"media:group"][@"media:text"][@"src"].
 */
- (NSString*)captions_en;


/**
 * The video event type. Maps to mediaCategory[@"urn:mtvn:eventType"].
 */
- (NSString*)eventType;


/**
 * Whether the video is reportable. Always @"true".
 */
- (NSString*)reportable;

@end

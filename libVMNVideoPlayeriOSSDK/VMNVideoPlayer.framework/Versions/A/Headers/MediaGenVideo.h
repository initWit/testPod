//
//  MediaGenVideo.h
//  VMNServices
//
//

#import <Foundation/Foundation.h>

#import "MediaGenVideoError.h"


/// Represents a MediaGen video.
//added sendAsynchronousRequest 1 THe URL
@interface MediaGenVideo : NSObject <NSXMLParserDelegate> {
           NSMutableString *currentString;
}


@property (nonatomic, assign) id parentParserDelegate;

/// Array of MediaGenVideoRenditions.
@property (nonatomic, readonly, strong) NSMutableArray *renditions;
/// Array of MediaGenBeacons.
@property (nonatomic, readonly, strong) NSMutableArray *beacons;
/// Array of MediaGenOverlays.
@property (nonatomic, readonly, strong) NSMutableArray *overlays;
/// Hold an instance of a MediaGenVideoError if an error is encountered.
@property (nonatomic, strong) MediaGenVideoError *mediaGenVideoError;
/// Whether the video is in live mode or not.
@property (nonatomic, assign) BOOL live;
/// Whether the video is in dvr mode or not.
@property (nonatomic, assign) BOOL dvr;
/// liveStreamExpires: the maximum number of seconds that a user is allowed to watch a live stream
@property (nonatomic, assign) NSInteger liveStreamExpires;
///
@property (nonatomic, strong) NSDate *sourceExpiry;
/// Live/simulcast stream time offset. 0 or -3, based on region. 
@property (nonatomic, assign) NSInteger offsetHours;
/// Whether the video allows or disallows Wireless Media Streaming (WMS) rights (e.g. Airplay).
/// we are passing it by string as opposed to boolean to support the cases where allowWMS is not set but we still don't
/// necessarily want to disable WMS.
@property (nonatomic, strong) NSString * wmsallow;
/// The value of the code attribute
@property (nonatomic, strong) NSString *code;
/// The value of the format attribute
@property (nonatomic, strong) NSString *format;

@end
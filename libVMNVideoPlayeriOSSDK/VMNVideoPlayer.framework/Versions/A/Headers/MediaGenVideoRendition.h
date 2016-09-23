//
//  MediaGenVideoRendition.h
//  VMNServices
//
//

#import <Foundation/Foundation.h>
#import "VMNJSONSerializable.h"

/// Represents a single rendition of a MediaGen video.
@interface MediaGenVideoRendition : NSObject <NSXMLParserDelegate>
{
       NSMutableString *currentString;
}
@property (nonatomic, assign) id parentParserDelegate;

/// The source url of the video.
@property (nonatomic, strong) NSString *src;
/// The content delivery network.
@property (nonatomic, strong) NSString *cdn;
/// The type of video.
@property (nonatomic, strong) NSString *type;
/// The duration of the video.
@property (nonatomic, assign) long long duration;
/// Whether the rendition is in live mode or not.
@property (nonatomic, assign) BOOL live;
/// Whether the rendition supports dvr mode or not.
@property (nonatomic, assign) BOOL dvr;
/// Whether the rendition supports nielsenID3 or not
@property (nonatomic, assign) BOOL nielsenID3;

@end
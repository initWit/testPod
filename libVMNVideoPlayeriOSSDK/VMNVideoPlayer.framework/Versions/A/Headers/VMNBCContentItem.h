//
//  VMNBCMediaItem.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-08-22.
//
//

#import "VMNContentItem.h"
#import "BCVideo.h"

@interface VMNBCContentItem : VMNContentItem


+ (instancetype)contentItemWithBCVideos:(NSArray *)videos andPlayerConfig:(PlayerConfig *)config;

@end



@interface BCVideo (VMNBCContentItem)

- (NSInteger)duration;
- (MediaGenVideo*)mediaGenVideo;

@end
//
//  VMNVideoPlayerUtils.h
//  VMNVideoPlayer
//
//  Created by Oscar Cortes on 7/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCVideo.h"
#import "MediaGenVideo.h"


/// Class that can be used to house various utilities needed by the player.
@interface VMNVideoPlayerUtils : NSObject

/// Clones a BCVideo object, replacing the rendition urls with those retrieved from mediagen.
/// @param originalVideo The original BCVideo to clone.
/// @param mediaGenVideo The MediaGenVideo object with values to insert into the cloned video.
- (BCVideo *) cloneBCVideo:(BCVideo *) originalVideo WithMediaGenVideo:(MediaGenVideo *) mediaGenVideo;
@end

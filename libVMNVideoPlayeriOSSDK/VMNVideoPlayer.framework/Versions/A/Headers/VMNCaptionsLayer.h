//
//  VMNCaptionsLayer.h
//  VMNVideoPlayer
//
//  Created by George White on 9/24/12.
//
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreText/CoreText.h>
#import "BCURLConnection.h"

@class TTElement;
@class VMNPlayer;

/// Coordinates the showing of closed captions in the player.
@interface VMNCaptionsLayer : CALayer
{
    CGRect fullFrame;
    CGRect videoFrame;
    
    BOOL hasCaptions;
}

/// The player that the captions will be shown in.
@property (nonatomic, weak) VMNPlayer *player;
/// Whether or not the video has captions.
@property (nonatomic, assign) BOOL hasCaptions;


/// Whether or not the captions are enabled.
@property (nonatomic, assign, setter=setCaptionsEnabled:) BOOL enabled;

// private???
@property (atomic, strong) AVSynchronizedLayer *syncLayer;
@property (nonatomic, strong) TTElement *captionRoot;
@property (nonatomic, strong) NSMutableDictionary *regions;
@property (nonatomic, strong) NSString *defaultRegion;
@property (nonatomic, assign) CGRect fullFrame;
@property (nonatomic, assign) CGRect videoFrame;
@property (nonatomic, assign) NSInteger border;


/// Convenience constructor to create a captions layer.
/// @param player The player to associate with the captions.
+(id)layerWithPlayer:(VMNPlayer *)player;

/// Designated initializer
-(void)initialize;

/// Clean up the captions for deallocation
-(void)cleanup;

/// Clean up that can be used by unload functionality
- (void) reset;

/// Update the captions to reflect the current movie
/// @param captionsURL The url where the captions are located.
-(void)updateCaptionsWithURL:(NSString *)captionsURL;

/// Re-synchronize the captions with the current item in the player
-(void)updateSync;

/// Returns whether captions are visible or not.
+(BOOL)captionsEnabled;

/// Enables or disables the captions.
-(void)setCaptionsEnabled:(BOOL)enabled;

/// Turns captions on/off. Deprecated; use .enabled instead. 
-(void)toggleCaptions;


/// Creates and adds the captions layer.
-(void)processCaptions;

/// Sets the rect of the frame holding the captions.
/// @param frame The rect to set the size to.
- (void)resizeCaptionsFrame:(CGRect)frame;

- (void) didPlayerSizeChange:(CGRect)newFrame;

@end

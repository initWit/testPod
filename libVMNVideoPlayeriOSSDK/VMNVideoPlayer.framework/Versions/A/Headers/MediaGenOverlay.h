//
//  MediaGenOverlay.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-05-29.
//
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>


@interface MediaGenOverlay : NSObject


/// The overlay's view
@property (nonatomic, strong) UIView *view;

/// The overlay source URL
@property (nonatomic, strong) NSString *src;

/// The overlay format
@property (nonatomic, strong) NSString *format;

/// Time the overlay begins displaying
@property (nonatomic, assign) NSInteger startTime;

/// Duration the overlay should display for (in ms)
@property (nonatomic, assign) NSInteger duration;

/// Width of the overlay, in pixels
@property (nonatomic, assign) NSInteger width;

/// Height of the overlay, in pixels
@property (nonatomic, assign) NSInteger height;

/// Horizontal position, as a percentage of the parent view (from the left)
@property (nonatomic, assign) NSInteger xPercent;

/// Vertical position, as a percentage of the parent view (from the top)
@property (nonatomic, assign) NSInteger yPercent;

/// Pre-set position, defaults to BC (bottom-center)
@property (nonatomic, strong) NSString* align;

@property (nonatomic, assign) BOOL persistant;

/**
 *  Create a new overlay from the source URL.
 *  @param urlString The URL for the overlay data. 
 *  @param format The format of the data
 *  @return A MediaGenOverlay object. Returns nil if the format is not supported.
 */
-(instancetype)initWithSourceURL:(NSString*)urlString andFormat:(NSString*)format;


/**
 *  Destroy the overlay object. Called automatically when overlay is removed from the manager.
 */
-(void)destroy;


/**
 *  Begins loading the overlay data. Called automatically when overlay is added to the manager.
 */
-(void)loadOverlay;


/**
 *  Calculates and sets the overlays position and size based on the parent view and 
 *  dimensions specified by MediaGen. Called automatically when overlay is added to the manager.
 */
-(void)calculateFrame:(AVPlayerLayer*)layer;


-(void)setPositionFromAlignment:(NSString*)alignment;

@end





@interface MediaGenOverlayParser : NSObject <NSXMLParserDelegate>

@property (nonatomic, strong) NSMutableString* currentString;
@property (nonatomic, strong) id parentParser;

@property (nonatomic, strong) NSString* value;

@end

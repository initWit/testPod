//
//  OverlayManager.h
//  VMNVideoPlayer
//
//  Created by Sander Gates on 8/20/12.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Defines overlay axis - these are enums, not classes
#import "OverlayAxis.h"

// Declare classes needed for interface definition
@class Overlay;
@class OverlayArrangement;
@class OverlayBounds;
@class OverlayRegion;

@interface OverlayManager : NSObject

// Externally visible properties
@property (retain) NSMutableArray *arrangements;
// @property (retain) NSMutableArray *overlays;
@property (retain) NSMutableArray *groups;
@property (retain) UIView         *playerView;

// Externally visible methods
-(OverlayManager *) init;
-(OverlayManager *) initWithPlayerView:(UIView *)playerView;


-(void) createGroupWithName:(NSString *)groupName;
-(void) removeGroupByName:(NSString *)groupName;

-(Overlay *) createOverlayWithName:(NSString *)name
                         groupName:(NSString *)groupName
                             width:(int)width
                            height:(int)height
                      canBeCovered:(BOOL)canBeCovered
          coveredPenaltyMultiplier:(float)coveredPenaltyMultiplier
                 allowedRegionLeft:(int) allowedRegionLeft
                allowedRegionRight:(int) allowedRegionRight
                  allowedRegionTop:(int) allowedRegionTop
               allowedRegionBottom:(int) allowedRegionBottom
                 allowedRegionAxis:(OverlayAxis)allowedRegionAxis
                       overlayBias:(int)overlayBias;
-(void) removeOverlayByName:(NSString *)name;
-(void) arrangeOverlaysToStage:(OverlayBounds *)targetStage;

@end

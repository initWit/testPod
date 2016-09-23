//
//  Overlay.h
//  VMNVideoPlayer
//
//  Created by Sander Gates on 8/20/12.
//
//

#import <UIKit/UIKit.h>

@class OverlayBounds;

@interface Overlay : NSObject

@property (retain) NSString      *overlayName;
@property (retain) OverlayBounds *bounds;
@property (retain) UIView        *overlayView;
@property          BOOL           canBeCovered;
@property          float          coveredPenaltyMultiplier;

@property (retain) NSMutableArray *allowedRegions;

-(Overlay *) initWithName:(NSString *)overlayName
                   bounds:(OverlayBounds *)bounds
             canBeCovered:(BOOL)canBeCovered
 coveredPenaltyMultiplier:(float)coveredPenaltyMultiplier;

-(NSArray *)arrangeFromOverlays:(NSArray *)overlays
           existingArrangements:(NSArray *)existingArrangements;

-(void) moveToBounds;

@end

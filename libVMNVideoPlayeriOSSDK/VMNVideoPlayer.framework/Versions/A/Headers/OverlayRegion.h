//
//  OverlayRegion.h
//  VMNVideoPlayer
//
//  Created by Sander Gates on 8/20/12.
//
//

#import <Foundation/Foundation.h>
#import "OverlayAxis.h"

@class OverlayBounds;

@interface OverlayRegion : NSObject

@property (retain) OverlayBounds *bounds;
@property          OverlayAxis    axis;
@property          int            bias;


-(OverlayRegion *) initWithBounds:(OverlayBounds *)bounds axis:(OverlayAxis)axis bias:(int)bias;
-(OverlayBounds *) createStartingBoundsFromOverlay:(Overlay *) overlay direction:(OverlayAxisDirection)direction;
-(NSArray *) createLowPlacementsForOverlay:(Overlay *)overlay existingPlacements:(NSMutableArray *)existingPlacements;
-(NSArray *) createHighPlacementsForOverlay:(Overlay *)overlay existingPlacements:(NSMutableArray *)existingPlacements;

@end

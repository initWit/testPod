//
//  OverlayBounds.h
//  VMNVideoPlayer
//
//  Created by Sander Gates on 8/20/12.
//
//

#import <Foundation/Foundation.h>

@interface OverlayBounds : NSObject

@property (nonatomic) int left;
@property (nonatomic) int top;
@property (nonatomic) int right;
@property (nonatomic) int bottom;
@property (nonatomic) int width;
@property (nonatomic) int height;

-(OverlayBounds *) initWithLeftBoundary:(int)left top:(int)top right:(int)right bottom:(int)bottom;
-(long long) scoreRectangle:(OverlayBounds *)rectangle bias:(int)bias;
-(BOOL) outOfBounds:(OverlayBounds *)innerBounds;
-(BOOL) overlaps:(OverlayBounds *)otherBounds;

@end

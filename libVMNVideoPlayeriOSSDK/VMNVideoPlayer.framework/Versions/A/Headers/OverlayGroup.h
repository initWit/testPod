//
//  OverlayGroup.h
//  VMNVideoPlayer
//
//  Created by Sander Gates on 9/4/12.
//
//

#import <Foundation/Foundation.h>

@interface OverlayGroup : NSObject

@property (retain) NSString       *groupName;
@property (retain) NSMutableArray *overlays;

-(OverlayGroup *) initWithName:(NSString *)name;

@end

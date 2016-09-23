//
//  TVEAuthRequired.h
//  VMNVideoPlayer
//
//  Created by Mo Farajmandi on 2014-05-26.
//
//

#import <Foundation/Foundation.h>

@interface TVEAuthRequired : NSObject <NSCopying>

-(id)initWithValue:(BOOL)value;

@property (atomic, assign) BOOL value;

/// authRequired needs to be passed as string to FreeWheel
- (NSString *) valueString;

@end

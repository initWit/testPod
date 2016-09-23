//
//  TTService.h
//  VMNVideoPlayer
//
//  Created by Jay Dolan on 9/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCURLConnection.h"

@class TTElement;

typedef void (^TTCompletion)(TTElement *, NSError *);

@interface TTService : NSObject

/*
 * @brief Resolve TT captions for the specified DFXP URL.
 *
 * @param completion The completion block will fire with the root TTElement or
 *   an NSError, but not both.
 */
+ (void) timedTextWithURL:(NSURL *)url withCompletion:(TTCompletion)completion;

@end

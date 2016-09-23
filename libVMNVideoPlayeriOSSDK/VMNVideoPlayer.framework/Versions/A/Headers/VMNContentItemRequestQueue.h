//
//  VMNContentItemRequestQueue.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-09-11.
//
//

#import <Foundation/Foundation.h>


@class VMNContentItemRequest;



/**
 * A singleton queue which manages all VMNContentItemRequests.
 */
@interface VMNContentItemRequestQueue : NSObject


/**
 * A serial queue that manages Content Item requests.
 */
@property (nonatomic, strong) NSOperationQueue *requestQueue;


/**
 * Queue used for managing internal connection delegates. Do not use.
 */
@property (nonatomic, strong) NSOperationQueue *connectionQueue;


/**
 *  The queue.
 *  @return The request queue.
 */
+ (VMNContentItemRequestQueue *)sharedQueue;


/**
 *  Adds a request for a content item to the queue.
 *  @param request The request to enqueue.
 */
- (void)addRequest:(VMNContentItemRequest*)request;


/**
 *  Cancels all active or pending requests.
 */
- (void)cancelAllRequests;


@end

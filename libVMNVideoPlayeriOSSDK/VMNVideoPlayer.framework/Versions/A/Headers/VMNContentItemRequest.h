//
//  VMNContentItemRequest.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-09-11.
//
//

#import <Foundation/Foundation.h>
#import "VMNContentItem.h"


@class AuthenticationInfo;

/**
 *  An operation which performs all of the requests required to create
 *  a VMNContentItem object for playback.
 */
@interface VMNContentItemRequest : NSOperation

/**
 *  The MGID this request is fetching.
 */
@property (nonatomic, strong, readonly) NSString* mgid;


/**
 *  The app name this request was made with.
 */
@property (nonatomic, strong, readonly) NSString* appName;


/**
 *  The completion handler for the request.
 */
@property (nonatomic, copy) void (^completionHandler)(VMNContentItem *, NSError *);


/**
 *  Subclasses should place custom requests/configuration here, and call super -beginRequest
 *  at the end of their implementation.
 */
- (void)beginRequest;


/**
 *  The internal completion handler for this item. Subclasses can override this to 
 *  implement returning a subclass of VMNContentItem. 
 *  Call super -finishRequestWithContentItem:andError: at the end of a custom implementation.
 *  @param item The VMNContentItem (or subclass) to return in the completion block.
 *  @param error The NSError corresponding to any error that occurs during the content request.
 */
- (void)finishRequestWithContentItem:(VMNContentItem*)item andError:(NSError*)error;


/**
 *  Creates a new content item request. Use VMNContentItem +contentItemForMGID:andAppName:withCompletion: instead
 *  @param mgid The mgid for the content requested.
 *  @param appName The App Name to use in requests for the content.
 *  @param auth The TVE AuthenticationInfo object for this request.
 *  @param completion The completion handler for the request.
 *  @return A new VMNContentItemRequest.
 */
- (instancetype)initWithMGID:(NSString*)mgid
                     AppName:(NSString*)appName
          AuthenticationInfo:(AuthenticationInfo*)auth
               andCompletion:(void (^)(VMNContentItem *, NSError *))completion;


@end



#pragma mark - VMNContentItem Request Category

@interface VMNContentItem (Request)

/**
 *  Fetches all metadata corresponding to a particular content item. 
 *  @param mgid The mgid for the content requested.
 *  @param appName The App Name to use in requests for the content.
 *  @param completion The completion handler for the request.
 *  @return The specific VMNContentItemRequest for this request.
 */
+ (VMNContentItemRequest *)contentItemForMGID:(NSString*)mgid
                                   andAppName:(NSString*)appName
                               withCompletion:(void (^)(VMNContentItem*, NSError*))completion;


/**
 *  Fetches all metadata corresponding to a particular content item.
 *  @param mgid The mgid for the content requested.
 *  @param appName The App Name to use in requests for the content.
 *  @param auth The TVE AuthenticationInfo object for this request.
 *  @param completion The completion handler for the request.
 *  @return The specific VMNContentItemRequest for this request.
 */
+ (VMNContentItemRequest *)contentItemForMGID:(NSString *)mgid
                                   andAppName:(NSString *)appName
                       withAuthenticationInfo:(AuthenticationInfo*)auth
                                andCompletion:(void (^)(VMNContentItem *, NSError *))completion;

@end
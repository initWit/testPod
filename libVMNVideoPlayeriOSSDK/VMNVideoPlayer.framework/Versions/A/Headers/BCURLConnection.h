//
//  BCURLConnection.m
//  VMNVideoPlayer
//
//  Created by Jay Dolan on 9/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VMNJSONSerializable.h"

typedef void (^BCURLCompletion)(id parserDelegate, NSError *error);

/**
 * @brief Abstract base class for retrieving URL resources.
 */
@interface BCURLConnection : NSObject

@property (nonatomic, assign) BCURLCompletion completion;
@property (nonatomic, retain) id parserDelegate;
@property (nonatomic, strong, readonly) NSURLConnection *connection;
@property (nonatomic, strong, readonly) NSMutableData *data;
@property (nonatomic, copy, readonly) NSURLRequest *request;

- (void) start;

@end

/// Provides a connection that loads JSON.
@interface BCURLConnectionJSON : BCURLConnection

@property (nonatomic, retain) id<VMNJSONSerializable> parserDelegate;

/// Factory method for instantiating BCURLConnectionJSON. The returned connections are automatically started, but they may be restarted as well.
/// @param request The NSURLRequest for this connection.
/// @param parserDelegate Object with defined methods that respond to messages from the parser.
/// @param completion The code block that handles the request.
+ (BCURLConnectionJSON *) withRequest:(NSURLRequest *)request withParserDelegate:(id)parserDelegate withCompletion:(BCURLCompletion) completion;
@end


/// Provides a connection that loads JSON.
@interface BCURLConnectionXML : BCURLConnection

@property (nonatomic, retain) id<NSXMLParserDelegate> parserDelegate;

/// Factory method for instantiating BCURLConnectionXML. The returned connections are automatically started, but they may be restarted as well.
/// @param request The NSURLRequest for this connection.
/// @param parserDelegate Object with defined methods that respond to messages from the parser.
/// @param completion The code block that handles the request.
+ (BCURLConnectionXML *) withRequest:(NSURLRequest *)request withParserDelegate:(id<NSXMLParserDelegate>)parserDelegate withCompletion:(BCURLCompletion)completion;
@end
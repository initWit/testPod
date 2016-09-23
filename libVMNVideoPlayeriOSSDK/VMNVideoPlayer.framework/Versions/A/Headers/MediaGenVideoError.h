//
//  MediaGenVideoError.h
//  VMNVideoServices
//
//  Created by Kit Huynh on 8/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VMNJSONSerializable.h"

/// Represents an error in receiving MediaGen info.
@interface MediaGenVideoError : NSObject <NSXMLParserDelegate>
{
    NSMutableString *currentString;
}

@property (nonatomic, assign) id parentParserDelegate;

/// The error code
@property (nonatomic, strong) NSString *errorCode;
/// Text describing the error.
@property (nonatomic, strong) NSString *errorText;

@end

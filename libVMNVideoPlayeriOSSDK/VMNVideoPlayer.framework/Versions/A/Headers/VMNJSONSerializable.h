//
//  JSONSerializable.h
//  VMNServices
//
//

#import <Foundation/Foundation.h>

/// Protocol for a class that can be serialized into JSON.
@protocol VMNJSONSerializable <NSObject>

- (void)readFromJSONDictionary:(NSDictionary *)d;

@end

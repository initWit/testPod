//
//  MVPDProviderName.h
//  VMNVideoPlayer
//
//  Created by Mo Farajmandi on 2014-05-26.
//
//

#import <Foundation/Foundation.h>

@interface MVPDProviderName : NSObject <NSCopying>

/// current provider Name
@property (atomic, strong) NSString *value;


-(id)initWithValue:(NSString *)value;

/// This method returns the md5 hash of lower case provider name
- (NSString *) lowerCaseProviderNameInMD5;

/// toFreeWheel getter prepare the provider name for freewheel. 
- (NSString *) toFreeWheel;

@end

//
//  AuthenticationInfo.h
//  VMNVideoPlayer
//
//  Created by Mo Farajmandi on 2014-05-26.
//
//

#import <Foundation/Foundation.h>
#import "MVPDProviderName.h"
#import "TVEAuthRequired.h"

@interface AuthenticationInfo : NSObject <NSCopying>

-(id)initWithProviderName:(MVPDProviderName *)providerName AndAuthToken:(NSString *) authToken AndAuthRequired:(TVEAuthRequired *) authRequired;
-(id)initWithProviderName:(MVPDProviderName *)providerName AndAuthToken:(NSString *) authToken;
-(id)initWithProviderName:(MVPDProviderName *)providerName AndAuthRequired:(TVEAuthRequired *) authRequired;
-(id)initWithProviderName:(MVPDProviderName *)providerName;
    
/// current provider Name
@property (atomic, strong) MVPDProviderName *providerName;
/// authentication token coming from a third party component (e.g. TVESDK)
@property (atomic, strong) NSString *authToken;
/// authRequired flag
@property (atomic, strong) TVEAuthRequired * authRequired;

@end

//
//  PlayerConfig.h
//  VMNServices
//
//

#import <Foundation/Foundation.h>
#import "VMNJSONSerializable.h"


/// Class that encapsulates various configuration values for the player.
@interface PlayerConfig : NSObject <VMNJSONSerializable>

/// mediaURL of the PlayerConfig
@property (atomic, strong) NSString *mediaURIValue;

/// Error text in the event of unavailable video.
@property (atomic, copy) NSString *errorSlateMessage;
/// The root URL for the MRSS service
@property (atomic, copy) NSString* mrssFeed;
/// The root url for the mediagen service
@property (atomic, assign) NSString *brightcove_mediagenRootURL;
/// Form factor id, a string that encodes various settings, i.e. full episode, gui type, social sharing.
@property (atomic, assign) NSString *formFactorID;
/// A dictionary with the player config properties
@property (atomic, retain) NSDictionary *config;
/// URI for getting config data.
@property (atomic, copy) NSString *uri;
/// FreeWheel setting for minimum time between ads.
@property (atomic, assign) long long timeSinceLastAd;
/// Are FreeWheel ads enabled?
@property (atomic, assign) BOOL freewheelEnabled;
/// The site section id (SSID) for FreeWheel.
@property (atomic, assign) NSString *freewheelSiteSection;
/// The FreeWheel Network ID. This might or might not be provided. If it is not, use the default one. (Set in th FW component).
@property (atomic, assign) NSString *freewheelNetworkId;

//Override parameters
@property (atomic, assign) NSDictionary *overrideParameters;
@property (atomic, copy) NSString *franchise;


// Values for known form factor ids
/// Is the player in full episode meode?
@property (atomic, assign) BOOL isFullEpisode;
/// Is this player expected to auto-play?
@property (atomic, assign) BOOL isAutoplayEnabled;
/// Dictionary containing form factor values.
@property (atomic, retain) NSDictionary *formFactorIdsDictionary;
/// Is this a chromed player?
@property (atomic, assign) BOOL isChromedPlayer;

// Social sharing IDs
/// Is social sharing enabled for this player?
@property (atomic, assign) BOOL isSocialSharingEnabled;
/// Is Twitter sharing enabled for this player?
@property (atomic, assign) BOOL isTwitterSharingEnabled;
/// Is FaceBook sharing enabled for this player?
@property (atomic, assign) BOOL isFacebookSharingEnabled;
/// Is email sharing enabled for this player?
@property (atomic, assign) BOOL isEmailSharingEnabled;
/// Flux domain information for social sharing
@property (atomic, assign) NSString *fluxAccountDomain;

/// Nielsen related parameters
@property (nonatomic, copy) NSString * nielsenClientID;
@property (nonatomic, assign) BOOL nielsenReporterEnabled;
@property (nonatomic, copy) NSString * nielsenVideoCensusID;
@property (nonatomic, copy) NSString * nielsenApplicationId;
@property (nonatomic, copy) NSString * nielsenSFcode;
@property (nonatomic, assign) BOOL nielsenDprEnabled;

// Omniture
@property (atomic, assign) BOOL omnitureAdTracking;
@property (atomic, assign) BOOL omnitureEnabled;
@property (atomic, assign) BOOL omnitureHeartbeatsDisabled;
@property (atomic, assign) BOOL omnitureLiveEventHeartbeatsDisabled;
@property (atomic, assign) BOOL omnitureMediaTracking;
@property (atomic, assign) BOOL omnitureVisitorNamespace;
@property (atomic, copy) NSString *omnitureCharacterSet;
@property (atomic, copy) NSString *omnitureDataCenter;
@property (atomic, copy) NSString *omnitureDevAccount;
@property (atomic, copy) NSString *omnitureMediaLiveEvent;
@property (atomic, copy) NSString *omnitureMediaLiveEventIDs;
@property (atomic, copy) NSString *omnitureNetworkAccount;
@property (atomic, copy) NSString *omniturePartnerAccount;
@property (atomic, copy) NSString *omniturePropertyOverrides;
@property (atomic, copy) NSString *omnitureTrackingServer;
@property (atomic, copy) NSString *omnitureViralAccount;
@property (atomic, copy) NSString *networkPlayerName;
@property (atomic, copy) NSDictionary *omnitureCustomFields;

//Akamai
@property (atomic, assign) BOOL akamaiContentTrackingEnabled;


/// Returns a dictionary parsed from the form factor id string.
/// @param theFormFactorIds String of form factor ids that will be parsed into a dictionary.
-(NSDictionary *) getDictionaryWithFormFactorIds:(NSString *) theFormFactorIds;


- (BOOL) isAirplayEnabled;

// private
- (NSString *) getPrefixFromUri;
- (void) setErrorSlateURL:(NSString *)errorSlateURL;
@end

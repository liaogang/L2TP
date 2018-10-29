//
//  NetworkExtesionPrivate.h
//  L2TP
//
//  Created by liaogang on 2018/7/6.
//  Copyright © 2018年 liaogang. All rights reserved.
//

#import <NetworkExtension/NetworkExtension.h>


typedef enum : NSUInteger {
    VPNType_IPSec = 1,
    VPNType_L2TP = 2,
} VPNType;


@class NEContentFilterPlugin;

@interface NEContentFilter : NSObject  {
    
    BOOL _enabled;
    NEContentFilterPlugin* _plugin;
    
}

@property (getter=isEnabled) BOOL enabled;                    //@synthesize enabled=_enabled - In the implementation block
@property (copy) NEContentFilterPlugin * plugin;              //@synthesize plugin=_plugin - In the implementation block
+(BOOL)supportsSecureCoding;
-(BOOL)checkValidityAndCollectErrors:(id)arg1 ;
-(id)descriptionWithIndent:(int)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)copyWithZone:(NSZone*)arg1 ;
-(void)setEnabled:(BOOL)arg1 ;
-(BOOL)isEnabled;
-(void)setPlugin:(NEContentFilterPlugin *)arg1 ;
-(NEContentFilterPlugin *)plugin;
@end



@class NEProfileIngestionPayloadInfo,NEAOVPN,NEVPNApp,NEContentFilter,NEPathController;



@interface NEVPNConnection ()

-(void)dealloc;
-(id)initWithType:(int)arg1 ;
-(void)setSession:(void*)arg1 ;
-(NEVPNManager *)manager;
-(void*)session;
-(NSDate *)connectedDate;
-(void)updateSessionInfoWithCompletionHandler:(/*^block*/id)arg1 ;
-(void)stopVPNTunnel;
-(void)newSessionWithConfigID:(id)arg1 withCompletionHandler:(/*^block*/id)arg2 ;
-(void)destroySession;
-(NEVPNManager *)weakmanager;
-(void)setWeakmanager:(NEVPNManager *)arg1 ;
-(int)sessionType;
@end



@interface NEVPN : NSObject
{
    
    BOOL _enabled;
    BOOL _onDemandEnabled;
    NSArray* _onDemandRules;
    NEVPNProtocol* _protocol;
    NSArray* _exceptionApps;
    
}

@property (copy) NSArray * exceptionApps;                               //@synthesize exceptionApps=_exceptionApps - In the implementation block
@property (getter=isEnabled) BOOL enabled;                              //@synthesize enabled=_enabled - In the implementation block
@property (getter=isOnDemandEnabled) BOOL onDemandEnabled;              //@synthesize onDemandEnabled=_onDemandEnabled - In the implementation block
@property (copy) NSArray * onDemandRules;                               //@synthesize onDemandRules=_onDemandRules - In the implementation block
@property (copy) NEVPNProtocol * protocol;                              //@synthesize protocol=_protocol - In the implementation block
+(BOOL)supportsSecureCoding;
-(void)setProtocol:(NEVPNProtocol *)arg1 ;
-(id)init;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)description;
-(void)setEnabled:(BOOL)arg1 ;
-(BOOL)isEnabled;
-(id)copyWithZone:(NSZone*)arg1 ;
-(NEVPNProtocol *)protocol;
-(BOOL)checkValidityAndCollectErrors:(id)arg1 ;
-(id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2 ;
-(id)copyLegacyDictionary;
-(id)initFromLegacyDictionary:(id)arg1 ;
-(BOOL)isOnDemandEnabled;
-(NSArray *)onDemandRules;
-(void)setOnDemandEnabled:(BOOL)arg1 ;
-(void)setOnDemandRules:(NSArray *)arg1 ;
-(id)copyProfileDictionaryWithCertificateUUID:(id)arg1 ;
-(NSArray *)exceptionApps;
-(void)setExceptionApps:(NSArray *)arg1 ;
@end



@interface NEIPv4Settings ()

@property (assign) long long configMethod;               //@synthesize configMethod=_configMethod - In the implementation block
@property (copy) NSString * router;                      //@synthesize router=_router - In the implementation block
@property (assign) BOOL overridePrimary;                 //@synthesize overridePrimary=_overridePrimary - In the implementation block
+(BOOL)supportsSecureCoding;
-(id)copyWithZone:(NSZone*)arg1 ;
-(BOOL)checkValidityAndCollectErrors:(id)arg1 ;
-(id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2 ;
-(id)copyLegacyDictionary;
-(id)initFromLegacyDictionary:(id)arg1 ;
-(long long)configMethod;
-(NSString *)router;
-(BOOL)overridePrimary;
-(void)setConfigMethod:(long long)arg1 ;
-(void)setRouter:(NSString *)arg1 ;
-(void)setOverridePrimary:(BOOL)arg1 ;
-(BOOL)hasDefaultRoute;
@end


@interface NEConfiguration : NSObject
{
    long long _grade;
    NSUUID* _identifier;
    NSString* _application;
    NSString* _name;
    NSString* _applicationName;
    NSString* _applicationIdentifier;
    NSString* _externalIdentifier;
    NEVPN* _VPN;
    NEAOVPN* _alwaysOnVPN;
    NEVPNApp* _appVPN;
    NEContentFilter* _contentFilter;
    NEProfileIngestionPayloadInfo* _payloadInfo;
    NEPathController* _pathController;
    
}

@property (readonly) NSString * pluginType;
@property (readonly) long long grade;                                      //@synthesize grade=_grade - In the implementation block
@property (readonly) NSUUID * identifier;                                  //@synthesize identifier=_identifier - In the implementation block
@property (copy) NSString * application;                                   //@synthesize application=_application - In the implementation block
@property (copy) NSString * name;                                          //@synthesize name=_name - In the implementation block
@property (copy) NSString * applicationName;                               //@synthesize applicationName=_applicationName - In the implementation block
@property (copy) NSString * applicationIdentifier;                         //@synthesize applicationIdentifier=_applicationIdentifier - In the implementation block
@property (copy) NSString * externalIdentifier;                            //@synthesize externalIdentifier=_externalIdentifier - In the implementation block
@property (copy) NEVPN * VPN;                                              //@synthesize VPN=_VPN - In the implementation block
//@property (copy) NEAOVPN * alwaysOnVPN;                                    //@synthesize alwaysOnVPN=_alwaysOnVPN - In the implementation block
//@property (copy) NEVPNApp * appVPN;                                        //@synthesize appVPN=_appVPN - In the implementation block
//@property (copy) NEContentFilter * contentFilter;                          //@synthesize contentFilter=_contentFilter - In the implementation block
//@property (copy) NEProfileIngestionPayloadInfo * payloadInfo;              //@synthesize payloadInfo=_payloadInfo - In the implementation block
//@property (copy) NEPathController * pathController;                        //@synthesize pathController=_pathController - In the implementation block
+(BOOL)supportsSecureCoding;
+(void)addError:(id)arg1 toList:(id)arg2 ;
//+(BOOL)setConfiguration:(CFDictionaryRef)arg1 forProtocol:(CFStringRef)arg2 inService:(SCNetworkServiceRef)arg3 ;
//+(CFDictionaryRef)copyConfigurationForProtocol:(CFStringRef)arg1 inService:(SCNetworkServiceRef)arg2 ;
//+(BOOL)SCServiceWithIdentifier:(id)arg1 existsInPreferences:(SCPreferencesRef)arg2 ;
//+(BOOL)removeSCServiceWithIdentifier:(id)arg1 fromPreferences:(SCPreferencesRef)arg2 ;

-(void)mySetGrade:(BOOL)grade;

+(id)configurationWithProfilePayload:(id)arg1 grade:(long long)arg2 ;
+(id)configurationWithProfilePayload:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(BOOL)isEqual:(id)arg1 ;
-(unsigned long long)hash;
-(id)description;
-(void)setName:(NSString *)arg1 ;
-(NSString *)name;
-(NSUUID *)identifier;
-(id)copyWithZone:(NSZone*)arg1 ;
-(void)setApplicationIdentifier:(NSString *)arg1 ;
-(NSString *)applicationIdentifier;
-(id)initWithIdentifier:(id)arg1 ;
-(NSString *)application;
-(void)setApplication:(NSString *)arg1 ;
-(id)initWithConfiguration:(id)arg1 ;
-(void)setApplicationName:(NSString *)arg1 ;
-(BOOL)checkValidityAndCollectErrors:(id)arg1 ;
-(NSString *)pluginType;
-(BOOL)needToUpdateKeychain;

 -(NEVPN *)VPN;
 -(NEVPNApp *)appVPN;
 -(long long)grade;
 -(NEAOVPN *)alwaysOnVPN;
 -(NEContentFilter *)contentFilter;

-(void)syncWithSystemKeychain;
-(id)generateSignature;
-(BOOL)isSupportedBySC;
//-(BOOL)applyChangesToSCServiceInPreferences:(SCPreferencesRef)arg1 ;
-(void)clearSystemKeychain;
-(NEProfileIngestionPayloadInfo *)payloadInfo;
//-(BOOL)updateFromSCService:(SCNetworkServiceRef)arg1 ;
//-(id)initFromSCService:(SCNetworkServiceRef)arg1 ;
-(void)syncWithUserKeychain;
-(void)clearUserKeychain;
-(id)initWithName:(id)arg1 grade:(long long)arg2 ;
-(void)setContentFilter:(NEContentFilter *)arg1 ;
-(void)setVPN:(NEVPN *)arg1 ;
-(void)setAppVPN:(NEVPNApp *)arg1 ;
-(void)setExternalIdentifier:(NSString *)arg1 ;
-(void)setAlwaysOnVPN:(NEAOVPN *)arg1 ;
-(void)setPayloadInfo:(NEProfileIngestionPayloadInfo *)arg1 ;
-(NEPathController *)pathController;
-(void)setPathController:(NEPathController *)arg1 ;
-(id)initWithVPNPayload:(id)arg1 configurationName:(id)arg2 grade:(long long)arg3 ;
-(id)initWithAlwaysOnVPNPayload:(id)arg1 configurationName:(id)arg2 grade:(long long)arg3 ;
-(id)initWithAppLayerVPNPayload:(id)arg1 configurationName:(id)arg2 grade:(long long)arg3 ;
-(id)initWithContentFilterPayload:(id)arg1 configurationName:(id)arg2 grade:(long long)arg3 ;
-(id)initWithPathControllerPayload:(id)arg1 configurationName:(id)arg2 grade:(long long)arg3 ;
-(id)descriptionWithOptions:(unsigned long long)arg1 ;
-(void)syncWithKeychainInDomain:(long long)arg1 ;
-(void)clearKeychainInDomain:(long long)arg1 ;
-(id)copyProfileDictionary;
-(void)copyPasswordsFromSystemKeychain;
-(BOOL)setConfigurationVPNPassword:(id)arg1 ;
-(BOOL)ingestDisconnectOptions:(id)arg1 ;
-(id)getConfigurationProtocol;
-(BOOL)ingestPPPDict:(id)arg1 ;
-(BOOL)configurePPPCommon:(id)arg1 ;
-(BOOL)configureVpnOnDemandRules:(id)arg1 ;
-(BOOL)configureL2TPWithPPPOptions:(id)arg1 ;
-(BOOL)configureIKE:(id)arg1 vpnType:(id)arg2 payloadBase:(id)arg3 vpn:(id)arg4 ;
-(BOOL)ingestPPPData:(id)arg1 vnpType:(id)arg2 ;
-(BOOL)configurePPPWithVPNOptions:(id)arg1 payloadBase:(id)arg2 ;
-(BOOL)ingestIPSecDict:(id)arg1 vpnType:(id)arg2 vpn:(id)arg3 ;
-(BOOL)configurePluginWithPayload:(id)arg1 pluginType:(id)arg2 payloadType:(id)arg3 ;
-(BOOL)configureVpnOnDemand:(id)arg1 vpnType:(id)arg2 ;
-(BOOL)ingestDNSOptions:(id)arg1 ;
-(BOOL)ingestProxyOptions:(id)arg1 ;
-(BOOL)setAppLayerVPNRuleSettings:(id)arg1 withAppIdentifier:(id)arg2 ;
-(id)configureAOVPNTunnelFromTunnelDict:(id)arg1 tunnelDict:(id)arg2 payloadBase:(id)arg3 interfaceType:(id)arg4 ;
-(BOOL)setCertificatesVPN:(id)arg1 ;
-(BOOL)setCertificatesAppVPN:(id)arg1 ;
-(BOOL)setCertificatesAOVpn:(id)arg1 ;
-(BOOL)setCertificateContentFilter:(id)arg1 ;
-(id)getPendingCertificateUUIDsInternal:(id)arg1 ;
-(id)getPendingCertificateUUIDsVPN:(id)arg1 ;
-(id)getPendingCertificateUUIDsAppVPN:(id)arg1 ;
-(id)getPendingCertificateUUIDsAOVpn:(id)arg1 ;
-(id)getPendingCertificateUUIDsContentFilter:(id)arg1 ;
-(BOOL)setConfigurationSharedSecret:(id)arg1 ;
-(BOOL)setPayloadInfoIdentityUserNameAndPassword:(id)arg1 ;
-(BOOL)setPayloadInfoIdentityProxy:(id)arg1 ;
-(BOOL)setPayloadInfoIdentityIPSecSharedSecret:(id)arg1 ;
-(BOOL)setPayloadInfoIdentityPIN:(id)arg1 ;
-(id)getCertificates;
-(id)getPendingCertificateUUIDs:(id)arg1 ;
-(id)getPendingCertificateInfo:(id)arg1 ;
-(id)getConfigurationIdentifier;
-(BOOL)setPayloadInfoIdentity:(id)arg1 ;
-(BOOL)setPayloadInfoCommon:(id)arg1 payloadOrganization:(id)arg2 ;
-(BOOL)setProfileInfo:(id)arg1 ;
-(BOOL)setAppLayerVPNUUID:(id)arg1 andSafariDomains:(id)arg2 ;
-(BOOL)setCertificates:(id)arg1 ;
-(void)updateWithConfiguration:(id)arg1 ;
-(NSString *)externalIdentifier;
-(NSString *)applicationName;
@end



@interface NEVPNManager ()

/*
 @property (copy) NEConfiguration * configuration;                       //@synthesize configuration=_configuration - In the implementation block
 @property (assign) BOOL hasLoaded;                                      //@synthesize hasLoaded=_hasLoaded - In the implementation block
 @property (copy) NSArray * onDemandRules;
 @property (getter=isOnDemandEnabled) BOOL onDemandEnabled;
 @property (copy) NSString * localizedDescription;
 @property (retain) NEVPNProtocol * protocol;
 @property (retain) NEVPNProtocol * protocolConfiguration;
 @property (readonly) NEVPNConnection * connection;                      //@synthesize connection=_connection - In the implementation block
 @property (getter=isEnabled) BOOL enabled;
 */


+(id)loadedManagers;
+(id)mapError:(id)arg1 ;
-(void)setProtocol:(NEVPNProtocol *)arg1 ;
-(id)init;
-(id)description;
-(NSString *)localizedDescription;
-(void)setEnabled:(BOOL)arg1 ;
-(BOOL)isEnabled;
-(void)setConfiguration:(NEConfiguration *)arg1 ;
-(NEConfiguration *)configuration;
-(NEVPNConnection *)connection;
-(NEVPNProtocol *)protocol;
-(void)setLocalizedDescription:(NSString *)arg1 ;
-(BOOL)hasLoaded;
-(id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2 ;
-(BOOL)isOnDemandEnabled;
-(void)setOnDemandEnabled:(BOOL)arg1 ;
-(void)setHasLoaded:(BOOL)arg1 ;
-(id)initWithGrade:(long long)arg1 connection:(id)arg2 ;
-(BOOL)isProtocolTypeValid:(long long)arg1 ;
-(void)additionalSetup;
-(NEVPNProtocol *)protocolConfiguration;
//-(void)setProtocolConfiguration:(NEVPNProtocol *)arg1 ;
@end

@class NEHelper;


@interface NEConfigurationManager : NSObject {
    
    NSString* _description;
    NEHelper* _helper;
    BOOL _hasReadPermission;
    BOOL _isVPNPublicAPI;
    BOOL _isVPNPrivateAPI;
    BOOL _isNEHelper;
    BOOL _hasVPNAPIEntitlement;
    int _changedNotifyToken;
    NSString* _pluginType;
    //NSObject*<OS_dispatch_queue> _queue;
    NSDictionary* _currentIndex;
    //NSObject*<OS_dispatch_queue> _changedQueue;
    /*^block*/id _changedHandler;
    NSMutableDictionary* _loadedIndex;
    NSMutableDictionary* _loadedConfigurations;
    NSKeyedUnarchiver* _decoder;
    long long _generation;
    NSData* _SCPreferencesSignature;
    NSUUID* _userUUID;
    NSString* _configFile;
    //id<NEConfigurationManagerDelegate> _delegate;
    long long _configurationChangeSource;
    
}

//@property (readonly) NSObject*<OS_dispatch_queue> queue;                                      //@synthesize queue=_queue - In the implementation block
@property (assign) int changedNotifyToken;                                                    //@synthesize changedNotifyToken=_changedNotifyToken - In the implementation block
@property (retain) NSDictionary * currentIndex;                                               //@synthesize currentIndex=_currentIndex - In the implementation block
//@property (retain) NSObject*<OS_dispatch_queue> changedQueue;                                 //@synthesize changedQueue=_changedQueue - In the implementation block
@property (copy) id changedHandler;                                                           //@synthesize changedHandler=_changedHandler - In the implementation block
@property (retain) NSMutableDictionary * loadedIndex;                                         //@synthesize loadedIndex=_loadedIndex - In the implementation block
@property (retain) NSMutableDictionary * loadedConfigurations;                                //@synthesize loadedConfigurations=_loadedConfigurations - In the implementation block
@property (retain) NSKeyedUnarchiver * decoder;                                               //@synthesize decoder=_decoder - In the implementation block
@property (assign) long long generation;                                                      //@synthesize generation=_generation - In the implementation block
@property (readonly) NEHelper * helper;
//@property (setter=CPreferencesSignature,retain) NSData * SCPreferencesSignature;              //@synthesize SCPreferencesSignature=_SCPreferencesSignature - In the implementation block
@property (assign) BOOL hasReadPermission;                                                    //@synthesize hasReadPermission=_hasReadPermission - In the implementation block
@property (assign) BOOL isVPNPublicAPI;                                                       //@synthesize isVPNPublicAPI=_isVPNPublicAPI - In the implementation block
@property (assign) BOOL isVPNPrivateAPI;                                                      //@synthesize isVPNPrivateAPI=_isVPNPrivateAPI - In the implementation block
@property (assign) BOOL isNEHelper;                                                           //@synthesize isNEHelper=_isNEHelper - In the implementation block
@property (assign) BOOL hasVPNAPIEntitlement;                                                 //@synthesize hasVPNAPIEntitlement=_hasVPNAPIEntitlement - In the implementation block
@property (readonly) NSUUID * userUUID;                                                       //@synthesize userUUID=_userUUID - In the implementation block
@property (nonatomic,copy) NSString * configFile;                                             //@synthesize configFile=_configFile - In the implementation block
//@property (retain) id<NEConfigurationManagerDelegate> delegate;                               //@synthesize delegate=_delegate - In the implementation block
@property (copy) id incomingMessageHandler;
@property (assign) long long configurationChangeSource;                                       //@synthesize configurationChangeSource=_configurationChangeSource - In the implementation block
@property (readonly) NSString * pluginType;                                                   //@synthesize pluginType=_pluginType - In the implementation block
+(id)sharedManager;
+(void)updateFlags:(unsigned long long*)arg1 withConfiguration:(id)arg2 ;
+(BOOL)configurationIsEnabled:(id)arg1 ;
+(long long)configuration:(id)arg1 overlapsWithOtherConfiguration:(id)arg2 ;
+(void)disableConfiguration:(id)arg1 onDemandOnly:(BOOL)arg2 ;
+(id)sharedManagerForAllUsers;
-(id)init;
//-(void)setDelegate:(id<NEConfigurationManagerDelegate>)arg1 ;
-(void)dealloc;
-(id)description;
//-(id<NEConfigurationManagerDelegate>)delegate;
-(NSDictionary *)currentIndex;
//-(NSObject*<OS_dispatch_queue>)queue;
-(void)setGeneration:(long long)arg1 ;
-(NEHelper *)helper;
-(void)setCurrentIndex:(NSDictionary *)arg1 ;
-(void)postChangeNotification;
-(id)initWithPluginType:(id)arg1 ;
-(NSString *)pluginType;
-(id)initWithUserUUID:(id)arg1 ;
-(int)changedNotifyToken;
-(NSKeyedUnarchiver *)decoder;
-(void)setIncomingMessageHandler:(id)arg1 ;
-(id)incomingMessageHandler;
-(void)sendRequest:(id)arg1 responseHandler:(/*^block*/id)arg2 ;
-(NSMutableDictionary *)loadedConfigurations;
-(void)postChangeNotificationWithGeneration:(long long)arg1 andFlags:(unsigned long long)arg2 ;
-(void)loadConfigurationsInternal:(id)arg1 withCompletionHandler:(/*^block*/id)arg2 ;
-(id)readIndexFromDiskWithError:(id*)arg1 ;
-(BOOL)hasReadPermission;
-(void)setDecoder:(NSKeyedUnarchiver *)arg1 ;
-(NSUUID *)userUUID;
-(id)filterIndexWithFilter:(id)arg1 ;
-(NSString *)configFile;
-(void)notifyChanges;
-(NSMutableDictionary *)loadedIndex;
-(void)clearLoadedConfigurationsWithIDs:(id)arg1 ;
-(id)decodeConfigurationWithIdentifier:(id)arg1 ;
-(void)didLoadConfiguration:(id)arg1 ;
-(void)registerForChangeNotifications;
-(BOOL)isVPNPublicAPI;
-(BOOL)reloadFromDisk;
-(BOOL)isNEHelper;
-(id)errorWithCode:(long long)arg1 specifics:(id)arg2 ;
//-(NSObject*<OS_dispatch_queue>)changedQueue;
-(id)changedHandler;
-(id)copyChangedConfigurationIDs:(id)arg1 ;
-(void)getCurrentIndexWithCompletionHandler:(/*^block*/id)arg1 ;
-(void)setChangedNotifyToken:(int)arg1 ;
-(void)setLoadedIndex:(NSMutableDictionary *)arg1 ;
-(void)setLoadedConfigurations:(NSMutableDictionary *)arg1 ;
-(void)didLoadConfiguration:(id)arg1 withSignature:(id)arg2 ;
-(BOOL)configurationHasChanged:(id)arg1 ;
-(void)setHasReadPermission:(BOOL)arg1 ;
-(void)setSCPreferencesSignature:(NSData *)arg1 ;
-(BOOL)resetKeychainItemsAfterProtocolChange:(id)arg1 newConfiguration:(id)arg2 ;
-(id)makeMutableCopyOfIndex:(id)arg1 ;
-(NSData *)SCPreferencesSignature;
//-(id)saveConfigurationToDisk:(id)arg1 updateSCPreferences:(SCPreferencesRef)arg2 currentSignature:(id)arg3 userUUID:(id)arg4 notifyNow:(BOOL)arg5 isUpgrade:(BOOL)arg6 ;
//-(id)removeConfigurationFromDisk:(id)arg1 updateSCPreferences:(SCPreferencesRef)arg2 ;
-(void)updateSCPreferencesSignatureOnDisk;
//-(void)setChangedQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(void)setChangedHandler:(id)arg1 ;
-(void)postGeneration;
-(void)saveConfigurationToDisk:(id)arg1 currentSignature:(id)arg2 userUUID:(id)arg3 isUpgrade:(BOOL)arg4 completionQueue:(id)arg5 completionHandler:(/*^block*/id)arg6 ;
-(void)removeConfigurationFromDisk:(id)arg1 completionQueue:(id)arg2 completionHandler:(/*^block*/id)arg3 ;
-(void)syncWithSystemConfigurationWithAppNameCallback:(/*^block*/id)arg1 completionHandler:(/*^block*/id)arg2 ;
-(void)loadIndexWithFilter:(id)arg1 completionQueue:(id)arg2 handler:(/*^block*/id)arg3 ;
-(void)loadConfigurations:(id)arg1 withFilter:(id)arg2 completionQueue:(id)arg3 completionHandler:(/*^block*/id)arg4 ;
-(void)loadConfigurationWithID:(id)arg1 withCompletionQueue:(id)arg2 handler:(/*^block*/id)arg3 ;
-(void)loadConfigurationsWithCompletionQueue:(id)arg1 handler:(/*^block*/id)arg2 ;


-(void)saveConfiguration:(id)arg1 withCompletionQueue:(id)arg2 handler:(void (^)(NSError * __nullable error))completionHandler ;


-(void)removeConfiguration:(id)arg1 withCompletionQueue:(id)arg2 handler:(void (^)(NSError * __nullable error))completionHandler;
-(void)setChangedQueue:(id)arg1 andHandler:(/*^block*/id)arg2 ;
-(void)handleFileRemovedWithCompletionHandler:(/*^block*/id)arg1 ;
//-(void)handlePluginTypesRemoved:(id)arg1 configuration:(id)arg2 vpn:(id)arg3 updateSCPreferences:(SCPreferencesRef)arg4 ;
-(void)handleApplicationsRemoved:(id)arg1 withCompletionHandler:(/*^block*/id)arg2 ;
-(void)copyIdentities:(id)arg1 fromDomain:(long long)arg2 withCompletionQueue:(id)arg3 handler:(/*^block*/id)arg4 ;
-(void)triggerLocalAuthenticationForConfigurationWithID:(id)arg1 withCompletionQueue:(id)arg2 handler:(/*^block*/id)arg3 ;
-(void)fetchClientListenerWithBundleID:(id)arg1 completionQueue:(id)arg2 handler:(/*^block*/id)arg3 ;
-(void)fetchUpgradeInfoForPluginType:(id)arg1 completionQueue:(id)arg2 handler:(/*^block*/id)arg3 ;
-(void)fetchCarrierBundleNATKeepAliveIntervalOverCell:(id)arg1 handler:(/*^block*/id)arg2 ;
-(void)setIsVPNPublicAPI:(BOOL)arg1 ;
-(BOOL)isVPNPrivateAPI;
-(void)setIsVPNPrivateAPI:(BOOL)arg1 ;
-(void)setIsNEHelper:(BOOL)arg1 ;
-(BOOL)hasVPNAPIEntitlement;
-(void)setHasVPNAPIEntitlement:(BOOL)arg1 ;
-(void)setConfigFile:(NSString *)arg1 ;
-(long long)configurationChangeSource;
-(void)setConfigurationChangeSource:(long long)arg1 ;
-(long long)generation;
@end



@interface NEVPNProtocolPPP : NEVPNProtocol {
    NEIPv4Settings * _IPv4Settings;
    NEIPv6Settings * _IPv6Settings;
    long long  _authenticationMethod;
    bool  _verboseLoggingEnabled;
}

@property (copy) NEIPv4Settings *IPv4Settings;
@property (copy) NEIPv6Settings *IPv6Settings;
@property long long authenticationMethod;
@property bool verboseLoggingEnabled;

+ (bool)supportsSecureCoding;


- (id)IPv4Settings;
- (id)IPv6Settings;
- (long long)authenticationMethod;
- (bool)checkValidityAndCollectErrors:(id)arg1;
- (id)copyLegacyDictionary;
- (id)copyWithZone:(struct _NSZone { }*)arg1;
- (id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)initFromLegacyDictionary:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithType:(long long)arg1;
- (void)setAuthenticationMethod:(long long)arg1;
- (void)setIPv4Settings:(id)arg1;
- (void)setIPv6Settings:(id)arg1;
- (bool)setServiceProtocolsInService:(struct __SCNetworkService { }*)arg1;
- (void)setVerboseLoggingEnabled:(bool)arg1;
- (bool)updateWithServiceProtocolsFromService:(struct __SCNetworkService { }*)arg1;
- (bool)verboseLoggingEnabled;

@end


@interface NEKeychainItem : NSObject
//<NEPrettyDescription, NSCopying, NSSecureCoding>
{
    NSString * _accessGroup;
    long long  _domain;
    NSString * _identifier;
    bool  _legacy;
    NEKeychainItem * _oldItem;
    NSString * _password;
    NSData * _persistentReference;
}

@property (copy) NSString *accessGroup;
@property long long domain;
@property (copy) NSString *identifier;
@property (readonly) bool legacy;
@property (copy) NEKeychainItem *oldItem;
@property (copy) NSString *password;
@property (copy) NSData *persistentReference;

+ (bool)supportsSecureCoding;

- (id)accessGroup;
- (bool)addOrUpdateWithConfiguration:(id)arg1 passwordType:(long long)arg2 accountName:(id)arg3 identifierSuffix:(id)arg4;
- (bool)copyDataFromKeychainItem:(void*)arg1 outPassword:(id*)arg2 outIdentifier:(id*)arg3 outPersistentReference:(id*)arg4;
- (id)copyKindForPasswordType:(long long)arg1;
- (id)copyPassword;
- (id)copyQueryWithReturnTypes:(id)arg1;
- (id)copyWithZone:(struct _NSZone { }*)arg1;
- (id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2;
- (long long)domain;
- (void)encodeWithCoder:(id)arg1;
- (id)identifier;
- (id)initWithCoder:(id)arg1;
- (id)initWithIdentifier:(id)arg1 domain:(long long)arg2;
- (id)initWithIdentifier:(id)arg1 domain:(long long)arg2 accessGroup:(id)arg3;
- (id)initWithLegacyIdentifier:(id)arg1 domain:(long long)arg2;
- (id)initWithLegacyIdentifier:(id)arg1 domain:(long long)arg2 accessGroup:(id)arg3;
- (id)initWithPassword:(id)arg1 domain:(long long)arg2;
- (id)initWithPassword:(id)arg1 domain:(long long)arg2 accessGroup:(id)arg3;
- (id)initWithPersistentReference:(id)arg1 domain:(long long)arg2;
- (id)initWithPersistentReference:(id)arg1 domain:(long long)arg2 accessGroup:(id)arg3;
- (bool)legacy;
- (void)migrateFromPreferences:(struct __SCPreferences { }*)arg1;
- (id)oldItem;
- (id)password;
- (id)persistentReference;
- (void)remove;
- (void)setAccessGroup:(id)arg1;
- (void)setDomain:(long long)arg1;
- (void)setIdentifier:(id)arg1;
- (void)setIdentifierInternal:(id)arg1;
- (void)setOldItem:(id)arg1;
- (void)setPassword:(id)arg1;
- (void)setPersistentReference:(id)arg1;
- (void)syncUsingConfiguration:(id)arg1 accountName:(id)arg2 passwordType:(long long)arg3 identifierSuffix:(id)arg4;

@end


@interface NEIdentityKeychainItem : NEKeychainItem

+ (id)copyIdentities:(id)arg1 fromDomain:(long long)arg2;
+ (id)copyPersistentReferenceForIdentity:(struct __SecIdentity { }*)arg1;
+ (id)copyPropertiesForIdentity:(struct __SecIdentity { }*)arg1 persistentReference:(id)arg2;
+ (id)importPKCS12Data:(id)arg1 passphrase:(id)arg2;

- (id)copyPassword;
- (id)copyQueryWithReturnTypes:(id)arg1;
- (id)copyWithZone:(struct _NSZone { }*)arg1;
- (id)initWithPassword:(id)arg1 domain:(long long)arg2 accessGroup:(id)arg3;
- (void)sync;
- (void)syncUsingConfiguration:(id)arg1 accountName:(id)arg2 passwordType:(long long)arg3 identifierSuffix:(id)arg4;

@end


@interface NEVPNProtocolL2TP : NEVPNProtocolPPP {
    NSString * _localIdentifier;
    long long  _machineAuthenticationMethod;
    //NEIdentityKeychainItem * _machineIdentity;
    bool  _machineIdentityDataImported;
    NSData * _machineIdentityDataInternal;
    //NEKeychainItem * _sharedSecretKeychainItem;
}



@property (copy) NSString *localIdentifier;
@property long long machineAuthenticationMethod;
@property (retain) NEIdentityKeychainItem *machineIdentity;
@property bool machineIdentityDataImported;
@property (copy) NSData *machineIdentityDataInternal;
@property (copy) NSData *machineIdentityReference;
@property (copy) NEKeychainItem *sharedSecretKeychainItem;
@property (copy) NSData *sharedSecretReference;

+ (bool)supportsSecureCoding;


- (bool)checkValidityAndCollectErrors:(id)arg1;
- (id)copyLegacyIPSecDictionary;
- (id)copyWithZone:(struct _NSZone { }*)arg1;
- (struct __SCNetworkInterface { }*)createInterface;
- (id)descriptionWithIndent:(int)arg1 options:(unsigned long long)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)init;
- (id)initWithCoder:(id)arg1;
- (id)localIdentifier;
- (long long)machineAuthenticationMethod;
- (id)machineIdentity;
- (bool)machineIdentityDataImported;
- (id)machineIdentityDataInternal;
- (id)machineIdentityReference;
//- (void)migratePasswordsFromPreferences:(struct __SCPreferences { }*)arg1;
- (bool)needToUpdateKeychain;
- (void)removeKeychainItemsInDomain:(long long)arg1 keepIdentity:(bool)arg2;
- (void)setIPSecSettingsFromLegacyDictionary:(id)arg1;
- (void)setLocalIdentifier:(id)arg1;
- (void)setMachineAuthenticationMethod:(long long)arg1;
- (void)setMachineIdentity:(id)arg1;
- (void)setMachineIdentityDataImported:(bool)arg1;
- (void)setMachineIdentityDataInternal:(id)arg1;
- (void)setMachineIdentityReference:(id)arg1;
//- (bool)setServiceProtocolsInService:(struct __SCNetworkService { }*)arg1;
- (void)setSharedSecretKeychainItem:(id)arg1;
- (void)setSharedSecretReference:(id)arg1;
- (id)sharedSecretKeychainItem;
- (id)sharedSecretReference;
- (void)syncWithKeychainInDomain:(long long)arg1 configuration:(id)arg2 suffix:(id)arg3;
//- (bool)updateWithServiceProtocolsFromService:(struct __SCNetworkService { }*)arg1;

@end






@interface NEVPNProtocol (my)
+(BOOL)supportsSecureCoding;
-(NSString *)serverAddress;
-(BOOL)checkValidityAndCollectErrors:(id)arg1 ;
-(id)descriptionWithIndent:(int)arg1 ;
-(void)setDisconnectOnWake:(BOOL)arg1 ;
-(id)copyLegacyDictionary;
-(void)syncWithKeychainInDomain:(long long)arg1 configuration:(id)arg2 suffix:(id)arg3 ;
-(void)removeKeychainItemsInDomain:(long long)arg1 ;

-(NEKeychainItem *)passwordKeychainItem;
-(NSString *)passwordEncryption;
-(NSData *)identityDataInternal;
-(NSString *)identityDataPassword;
-(BOOL)identityDataImported;
-(NSData *)identityDataHash;
-(NEProxySettings *)proxySettings;
-(BOOL)disconnectOnIdle;
-(int)disconnectOnIdleTimeout;
-(BOOL)disconnectOnSleep;
-(BOOL)disconnectOnWake;
-(int)disconnectOnWakeTimeout;
-(id)initWithProtocolIdentifier:(id)arg1 ;
-(void)setServerAddress:(NSString *)arg1 ;
-(void)setIdentityDataInternal:(NSData *)arg1 ;
-(void)setIdentityDataPassword:(NSString *)arg1 ;
-(void)setIdentityDataImported:(BOOL)arg1 ;
-(void)setIdentityDataHash:(NSData *)arg1 ;
-(void)setProxySettings:(NEProxySettings *)arg1 ;
-(void)setDisconnectOnIdle:(BOOL)arg1 ;
-(void)setDisconnectOnIdleTimeout:(int)arg1 ;
-(void)setDisconnectOnSleep:(BOOL)arg1 ;
-(void)setDisconnectOnWakeTimeout:(int)arg1 ;
-(void)setPasswordKeychainItem:(NEKeychainItem *)arg1 ;
-(void)setPasswordEncryption:(NSString *)arg1 ;
-(id)type2str;
-(void)addDisconnectOptions:(id)arg1 ;
-(void)initDisconnectOptions:(id)arg1 ;
-(id)initFromLegacyDictionary:(id)arg1 ;
-(long long)keychainDomain;
-(void)setIdentityReferenceInternal:(NSData *)arg1 ;
-(NSData *)identityReferenceInternal;
-(void)syncWithKeychainInDomainCommon:(long long)arg1 ;
-(void)setPasswordReference:(NSData *)arg1 ;
-(NSData *)passwordReference;
-(void)setIdentityReference:(NSData *)arg1 ;
-(NSData *)identityReference;
-(void)setIdentityData:(NSData *)arg1 ;
-(NSData *)identityData;
-(void)copyPasswordsFromKeychainInDomain:(long long)arg1 ;
-(BOOL)disconnectOnUserSwitch;
-(void)setDisconnectOnUserSwitch:(BOOL)arg1 ;
-(BOOL)disconnectOnLogout;
-(void)setDisconnectOnLogout:(BOOL)arg1 ;
-(void)setKeychainDomain:(long long)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)description;
-(NSUUID *)identifier;
-(long long)type;
-(id)copyWithZone:(NSZone*)arg1 ;
-(id)initWithType:(long long)arg1 ;
-(void)setIdentifier:(NSUUID *)arg1 ;
-(void)setUsername:(NSString *)arg1 ;
-(void)setIdentity:(NEIdentityKeychainItem *)arg1 ;
-(NEIdentityKeychainItem *)identity;
-(NSString *)username;
@end


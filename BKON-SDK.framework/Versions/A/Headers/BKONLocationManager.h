//
//  BKONLocationManager.h
//  BKON-SDK
//
//	Version: 1.0b1
//  Created by Beat Zenerino on 3/18/14.
//  Copyright (c) 2014 BKON Connect LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BKONRegion.h"

@protocol BKONLocationManagerDelegate;

/**
 * The BKONLocationManager class is used to discover beacons and query their
 * approximate distance to the iPhone. You define regions that look for specific
 * iBeacon parameters, such as UUID, major and minor and then pass those to the
 * BKONLocationManager.
 */
@interface BKONLocationManager : NSObject <CLLocationManagerDelegate>

@property (weak, nonatomic) id<BKONLocationManagerDelegate> delegate;

/**
 * Returns a boolean indicating if ranging for beacons is available.
 */
+ (BOOL)isRangingAvailable;

/**
 * Returns a boolean indicating if location services are enabled on this device.
 */
+ (BOOL)locationServicesEnabled;

/**
 * Starts monitoring for the specified region. BKONLocationManager will notify
 * your application, through the delegate method 'didEnterRegion', when the host
 * device enters the proximity of a beacon region. It will also notify your application
 * when the device leaves the proximity of a beacon region through the delegate method
 * 'didExitRegion'
 *
 * @param region a BKON region
 */
- (void)startMonitoringForRegion:(BKONRegion *)region;

/**
 * Stops monitoring for the specified region.
 *
 * @param region a BKON region
 */
- (void)stopMonitoringForRegion:(BKONRegion *)region;

/**
 * Start looking for beacons in the specified region. After calling this function the
 * BKONLocationManager will start returning any beacon it found for the region
 * through the delegate function 'didRangeBeacons'.
 *
 * @param region a BKON region
 */
- (void)startRangingBeaconsInRegion:(BKONRegion *)region;

/**
 * Stops ranging beacons in the specified region.
 *
 * @param region a BKON region
 */
- (void)stopRangingBeaconsInRegion:(BKONRegion *)region;

/**
 * Retrieves the state of a region. This will report if you are inside a region
 * through the delegate method 'didDetermineState'.
 *
 * @param region a BKON region
 */
- (void)requestStateForRegion:(BKONRegion *)region;

@end

/**
 * The BKONLocationManagerDelegate is used to listen to proximity events from the
 * BKONLocationManager.
 */
@protocol BKONLocationManagerDelegate <NSObject>

@optional

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param region a BKON region
 */
- (void)bkonManager:(BKONLocationManager *)manager didEnterRegion:(BKONRegion *)region;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param region a BKON region
 */
- (void)bkonManager:(BKONLocationManager *)manager didExitRegion:(BKONRegion *)region;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param state the state of the region
 * @param region a BKON region
 */
- (void)bkonManager:(BKONLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(BKONRegion *)region;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param region a BKON region
 * @param error the error returned
 */
- (void)bkonManager:(BKONLocationManager *)manager monitoringDidFailForRegion:(BKONRegion *)region withError:(NSError *)error;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param region a BKON region
 */
- (void)bkonManager:(BKONLocationManager *)manager didStartMonitoringForRegion:(BKONRegion *)region;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param beacons an array of BKONBeacon's within proximity of the device
 * @param region a BKON region
 */
- (void)bkonManager:(BKONLocationManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(BKONRegion *)region;

/**
 * Invoked when the device enters the proximity of a beacon.
 *
 * @param manager the BKONLocationmanager object
 * @param region a BKON region
 * @param error the error returned
 */
- (void)bkonManager:(BKONLocationManager *)manager rangingBeaconsDidFailForRegion:(BKONRegion *)region withError:(NSError *)error;

@end
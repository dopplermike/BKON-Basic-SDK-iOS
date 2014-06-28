//
//  BKONCentralManager.h
//  BKON-SDK
//
//  Created by Beat Zenerino on 6/23/14.
//  Copyright (c) 2014 BKON Connect LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BKONPeripheral.h"

@class BKONPeripheral;
@protocol BKONCentralManagerDelegate;


/**
 * The BKONCentralManager is used to discover BKON hardware and change its
 * parameters.
 */
@interface BKONCentralManager : NSObject

@property (weak, nonatomic) id<BKONCentralManagerDelegate> delegate;

/**
 * Start scanning for BKON beacons. An array of beacons is returned through
 * the 'refreshWithBeacons' delegate method.
 */
- (void)startScan;

/**
 * Stop scanning for BKON beacons.
 */
- (void)stopScan;

/**
 * Try to connect to a specific beacon. This will establish a one-to-one communication
 * channel to the beacon and allow for changing of the beacons parameters.
 *
 * @param beacon A beacon that was returned through the 'refreshWithBeacons' delegate method
 */
- (BOOL)connectToPeripheral:(BKONPeripheral *)beacon;

/**
 * Break down the communcation channel to the beacon.
 */
- (void)cancelCurrentPeripheral;

@end

/**
 * The BKONCentralManagerDelegate protocol is used to receive an array of beacons
 */
@protocol BKONCentralManagerDelegate <NSObject>

@optional
/**
 * Returns an array of beacons within proximity of the device.
 *
 * @param manager the manager
 * @param beacons an array of beacons
 */
- (void)centralManager:(BKONCentralManager *)manager refreshWithBeacons:(NSArray *)beacons;

@end
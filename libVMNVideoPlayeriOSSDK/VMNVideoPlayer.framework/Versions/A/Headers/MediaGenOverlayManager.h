//
//  MediaGenOverlayManager.h
//  VMNVideoPlayer
//
//  Created by Chris Baltzer on 2014-05-29.
//
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "MediaGenOverlay.h"
#import <BCEventEmitter.h>
#import <BCRegisteringEventEmitter.h>
#import <BCEvent.h>
#import "VMNEvent.h"
#import <BCCuePoint.h>

@class VMNPlayer;

@interface MediaGenOverlayManager : NSObject

/// The view all overlays will be added to
@property (nonatomic, strong) UIView* view;


/**
 *  Creates a new overlay manager.
 *  @param emitter The player emitter
 *  @param parentView The view to render overlays in
 */
-(instancetype)initWithEmitter:(BCRegisteringEventEmitter*)emitter withPlayer:(VMNPlayer*)player inView:(UIView*)parentView;


/**
 *  Destroys the overlay manager and all overlays it contains
 */
-(void)destroy;


/**
 *  Adds an overlay. This queues it for display, when appropriate.
 *  @param overlay The overlay to add.
 */
-(void)queueOverlay:(MediaGenOverlay*)overlay;


/**
 *  This triggers loading the overlay asset, calculating it's size and position,
 *  and adding it to the view.
 */
-(void)displayOverlay:(MediaGenOverlay*)overlay;


/**
 *  Removes an overlay from view, but does not destroy it.
 */
-(void)hideOverlay:(MediaGenOverlay*)overlay;


/**
 *  Removes an overlay from the view. This destroys the overlay.
 *  @param overlay The overlay to remove.
 */
-(void)removeOverlay:(MediaGenOverlay*)overlay;


/**
 *  Removes and destroys all overlays in the manager.
 */
-(void)removeAllOverlays;


@end

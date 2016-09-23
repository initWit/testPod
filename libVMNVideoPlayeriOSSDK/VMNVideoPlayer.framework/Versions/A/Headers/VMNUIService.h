//
//  VMNUIService.h
//  VMNVideoPlayer
//
//  Created by Keith Peters on 8/16/12.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayerConfig.h"


/// Configures the UI based on values loaded in the player config.
@interface VMNUIService : NSObject

/// The view containing the UI elements, generally the controls view.
@property (nonatomic, weak) UIView *view;


/// Designated initializer.
/// @param viewValue The view to configure.
- (id)initWithView:(UIView *)viewValue;

/// Updates the view based on the config values.
/// @param thePlayerConfig thePlayerConfig The PlayerConfig being used to configure the UI.
- (void)updateView:(PlayerConfig *)thePlayerConfig;


@end

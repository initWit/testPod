//
//  VMNSlider.h
//  Controls
//
//  Created by Keith Peters on 10/10/12.
//  Copyright (c) 2012 Keith Peters. All rights reserved.
//

#import <UIKit/UIKit.h>

/// Delegate definition for objects that respond to VMNSlider events.
@protocol VMNSliderDelegate <NSObject>

/// Called when the slider is touched before moving@deb
- (void)sliderBegan;
/// Called when the slider moves
- (void)sliderChanged;
/// Called when the slider stops moving and is released
- (void)sliderEnded;

@end


/// A slider component that shows regular and segmented progress and performs seeking for the VMNPlayer.
@interface VMNSlider : UIView
{
    UIImageView *thumb;
    UIView *track;
    UIView *segments;
    UIView *filledTrack;
    UIView *timeLabelHolder;
    UILabel *timeLabel;
    BOOL isDragging;
    __unsafe_unretained id<VMNSliderDelegate> delegate;
    float value;
    NSArray *segmentData;
}

/// The view that is the thumb button part of the slider
@property (nonatomic, retain) UIImageView *thumb;
/// The view that is the background track of the slider
@property (nonatomic, retain) UIView *track;
/// A view holding the separator bars that distinguish the different segments in segmented playlists
@property (nonatomic, retain) UIView *segments;
/// The view that shows the played portion of the background track of the slider
@property (nonatomic, retain) UIView *filledTrack;
/// The view that holds the label displaying current time.
@property (nonatomic, retain) UIView *timeLabelHolder;
/// The UILabel that displays the current time as a tooltip on the slider thumb.
@property (nonatomic, retain) UILabel *timeLabel;
/// The delegate that slider events will be sent to.
@property (nonatomic, assign) id<VMNSliderDelegate>delegate;
/// The current value (time position) of the slider, in seconds.
@property (nonatomic, assign) float value;
/// An array holding the size of each segment in a segmented playlist.
@property (nonatomic, retain) NSArray *segmentData;

+ (NSBundle *)frameworkBundle;

/// Updates the position of the thumb and the size of the filled track based on touch data.
/// @param touches The NSSet of touch data.
- (void)updateThumbAndTrack:(NSSet *)touches;

/// Creates separators on the track to respresent the segments in a segmented playlist.
/// @param segs The array of segment sizes.
- (void)createSegments:(NSArray *)segs;
/// Updates and positions the segment separators based on the sizes of segments in a segmented playlist.
- (void)updateSegments;
/// Calculates the value of the slider based on the position of the thumb, size of the slider, and segment data.
- (void)updateValue;
/// Indicates / sets whether the slider shows the thumb and allows for interactive seeking, or only shows the progress.
/// @param b Interactive mode true or false.
- (void)interactiveMode:(BOOL)b;
-(void)setRecursiveUserInteraction:(BOOL)enabled;

@end

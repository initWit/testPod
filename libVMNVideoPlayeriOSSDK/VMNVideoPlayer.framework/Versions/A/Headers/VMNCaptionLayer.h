//
//  VMNCaptionLayer.h
//  VMNSampleApp
//
//

#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
#import <MediaAccessibility/MediaAccessibility.h>

#define CAPTIONS_FONT @"Courier"
#define CAPTIONS_FONT_ITALIC @"Courier-Oblique"
#define CAPTIONS_FONT_BOLD @"Courier-Bold"
#define CAPTIONS_FONT_BOLD_ITALIC @"Courier-BoldOblique"
#define CAPTIONS_FONT_COLOR [[UIColor whiteColor] CGColor]
#define CAPTION_PADDING 2.0
#define CAPTION_FONT_DEFAULT_RATIO 0.052



@class TTElement;
@class VMNCaptionRegionLayer;

/// Core Animation Layer for displaying captions.
@interface VMNCaptionLayer : CAScrollLayer

/// The starting time of the captions.
@property (nonatomic, strong) NSString *startTime; // hh:mm:ss.milliseconds
/// The ending time of the captions.
@property (nonatomic, strong) NSString *endTime; // hh:mm:ss.milliseconds
/// The horizontal alignment of the text (left, right, center).
@property (nonatomic, strong) NSString *textAlignment;
/// The position on the display of the text (before, after).
@property (nonatomic, strong) NSString *displayAlign;
/// The justification of the text
@property (nonatomic, strong) NSString *textJustify;
/// Reference to the Core animation layer.
@property (nonatomic, strong) CALayer *captionLayer;

@property (nonatomic, assign) BOOL iOSVerLessThan7;

// private....
@property (nonatomic, strong) VMNCaptionRegionLayer *textRegion;
@property (nonatomic, strong) TTElement *captionsObj;
@property (nonatomic, strong) NSMutableArray *previousLayers;



/// Convenience constructor. Returns VMNCaptionLayer.
/// @param element The TTElement for the regions.
/// @param regions A dictionary of caption regions.
+(id)layerWithCaptionElement:(TTElement *)element regions:(NSDictionary *)regions iOSVerLessThan7:(BOOL)iOSVerLessThan7;


// private...
-(void)buildCaptions: (float) playerVerticalHeigth
     backgroundColor:(UIColor *) theBackgroundColor
           fontColor:(UIColor *)theFontColor
                font:(UIFont *) theUIFont
       textEdgeStyle:(MACaptionAppearanceTextEdgeStyle) theTextEdgeStyle
windowBackgroundColor :(UIColor *) theWindowBackgroundColor;


@end

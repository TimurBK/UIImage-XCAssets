//
//  UIImage+AssetLaunchImage.m
//  UIImage+AssetLaunchImage
//
//  Created by Timur Kuchkarov on 25.11.14.
//  Released under MIT license.
//

#import "UIImage+AssetLaunchImage.h"

// Thanks to http://stackoverflow.com/a/20045142/2082172
// This category supports only iOS 7+, although it should be easy to add 6- support.

static NSString * const kAssetImageBaseFileName							= @"LaunchImage";

// Asset catalog part

static CGFloat const kAssetImage4inchHeight								= 568.;
static CGFloat const kAssetImage35inchHeight							= 480.;
static CGFloat const kAssetImage6PlusScale								= 3.;

static NSString * const kAssetImageiOS8Prefix							= @"-800";
static NSString * const kAssetImageiOS7Prefix							= @"-700";
static NSString * const kAssetImagePortraitString						= @"-Portrait";
static NSString * const kAssetImageLandscapeString						= @"-Landscape";
static NSString * const kAssetImageiPadPostfix							= @"~ipad";
static NSString * const kAssetImageHeightFormatString					= @"-%.0fh";
static NSString * const kAssetImageScaleFormatString					= @"@%.0fx";

// IB based part
static NSString * const kAssetImageLandscapeLeftString					= @"-LandscapeLeft";
static NSString * const kAssetImagePathToFileFormatString				= @"~/Library/Caches/LaunchImages/%@/%@";
static NSString * const kAssetImageSizeFormatString						= @"{%.0f,%.0f}";


@implementation UIImage (AssetLaunchImage)

+ (UIImage *)assetLaunchImageWithOrientation:(UIInterfaceOrientation)orientation useSystemCache:(BOOL)cache
{
	UIScreen *screen = [UIScreen mainScreen];
	CGFloat screenHeight = screen.bounds.size.height;
	if ([screen respondsToSelector:@selector(convertRect:toCoordinateSpace:)]) {
		screenHeight = [screen.coordinateSpace convertRect:screen.bounds toCoordinateSpace:screen.fixedCoordinateSpace].size.height;
	}
	CGFloat scale = screen.scale;
	BOOL portrait = UIInterfaceOrientationIsPortrait(orientation);
	BOOL isiPhone = ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone);
	BOOL isiPad = ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad);
	NSMutableString *imageNameString = [NSMutableString stringWithString:kAssetImageBaseFileName];
	if (isiPhone && screenHeight > kAssetImage4inchHeight) { // currently here will be launch images for iPhone 6 and 6 plus
		[imageNameString appendString:kAssetImageiOS8Prefix];
	} else {
		[imageNameString appendString:kAssetImageiOS7Prefix];
	}
	if (scale >= kAssetImage6PlusScale || isiPad) {
		NSString *orientationString = portrait ? kAssetImagePortraitString : kAssetImageLandscapeString;
		[imageNameString appendString:orientationString];
	}
	
	if (isiPhone && screenHeight > kAssetImage35inchHeight) {
		[imageNameString appendFormat:kAssetImageHeightFormatString, screenHeight];
	}
	if (scale > 1) {
		[imageNameString appendFormat:kAssetImageScaleFormatString, scale];
	}
	if (isiPad) {
		[imageNameString appendString:kAssetImageiPadPostfix];
	}
	if (cache) {
		return [UIImage imageNamed:imageNameString];
	} else {
		return [UIImage imageWithContentsOfFile:imageNameString];
	}
}

+ (UIImage *)interfaceBuilderBasedLaunchImageWithOrientation:(UIInterfaceOrientation)orientation useSystemCache:(BOOL)cache
{
	UIScreen *screen = [UIScreen mainScreen];
	CGFloat screenHeight = screen.bounds.size.height;
	CGFloat screenWidth = screen.bounds.size.width;
	BOOL portrait = UIInterfaceOrientationIsPortrait(orientation);
	if ( (screenHeight > screenWidth && !portrait) || (screenWidth > screenHeight && portrait)) {
		CGFloat temp = screenWidth;
		screenWidth = screenHeight;
		screenHeight = temp;
	}
	NSMutableString *imageNameString = [NSMutableString stringWithString:kAssetImageBaseFileName];
	NSString *orientationString = portrait ? kAssetImagePortraitString : kAssetImageLandscapeLeftString;
	[imageNameString appendString:orientationString];
	
	[imageNameString appendFormat:kAssetImageSizeFormatString, screenWidth, screenHeight];
	NSString *bundleID = [[NSBundle mainBundle] bundleIdentifier];
	NSString *pathToFile = [[NSString stringWithFormat:kAssetImagePathToFileFormatString, bundleID, imageNameString] stringByExpandingTildeInPath];
	if (cache) {
		return [UIImage imageNamed:pathToFile];
	} else {
		return [UIImage imageWithContentsOfFile:pathToFile];
	}
}

+ (UIImage *)interfaceBuilderBasedLaunchImage
{
	UIInterfaceOrientation statusBarOrientation = [[UIApplication sharedApplication] statusBarOrientation];
	return [UIImage interfaceBuilderBasedLaunchImageWithOrientation:statusBarOrientation useSystemCache:YES];
}

+ (UIImage *)assetLaunchImage
{
	UIInterfaceOrientation statusBarOrientation = [[UIApplication sharedApplication] statusBarOrientation];
	return [UIImage assetLaunchImageWithOrientation:statusBarOrientation useSystemCache:YES];
}


+ (UIImage *)assetLaunchImageWithSize:(CGSize)size useSystemCache:(BOOL)cache
{
	UIInterfaceOrientation orientation = (size.height > size.width) ? UIInterfaceOrientationPortrait: UIInterfaceOrientationLandscapeLeft;
	return [UIImage assetLaunchImageWithOrientation:orientation useSystemCache:cache];
}

+ (UIImage *)interfaceBuilderBasedLaunchImageWithSize:(CGSize)size useSystemCache:(BOOL)cache
{
	UIInterfaceOrientation orientation = (size.height > size.width) ? UIInterfaceOrientationPortrait: UIInterfaceOrientationLandscapeLeft;
	return [UIImage interfaceBuilderBasedLaunchImageWithOrientation:orientation useSystemCache:cache];
}

@end

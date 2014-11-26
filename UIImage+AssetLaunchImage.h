//
//  UIImage+AssetLaunchImage.h
//  UIImage+AssetLaunchImage
//
//  Created by Timur Kuchkarov on 25.11.14.
//  Released under MIT license.
//

#import <UIKit/UIKit.h>

@interface UIImage (AssetLaunchImage)

/**
 *	Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method.
 *  App should use Asset catalog or this method may return nil.
 *
 *  @return Launch image with current status bar orientation.
 */
+ (UIImage *)assetLaunchImage;

/**
 *  Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method.
 *  App should use IB based launch image or this method may return nil.
 *
 *  @return Launch image with current status bar orientation.
 */
+ (UIImage *)interfaceBuilderBasedLaunchImage;

/**
 *  Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method if cache is YES
 *  or via @code [UIImage imageWithContentsOfFile:] @endcode if cache is NO.
 *  App should use IB based launch image or this method may return nil.
 *
 *  @param orientation Image orientation to find.
 *  @param cache       If image should be cached by system means.
 *
 *  @return Launch image with passed orientation.
 */
+ (UIImage *)interfaceBuilderBasedLaunchImageWithOrientation:(UIInterfaceOrientation)orientation useSystemCache:(BOOL)cache;

/**
 *  Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method if cache is YES
 *  or via @code [UIImage imageWithContentsOfFile:] @endcode if cache is NO.
 *  App should use Asset catalog or this method may return nil.
 *
 *  @param orientation Image orientation to find.
 *  @param cache       If image should be cached by system means.
 *
 *  @return Launch image with passed orientation.
 */
+ (UIImage *)assetLaunchImageWithOrientation:(UIInterfaceOrientation)orientation useSystemCache:(BOOL)cache;

/**
 *  Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method if cache is YES
 *  or via @code [UIImage imageWithContentsOfFile:] @endcode if cache is NO
 *  App should use Asset catalog or this method may return nil.
 *  This method is useful for iOS 8 rotation methods where we get size app will transition to.
 *
 *  @param size  Size used to determine image orientation (if height > width - portrait, landscape left otherwise).
 *  @param cache If image should be cached by system means.
 *
 *  @return Launch image with constructed orientation.
 */
+ (UIImage *)assetLaunchImageWithSize:(CGSize)size useSystemCache:(BOOL)cache;

/**
 *  Constructs launch image name and returns it via @code [UIImage imageNamed:] @endcode method if cache is YES
 *  or via @code [UIImage imageWithContentsOfFile:] @endcode if cache is NO.
 *  App should use Asset catalog or this method may return nil.
 *  This method is useful for iOS 8 rotation methods where we get size app will transition to.
 *
 *  @param size  Size used to determine image orientation (if height > width - portrait, landscape left otherwise).
 *  @param cache If image should be cached by system means.
 *
 *  @return Launch image with constructed orientation.
 */
+ (UIImage *)interfaceBuilderBasedLaunchImageWithSize:(CGSize)size useSystemCache:(BOOL)cache;

@end

//
//  UIImage+AssetLaunchImage.h
//  PaymentApp
//
//  Created by Timur Kuchkarov on 25.11.14.
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Timur Kuchkarov, i-2K
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
+ (UIImage *)interfaceBuilderBasedLaunchImageWithOrientation:(UIInterfaceOrientation)orientation
											  useSystemCache:(BOOL)cache;

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

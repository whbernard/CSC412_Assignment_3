//
// Created by William Bernard on 10/10/18.
//

#ifndef CSC412_ASSIGNMENT_3_COMPAREIMAGES_H
#define CSC412_ASSIGNMENT_3_COMPAREIMAGES_H

#include "rotate.h"
#include <stdbool.h>

/**	This function checks to see if image1 and image2 are the same, even if image2 is rotated in a different
 *  orientation (90 degrees, 180 degrees, or 270 degrees). Returns 1 if they are the same, 0 if not.
 *	@param	image1	image1 remains in same position
 *	@param	image2  image2 is rotated in all possible configurations, then checked to see
 *	                if it's the same as image1
 *	@param	type	one of RGBA32_RASTER, GRAY_RASTER, or FLOAT_RASTER
 *	@param	wordSizeRowPadding word size at which rows should be rounded up.
 *			You should use a padding size of 4 for a GRAY_RASTER raster
 *			if you intend to use OpenGL to render the image.
 */
bool compareImages(const ImageStruct * image1, ImageStruct * image2);

/**	This is really a helper function for compareImages(). areAllPixelsEqual() performs the actual
 *  pixel-wise comparison. However, compareImages() rotates the images, *then* calls areAllPixelsEqual().
 *
 *	@param	image1	image for image comparison
 *	@param	image2  image for image comparison -- this image is *not* rotated. If the image is in the a different
 *	                orientation, but it's the same image, it will return 0. If the images are in the same orientation,
 *	                and the same image, then this function will return 1.
 */
bool areAllPixelsEqual(const ImageStruct * image1, const ImageStruct * image2);


#endif //CSC412_ASSIGNMENT_3_COMPAREIMAGES_H

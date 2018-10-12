//
//  rotate
//  Prog 02 Solution
//
//  Created by Jean-Yves HervÃ© on 2018-10-03.
//
//
#include "rotate.h"

#if 0
#pragma mark -
#pragma mark Function implementations
#endif

ImageStruct rotateImage90(const ImageStruct* image)
{
    ImageStruct outImage = newImage(image->height, image->width, RGBA32_RASTER, 4);
    const int* rasterIn = (int*)(image->raster);
    int* rasterOut = (int*)(outImage.raster);
    
    for (unsigned i=0; i<image->height; i++)
    {
        for (unsigned j=0; j<image->width; j++)
            rasterOut[(outImage.height-j-1)*outImage.width + i] =
            rasterIn[i*image->width + j];
    }
    
    return outImage;
}

//    In a rotation by 180 degree clockwise, the pixel at row i, col j in the input image
//    ends up at row height - i - 1, col weight - j in the output image
ImageStruct rotateImage180(const ImageStruct* image)
{
    ImageStruct outImage = newImage(image->width, image->height, RGBA32_RASTER, 4);
    
    const int* rasterIn = (int*)(image->raster);
    int* rasterOut = (int*)(outImage.raster);
    
    for (unsigned i=0; i<image->height; i++)
    {
        for (unsigned j=0; j<image->width; j++)
            rasterOut[(outImage.height-i-1)*outImage.width + outImage.width - j -1] =
            rasterIn[i*image->width + j];
    }
    
    return outImage;
}

//    In a rotation by 270 degree clockwise, the pixel at row i, col j in the input image
//    ends up at row j, col outWidth - i - 1 in the output image
ImageStruct rotateImage270(const ImageStruct* image)
{
    ImageStruct outImage = newImage(image->height, image->width, RGBA32_RASTER, 4);
    const int* rasterIn = (int*)(image->raster);
    int* rasterOut = (int*)(outImage.raster);
    
    for (unsigned i=0; i<image->height; i++)
    {
        for (unsigned j=0; j<image->width; j++)
            rasterOut[j*outImage.width + outImage.width - i - 1] =
            rasterIn[i*image->width + j];
    }
    
    return outImage;
}

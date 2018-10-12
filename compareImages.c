#include "compareImages.h"

bool compareImages(const ImageStruct * image1, ImageStruct * image2) {

    // Compare the images as they are now perform we perform the rotation
    if (areAllPixelsEqual(image1, image2)) {
        return true;
    }

    // If the first check failed, beginning comparing the images after each rotation
    ImageStruct image90  = rotateImage90(image2);
    ImageStruct image180 = rotateImage180(image2);
    ImageStruct image270 = rotateImage270(image2);

    return areAllPixelsEqual(image1, &image90)  ||
           areAllPixelsEqual(image1, &image180) ||
           areAllPixelsEqual(image1, &image270);

}

bool areAllPixelsEqual(const ImageStruct * image1, const ImageStruct * image2) {
    const int *rasterImage1 = (int *) (image1->raster);
    const int *rasterImage2 = (int *) (image2->raster);

    // Let's do a quick dimension check. If the dimensions aren't
    // the same, we have no need to iterate through the loop -- we already
    // know for fact that the images aren't the same
    if (image1->height != image2->height) {
        return false;
    }

    if (image1->width  != image2->width) {
        return false;
    }

    for (unsigned i = 0; i < image1->height; i++) {
        for (unsigned j = 0; j < image1->width; j++) {


            // Now, we can check pixel per pixel. Once two pixels are found not to be equal, immediately return. There's
            // not point to continue searching.
            if (rasterImage1[i*image1->width + j] != rasterImage2[i*image2->width + j]) {
                return false;
            }

        }
    }
    return true;
}


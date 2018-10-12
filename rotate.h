//
// Created by William Bernard on 10/9/18.
//

#ifndef CSC412_ASSIGNMENT_3_ROTATE_H
#define CSC412_ASSIGNMENT_3_ROTATE_H

//
//  rotate
//  Prog 02 Solution
//
//  Created by Jean-Yves HervÃ© on 2018-10-03.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
#include "imageIO_TGA.h"
#include "rasterImage.h"

#if 0
#pragma mark -
#pragma mark Custom data types and global variables
#endif

/**    Simple enum type to report optional arguments for the program
 */
//typedef enum RotationVal
//{
//    NO_ROTATION = 0,
//    ROTATE_90,
//    ROTATE_180,
//    ROTATE_270,
//    //
//            NUM_ROTATIONS    //    automatically 4
//
//} RotationVal;
//
///**    An array to store the suffix strings for the output file, for each
// *    rotation value.
// */
//const char* ROT_SUFFIX[NUM_ROTATIONS] = {
//        "",
//        " [r]",
//        " [rr]",
//        " [l]"
//};
//
///**    An enum type for all the errors that this program specifically handles
// */
//typedef enum ErrorCode
//{
//    NO_ERROR = 0,
//    //
//    //    //    file-related    -->    Not used in this application
//    //    FILE_NOT_FOUND,
//    //    CANNOT_OPEN_FILE,
//    //    WRONG_FILE_TYPE,
//    //    CANNOT_WRITE_FILE,
//    //
//    //    command line argument errors
//            WRONG_NUMBER_OF_ARGUMENTS,
//    NO_DASH_ON_ROT_STRING,
//    INVALID_ROT_STRING,
//    //
//            NUM_ERROR_CODES        //    correct value because I don't skip codes
//
//} ErrorCode;
//
///**    Going overly cute here:  Error message for each of the errors
// *    supported.  This one is tricky because it's easy to get the order
// *    different from that of the enum type
// */
//const char* ERROR_STR[NUM_ERROR_CODES] = {
//        "",        //    NO_ERROR
//        //    //    file-related errors
//        //    "",    //    FILE_NOT_FOUND,
//        //    "",    //    CANNOT_OPEN_FILE,
//        //    "",    //    WRONG_FILE_TYPE,
//        //    "",    //    CANNOT_WRITE_FILE,
//        //    command line argument errors
//        "Incorrect number of arguments.\nProper usage: rotate -{r|l}+ inputImagePath outFolderPath\n",    //    WRONG_NUMBER_OF_ARGUMENTS
//        "Rotation specification must start with a dash",    //    NO_DASH_ON_ROT_STRING,
//        "Rotation specification can only contain letters l or r"    //    INVALID_ROT_STRING,
//};
//
//#if 0
//#pragma mark -
//#pragma mark Function prototypes
//#endif
//
///**    Processes the rotation-specifying string to determine the
// *    rotation to apply.
// *    @param    rotStr    the rotation-specifying string in the form -[r|l]+
// *    @param    rotVal    pointer to a RotationVal enum variable
// *    @return    an error code
// */
//ErrorCode determineRotation(const char* rotStr, RotationVal* rotVal);
//
///**    In this app, just prints out an error message to the console and
// *    exits with the proper error code.  In a fancier version, could
// *    write to a log and "swallow" some non-critical errors.
// *
// *    @param code        the code of the error to report/process
// *    @param input    the input string that caused the error (NULL otherwise)
// */
//void errorReport(ErrorCode code, const char* input);
//
///**    Produces a complete path to the output image file.
// *    If the input file path was ../../Images/clown and the 90-degree-rotated is to be
// *    written the output folder path is ../Output [with or without final slash),
// *    then the output file path will be ../Output/clown [r].tga
// *
// *    @param inputImagePath    path to the input image
// *    @param outFolderPath    path to the output folder
// *    @param rotVal            the rotation applied
// *    @return    complete path to the desired output file.
// */
//char* produceOutFilePath(const char* inputImagePath, const char* outFolderPath,
//                         RotationVal rotVal);


/**    Produces a copy of the input image (rotation by 0).
 *    This function currently only works for RGBA32_RASTER images.
 *    @param  image    pointer to the RGBA32_RASTER image to copy
 *    @return    a new image struct that stores a copy of the input image
 */
ImageStruct copyImage(const ImageStruct* image);

/**    Produces a rotated copy of the input image (rotated by 90 degree clockwise).
 *    This function currently only works for RGBA32_RASTER images.
 *    @param    image    pointer to the RGBA32_RASTER image to rotate
 *    @return    a new image struct that stores the rotated image
 */
ImageStruct rotateImage90(const ImageStruct* image);

/**    Produces a rotated copy of the input image (rotated by 180 degree clockwise).
 *    This function currently only works for RGBA32_RASTER images.
 *    @param    image    pointer to the RGBA32_RASTER image to rotate
 *    @return    a new image struct that stores the rotated image
 */
ImageStruct rotateImage180(const ImageStruct* image);

/**    Produces a rotated copy of the input image (rotated by 270 degree clockwise).
 *    This function currently only works for RGBA32_RASTER images.
 *    @param    image    pointer to the RGBA32_RASTER image to rotate
 *    @return    a new image struct that stores the rotated image
 */
ImageStruct rotateImage270(const ImageStruct* image);


#if 0
#pragma mark -
#pragma mark Function implementations
#endif


#endif //CSC412_ASSIGNMENT_3_ROTATE_H

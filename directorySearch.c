//
// Created by William Bernard on 10/10/18.
//

#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "compareImages.h"

/** This function performs a recursive search for all .tga files in a root directory. It compares these images to .tga
 *  images in the "source" directory, which is simply a directory containing some .tga files. No recursive search is
 *  performed on the "source" direct
 * @param sourceDirectoryPath - path which contains .tga files to compare to
 * @param rootPath - looks for all images recursively from a root path, and finding all .tga files within - once they
 *                   are found, the function performs a comparison.
 */
void recursiveDirectoryComparison(const char *sourceDirectoryPath, const char *rootPath);

const char * CURRENT_DIRECTORY = ".";
const char * ABOVE_DIRECTORY   = "..";

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid arguments.\nUsage: directorySearch <sourceDirectory> <rootDirectory>. Complete paths with '/'");
    }

    char *sourceDirectoryPath = argv[1];
    char *rootPath = argv[2];

    recursiveDirectoryComparison(sourceDirectoryPath, rootPath);
    return 0;

}

/** Utility function: get the root directory of the path (aka, the last directory in the path)
 * @param path - path to get root directory of
 * @return rootDir
 */
char * getRootDir(const char *path) {
    // Perform "strrchr" to do the same as "strchr," but in reverse. This will give the root directory
    // of the path.
    char * rootDir = strrchr(path, '/');
    return rootDir;

}

/** Utility function: creates a new path from a parent path and directory name.
 * @param path - parent path
 * @param newRootDir - directory name to add to path
 * @return new path
 */
char * makeNewDirectoryPath(const char *path, const char *newRootDir) {
    char * newPath = malloc(strlen(path) + strlen(newRootDir) + 1 + 1); // for '/' and '/0'
    strcpy(newPath, path);
    strcat(newPath, newRootDir);
    strcat(newPath, "/");
    return newPath;
}

/**
 * Utility function: similar to makeNewDirectoryPath, but instead add a filename at the end.
 * @param path - parent path
 * @param fileName - filename to add
 * @return new path
 */
char * makeNewFilePath(const char *path, const char *fileName) {
    char * newPath = malloc(strlen(path) + strlen(fileName) + 1); // for '/' and '/0'
    strcpy(newPath, path);
    strcat(newPath, fileName);
    return newPath;
}


void recursiveDirectoryComparison(const char *sourceDirectoryPath, const char *rootPath) {
    struct dirent *rootDE;
    DIR *rootDir = opendir(rootPath);

    if (!rootDir) {
        return;
    }

    while ((rootDE = readdir(rootDir)) != NULL) {
        if (rootDE->d_type == DT_DIR) {
            int isCurrentDirectory = strcmp(rootDE->d_name, CURRENT_DIRECTORY);
            int isAboveDirectory = strcmp(rootDE->d_name, ABOVE_DIRECTORY);

            if (isCurrentDirectory != 0 & isAboveDirectory != 0) {

                char *rootDir = getRootDir(rootPath);

                if (rootDir != NULL) {
                    char *newPath = makeNewDirectoryPath(rootPath, rootDE->d_name);
                    //printf ("%s\n", newPath);
                    recursiveDirectoryComparison(sourceDirectoryPath, newPath);
                    free(newPath);
                }
            }
        }

        if (rootDE->d_type == DT_REG) {
            char * newPath = makeNewFilePath(rootPath, rootDE->d_name);
            const char * fileExtention = strrchr(rootDE->d_name, '.');
            if (strcmp(fileExtention, ".tga") == 0) {
                struct dirent *sourceDE;
                DIR *sourceDir = opendir(sourceDirectoryPath);

                if (!sourceDir) {
                    return;
                }

                while ((sourceDE = readdir(sourceDir)) != NULL) {
                    if (sourceDE->d_type == DT_REG) {
                        char * sourcePath = makeNewFilePath(sourceDirectoryPath, sourceDE->d_name);
                        ImageStruct sourceImage = readTGA(sourcePath);
                        ImageStruct searchedImage = readTGA(newPath);
                        bool result = compareImages(&sourceImage, &searchedImage);
                        if (result) {
                            printf("%s and %s are the same\n", sourcePath, newPath);
                        }
                    }
                }
            }
            free(newPath);
        }
    }
    closedir(rootDir);
}

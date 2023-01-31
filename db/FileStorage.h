#ifndef SCHC_CONTRIBUTION_FILESTORAGE_H
#define SCHC_CONTRIBUTION_FILESTORAGE_H
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <direct.h>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>
#include <iostream>
#include <stdio.h>

namespace fs = std::filesystem;
using namespace std;

class FileStorage {
public:
    char* ROOT;

    /*Constructor */
    explicit FileStorage(char *root);

    /**
     * Join two path
     * @param path
     * @return path
     */
    char * joinPath (char * path );

    /**
     * return file size
     * @return file size
     */
    int fileSize(char* path);

    /**
     * Reads a file and returns its content as a char
     * @param path
     * @return char with file content
     */
    char* readFile(char *path);

    /**
     * Writes a string into a file
     * @param data
     */
    void writeFile( char * path, char * data);

    /**
     * Delete a file
     * @param path
     */
    void deleteFile(char * path);

    /**
     * list files and directories of path
     * @param path
     * @return
     */
    vector<char*> listFiles(char * path);

    /**
     * delete a folder
     * @param path
     */
    void deleteFolder(char*path);

    /**
     * create a folder
     * @param path
     */
    void createFolder(char * path);

    /**
     * return true if a folder exists
     * @param path
     * @return true or false
     */
    bool folderExists(char * path);

    /**
     * return true if a file exists
     * @param path
     * @return true or false
     */
    bool fileExists(char * path);

    /**
     * return true if the path is a folder
     * @param path
     * @return true or false
     */
    bool isFolder(char * path);

    /**
     * return true if the past is a file
     * @param path
     * @return true or false
     */
    bool isFile(char * path);

    /**
     * Checks if a file exists and is empty.
     * @param path
     * @return
     */
    bool emptyFile(char *path);

    /**
     * Checks if a folder exists and is empty
     * @param path
     * @return
     */
    bool emptyFolder(char *path);

};

#endif //SCHC_CONTRIBUTION_FILESTORAGE_H

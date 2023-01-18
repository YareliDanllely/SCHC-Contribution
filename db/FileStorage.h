//
// Created by Usuario on 16-01-2023.
//

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

    explicit FileStorage(char *root) : ROOT(root) {}

    /**
     * Join two path
     * @param path
     * @return path
     */
    virtual char * joinPath (char * path ) {

        if (strcmp(ROOT,"\0")==0){
            return path;
        }

        else if (strcmp(path,"\0")==0){
            return ROOT;
        }

        else {
            int sizeRoot = strlen(ROOT);
            int sizePath = strlen(path);
            char join[sizeRoot + sizePath + 1];
            char *finalJoin = (char *) ::malloc(sizeRoot + sizePath + 1);
            char *pJoin = join;
            char *pRoot = ROOT;
            char *pPath = path;

            for (int i = 0; i <= sizeRoot; i++) {
                if (i == sizeRoot) {
                    *pJoin = '\\';
                } else {
                    *pJoin = *pRoot;
                }
                pJoin++;
                pRoot++;
            }

            for (int i = 0; i < sizePath; i++) {
                *pJoin = *pPath;
                pJoin++;
                pPath++;
            }
            *pJoin = '\0';

            strcpy(finalJoin, join);

            return finalJoin;
        }


    }


    /**
     * return file size
     * @return file size
     */
    virtual int fileSize(char* path) {
        ::FILE * fp = ::fopen(joinPath(path), "r");
        ::fseek(fp,1,SEEK_END);
        int size = ::ftell(fp)-1;
        ::fseek(fp,0,SEEK_SET);
        ::fclose(fp);

        return size;

    }

    /**
     * Reads a file and returns its content as a char
     * @param path
     * @return char with file content
     */
    virtual char* readFile(char *path){
        ::FILE * fp = ::fopen(joinPath(path), "r");

        if (fp==NULL){
            cout << "error"<< endl;
        }

        int size = fileSize(path);

        char buff[size+1];
        ::fread(buff,1,size,fp);
        char *pointer = buff;
        pointer +=size;
        *pointer = '\0';

        char * final = (char*) malloc(size+1);
        strcpy(final,buff);

        ::fclose(fp);
        return final;


    }

    /**
     * Writes a string into a file
     * @param data
     */
    virtual void writeFile( char * path, char * data){
        ::FILE * fp = ::fopen(joinPath(path), "w");
        ::fwrite(data, strlen(data),1,fp);
        ::fclose(fp);

    }

    /**
     * Delete a file
     * @param path
     */
    virtual void deleteFile(char * path) {
        int result = ::remove(joinPath(path));
        (result ==0 ? cout<< "successfully deleted" << endl:cout << "error" );

    }

    /**
     * list files and directories of path
     * @param path
     * @return
     */

   virtual vector<char*> listFiles(char * path) {
        vector<char*> result;
        if (folderExists(joinPath(path))) {
            for (const auto &file: fs::directory_iterator(joinPath(path))) {
                char *pathResult = (char *) ::malloc(file.path().string().size() + 1);
                strcpy(pathResult, &file.path().string()[0]);
                result.push_back(pathResult);
            }
        }

        return result;

    }

    /**
     * delete a folder
     * @param path
     */

    virtual void deleteFolder(char*path){
        if (folderExists(path)) {
            for (const auto & file : fs::directory_iterator(joinPath(path))) {
                cout << file.path() <<endl;
                char * pathResult = (char *)::malloc(file.path().string().size()- (strlen(ROOT)+1));
                strcpy(pathResult,&file.path().string()[strlen(ROOT)+1]);

                if (isFile(pathResult)){
                    deleteFile(pathResult);
                    cout << "delete file" << endl;
                }
                else if (isFolder(pathResult)){
                    deleteFolder(pathResult);
                }
            }

        }
        rmdir(joinPath(path));
    }

    /**
     * create a folder
     * @param path
     */

    virtual void createFolder(char * path){

        if ( not folderExists(joinPath(path))) {
            if (strcmp(path,"\0")==0){
                bool result = fs::create_directories(joinPath(ROOT));
                (result == false ? cout << "Error" << endl : cout << "File created" << endl);
            }
            else {
                bool result = fs::create_directories(joinPath(path));
                (result == false ? cout << "Error" << endl : cout << "File created" << endl);

            }
        }
    }


    /**
     * return true if a folder exists
     * @param path
     * @return true or false
     */
    virtual bool folderExists(char * path){
        struct stat sb;
        bool finalResult;
        int result = stat(joinPath(path), &sb);
        (result == 0 ? finalResult = true : finalResult = false);
        return finalResult;
    }

    /**
     * return true if a file exists
     * @param path
     * @return true or false
     */
    virtual bool fileExists(char * path) {
        ::FILE * fp;
        bool result;
        (::fopen(joinPath(path), "r") ? result = true : result=false);
        return result;
    }

    /**
     * return true if the path is a folder
     * @param path
     * @return true or false
     */
    virtual bool isFolder(char * path) {
        struct stat s;
        bool result;
        if ( stat(joinPath(path), &s) ==0){
            (s.st_mode & S_IFDIR ? result = true : result = false);
        }
        else {
            result=false;
        }
        return result;
    }

    /**
     * return true if the past is a file
     * @param path
     * @return true or false
     */
    virtual bool isFile(char * path) {
        struct stat s;
        bool result;
        if ( stat(joinPath(path), &s) ==0){
            (s.st_mode & S_IFREG ? result = true : result =false);
        }
        else {
            result= false;
        }
        return result;

    }

};


#endif //SCHC_CONTRIBUTION_FILESTORAGE_H

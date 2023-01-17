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
     * return file size
     * @return
     */
    virtual int fileSize() {
        ::FILE * fp = ::fopen(ROOT, "r");
        ::fseek(fp,1,SEEK_END);
        int size = ::ftell(fp);
        ::fseek(fp,0,SEEK_SET);
        ::fclose(fp);

        return size;

    }

    /**
     * Reads a file and returns its content as a char
     * @param path
     * @return char with file content
     */
    virtual char* readFile(){
        ::FILE * fp = ::fopen(ROOT, "r");

        if (fp==NULL){
            cout << "error"<< endl;
        }

        int size = fileSize();

        char buff[size];
        ::fread(buff,1,size,fp);

        char * final = (char*) malloc(size);
        strcpy(final,buff);

        ::fclose(fp);
        return final;


    }

    /**
     * Writes a string into a file
     * @param data
     */
    virtual void writeFile(char * data){
        ::FILE * fp = ::fopen(ROOT, "w");
        ::fwrite(data, strlen(data),1,fp);
        ::fclose(fp);

    }

    /**
     * Delete a file
     * @param path
     */
    virtual void deleteFile(char * path) {
        int result = ::remove(path);
        (result ==0 ? cout<< "successfully deleted" << endl:cout << "error" );

    }

    /**
     * list files and directories of path
     * @param path
     * @return
     */

   virtual vector<char*> listFiles(char * path) {
        vector<char*> result;
        for (const auto & file : fs::directory_iterator(path)){
            char * pathResult = (char *)::malloc(file.path().string().size()+1);
            strcpy(pathResult,&file.path().string()[0]);
            result.push_back(pathResult);
        }
        return result;
    }

    /**
     * delete a folder
     * @param path
     */

    virtual void deleteFolder(char*path){
        if (folderExists(path)) {
            for (const auto & file : fs::directory_iterator(path)) {
                char * pathResult = (char *)::malloc(file.path().string().size());
                strcpy(pathResult,&file.path().string()[0]);
                if (isFile(pathResult)){
                    deleteFile(pathResult);
                }
                else if (isFolder(pathResult)){
                    deleteFolder(pathResult);
                }
            }

        }
        rmdir(path);
    }

    /**
     * create a folder
     * @param path
     */

    virtual void createFolder(char * path){
        int result = mkdir(path);
        (result== -1 ? cout << "Error"<<endl : cout << "File created"<<endl);
    }

    virtual bool folderExists(char * path){
        struct stat sb;
        bool finalResult;
        int result = stat(path, &sb);
        (result == 0 ? finalResult = true : finalResult = false);
        return finalResult;
    }

    virtual bool fileExists(char * path) {
        ::FILE * fp;
        bool result;
        (::fopen(path, "r") ? result = true : result=false);
        return result;
    }

    virtual bool isFolder(char * path) {
        struct stat s;
        bool result;
        if ( stat(path, &s) ==0){
            (s.st_mode & S_IFDIR ? result = true : result = false);
        }
        else {
            result=false;
        }
        return result;
    }

    virtual bool isFile(char * path) {
        struct stat s;
        bool result;
        if ( stat(path, &s) ==0){
            (s.st_mode & S_IFREG ? result = true : result =false);
        }
        else {
            result= false;
        }
        return result;

    }

};


#endif //SCHC_CONTRIBUTION_FILESTORAGE_H

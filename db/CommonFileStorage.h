//
// Created by Usuario on 16-01-2023.
//

#ifndef SCHC_CONTRIBUTION_COMMONFILESTORAGE_H
#define SCHC_CONTRIBUTION_COMMONFILESTORAGE_H

#include <FileStorage.h>
#include<fstream>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;



class CommonFileStorage: public FileStorage {
public:

    /**
     * constructor
     * @param path
     */

    explicit CommonFileStorage(char *root) : FileStorage(root) {}


};


#endif //SCHC_CONTRIBUTION_COMMONFILESTORAGE_H

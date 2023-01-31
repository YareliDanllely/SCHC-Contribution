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

    explicit CommonFileStorage(char *root);


};


#endif //SCHC_CONTRIBUTION_COMMONFILESTORAGE_H

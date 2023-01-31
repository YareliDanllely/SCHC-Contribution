#include "FileStorage.h"


FileStorage::FileStorage(char *root):ROOT(root) {}

char *FileStorage::joinPath(char *path) {

    if (strcmp(ROOT, "\0") == 0) {
        return path;
    }
    else if (strcmp(path, "\0") == 0) {
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
            }
            else {
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

int FileStorage::fileSize(char *path)  {
    ::FILE * fp = ::fopen(joinPath(path), "r");
    ::fseek(fp,1,SEEK_END);
    int size = ::ftell(fp)-1;
    ::fseek(fp,0,SEEK_SET);
    ::fclose(fp);
    return size;
}

char *FileStorage::readFile(char *path) {
    ::FILE * fp = ::fopen(joinPath(path), "r");
    if (fp==NULL) {
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

void FileStorage::writeFile(char *path, char *data) {
    ::FILE * fp = ::fopen(joinPath(path), "w");
    ::fwrite(data, strlen(data),1,fp);
    ::fclose(fp);
}

void FileStorage::deleteFile(char *path) {
    int result = ::remove(joinPath(path));
    (result ==0 ? cout<< "successfully deleted" << endl:cout << "error" );
}

vector<char *> FileStorage::listFiles(char *path)  {
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

void FileStorage::deleteFolder(char *path) {
    if (folderExists(path)) {
        if (not emptyFolder(path)) {
            for (const auto & file : fs::directory_iterator(joinPath(path))) {
                cout << file.path() <<endl;
                char * pathResult = (char *)::malloc(file.path().string().size()- (strlen(ROOT)+1));
                strcpy(pathResult,&file.path().string()[strlen(ROOT)+1]);

                if (isFile(pathResult)) {
                    deleteFile(pathResult);
                }
                else if (isFolder(pathResult)) {
                    deleteFolder(pathResult);
                }
            }
        }

    }
    rmdir(joinPath(path));

}

void FileStorage::createFolder(char *path) {
    if ( not folderExists(joinPath(path))) {
        if (strcmp(path,"\0")==0) {
            bool result = fs::create_directories(joinPath(ROOT));
            (result == false ? cout << "Error" << endl : cout << "File created" << endl);
        }
        else {
            bool result = fs::create_directories(joinPath(path));
            (result == false ? cout << "Error" << endl : cout << "File created" << endl);
        }
    }
}

bool FileStorage::folderExists(char *path) {
    struct stat sb;
    bool finalResult;
    int result = stat(joinPath(path), &sb);
    (result == 0 ? finalResult = true : finalResult = false);
    return finalResult;
}

bool FileStorage::fileExists(char *path) {
    bool result;
    (::fopen(joinPath(path), "r") ? result = true : result=false);
    return result;
}

bool FileStorage::isFolder(char *path) {
    struct stat s;
    bool result;
    if ( stat(joinPath(path), &s) ==0) {
        (s.st_mode & S_IFDIR ? result = true : result = false);
    }
    else {
        result=false;
    }
    return result;
}

bool FileStorage::isFile(char *path) {
    struct stat s;
    bool result;
    if ( stat(joinPath(path), &s) ==0) {
        (s.st_mode & S_IFREG ? result = true : result =false);
    }
    else {
        result= false;
    }
    return result;
}

bool FileStorage::emptyFile(char *path) {
    int size = fileSize(path);
    return fileExists(path) && size ==0;
}

bool FileStorage::emptyFolder(char *path)  {
    vector <char *> files = listFiles(path);
    return folderExists(path) && files.size()==0;
}
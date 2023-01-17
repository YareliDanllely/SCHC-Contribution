
#include "CommonFileStorage.h"


int main() {

    char path[] = "listFilesTest";
    FileStorage file(path);

    vector <char *> list = file.listFiles(path);

    file.deleteFolder(path);
    ::printf("%s\n", list[0]);





}
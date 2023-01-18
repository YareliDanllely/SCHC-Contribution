
#include "CommonFileStorage.h"


int main() {

    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    char patht[] = "dice\\asa";
    char test[] = "listFilesTest";
    CommonFileStorage file(ROOT);

    file.createFolder(patht);


    //cout << file.folderExists(path)<<endl;
    //cout << file.joinPath(path)<< endl;
    //cout << file.folderExists(path) <<endl;


    //int result = ::remove("listFilesTest\\imADirectory\\testTwo.txt");
    //(result ==0 ? cout<< "successfully deleted" << endl:cout << "error" );

     // vector <char *> list = file.listFiles(path);

    // char result[] = "listFilesTest\\hello.txt";
/*
    cout << strcmp(list[0],result) << endl;

    cout << "len"<<strlen(result) << endl;*/

    //::printf("%s\n", list[0]);

    /*::printf("resul %s\n", file.readFile("hello.txt"));

    cout << strlen(file.readFile("hello.txt")) <<endl;
    cout << file.fileSize("hello.txt") <<endl;



*/

return 0;



}
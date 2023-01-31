#include "gtest/gtest.h"
#include "CommonFileStorage.h"

TEST(cretaeAFileTest, dbTest){
    char path[] = "testDb.txt";
    CommonFileStorage file(path);
    ASSERT_EQ(strcmp(file.ROOT,path),0);
}

TEST(joinPathTest, dbTest) {
    char path[] = "listFilesTest";
    CommonFileStorage file(path);
    char result[] = "testOne.txt";

    ASSERT_TRUE(file.isFile(result));
}

TEST(joinPathTestTwo, dbTest) {
    char path[] = "\0";
    char root[] = "listFilesTest";
    CommonFileStorage file(root);

    ASSERT_EQ(strcmp(file.joinPath(path),file.ROOT),0);
}

TEST(joinPathTestThree, dbTest) {
    char path[] = "listFilesTest";
    char root[] = "\0";
    CommonFileStorage file(root);

    ASSERT_EQ(strcmp(file.joinPath(path),path),0);
}

TEST(filseSizeTest, dbTest){
    char path[] = "listFilesTest";
    CommonFileStorage file(path);
    char pathTwo[] = "testOne.txt";
    ASSERT_EQ(file.fileSize(pathTwo),5);
}

TEST(readFileTest, dbTest){
    char path[] = "listFilesTest";
    char test[]= "testOne.txt";
    CommonFileStorage file(path);
    ASSERT_EQ(strcmp(file.readFile(test),"hello"),0);
}

TEST(writeFileTest,dbTest){
    char str[]= "test db two";
    char ROOT[] = "listFilesTest";
    char path[] = "hello.tx";
    CommonFileStorage file(ROOT);
    file.writeFile(path,str);
    ASSERT_EQ(strcmp(file.readFile(path),"test db two"),0);
}

TEST(isFileTest, dbTest){
    char ROOT[] = "listFilesTest";
    char path[] = "testOne.txt";
    CommonFileStorage file(ROOT);
    ASSERT_TRUE(file.isFile(path));

    char pathTwo[] = "testdbdb.txt";
    CommonFileStorage fileTwo(ROOT);
    ASSERT_FALSE(fileTwo.isFile(pathTwo));
}

TEST(fileExistTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "testOne.txt";
    CommonFileStorage file(ROOT);
    ASSERT_TRUE(file.fileExists(path));

    char pathTwo[] = "testdbdb.txt";
    CommonFileStorage fileTwo(ROOT);
    ASSERT_FALSE(fileTwo.fileExists(pathTwo));
}

TEST(isFolderTest,dbTest){
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    CommonFileStorage file(ROOT);
    ASSERT_TRUE(file.isFolder(path));

    char pathTwo[] = "testDbDb";
    CommonFileStorage fileTwo(ROOT);
    ASSERT_FALSE(fileTwo.isFolder(pathTwo));
}

TEST(folderExistsTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    CommonFileStorage file(ROOT);
    ASSERT_TRUE(file.folderExists(path));

    char pathTwo[] = "listFilesTestTest";
    ASSERT_FALSE(file.folderExists(pathTwo));
}

TEST(createFolderTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory\\Direct";
    CommonFileStorage file(ROOT);

    file.createFolder(path);
    ASSERT_TRUE(file.folderExists(path));
}

TEST(createFolderTestTwo, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "\0";
    char test[] = "listFilesTest";
    CommonFileStorage file(ROOT);

    file.createFolder(path);
    ASSERT_TRUE(file.folderExists(test));
}

TEST(listFilesTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    CommonFileStorage file(ROOT);

    char result[] = "listFilesTest\\imADirectory\\testTwo.txt";

    vector <char*> list = file.listFiles(path);
    ASSERT_EQ(strcmp(list[0],result),0);
}

TEST(deleteFileTest, dbTest){
    char ROOT[] = "listFilesTest";
    char path[] = "testDbDelete.txt";
    CommonFileStorage file(ROOT);
    file.deleteFile(path);
    ASSERT_FALSE(file.isFile(file.ROOT));
}

TEST(deleteFolderTestOne, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    CommonFileStorage file(ROOT);

    ASSERT_TRUE(file.folderExists(path));
}

TEST(deleteFolderTestOneParTwo, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "imADirectory";
    CommonFileStorage file(ROOT);

    file.deleteFolder(path);
    ASSERT_FALSE(file.folderExists(path));
}

TEST(fileEmptyTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "listFilesTest\\emptyFile.txt";
    CommonFileStorage file(ROOT);

    ASSERT_TRUE(file.emptyFile(path));
}

TEST(folderEmptyTest, dbTest) {
    char ROOT[] = "listFilesTest";
    char path[] = "emptyDirectory";
    CommonFileStorage file(ROOT);

    ASSERT_TRUE(file.emptyFolder(path));
}

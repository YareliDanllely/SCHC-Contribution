#include "gtest/gtest.h"
#include "CommonFileStorage.h"


TEST(cretaeAFileTest, dbTest){
    char path[] = "testDb.txt";
    CommonFileStorage file(path);
    ASSERT_EQ(strcmp(file.ROOT,path),0);
}

TEST(filseSizeTest, dbTest){
    char path[] = "testDb.txt";
    CommonFileStorage file(path);
    ASSERT_EQ(file.fileSize(),8);
}

TEST(readFileTest, dbTest){
    char path[] = "testDb.txt";
    CommonFileStorage file(path);
    ASSERT_EQ(strcmp(file.readFile(),"test db"),0);
}

TEST(writeFileTest,dbTest){
    char str[]= "test db two";
    char path[] = "testDb.txt";
    CommonFileStorage file(path);
    file.writeFile(str);
    ASSERT_EQ(strcmp(file.readFile(),"test db two"),0);
}

TEST(isFileTest, dbTest){
    char path[] = "testDbDelete.txt";
    CommonFileStorage file(path);
    ASSERT_TRUE(file.isFile(file.ROOT));

    char pathTwo[] = "testdbdb.txt";
    CommonFileStorage fileTwo(pathTwo);
    ASSERT_FALSE(fileTwo.isFile(fileTwo.ROOT));
}

TEST(fileExistTest, dbTest) {
    char path[] = "testDbDelete.txt";
    CommonFileStorage file(path);
    ASSERT_TRUE(file.fileExists(file.ROOT));

    char pathTwo[] = "testdbdb.txt";
    CommonFileStorage fileTwo(pathTwo);
    ASSERT_FALSE(fileTwo.fileExists(fileTwo.ROOT));
}

TEST(deleteFileTest, dbTest){
    char path[] = "testDbDelete.txt";
    CommonFileStorage file(path);
    file.deleteFile(path);
    ASSERT_FALSE(file.isFile(file.ROOT));
}

TEST(isFolderTest,dbTest){
    char path[] = "listFilesTest";
    CommonFileStorage file(path);
    ASSERT_TRUE(file.isFolder(path));

    char pathTwo[] = "testDbDb";
    CommonFileStorage fileTwo(pathTwo);
    ASSERT_FALSE(fileTwo.isFolder(fileTwo.ROOT));
}

TEST(folderExistsTest, dbTest) {
    char path[] = "listFilesTest";
    CommonFileStorage file(path);
    ASSERT_TRUE(file.folderExists(path));

    char pathTwo[] = "listFilesTestTest";
    CommonFileStorage fileTwo(pathTwo);
    ASSERT_FALSE(fileTwo.folderExists(pathTwo));
}

TEST(createFolderTest, dbTest) {
    char path[] = "listFilesTestTwo";
    CommonFileStorage file(path);
    file.createFolder(path);
    ASSERT_TRUE(file.folderExists(path));
}

TEST(listFilesTest, dbTest) {
    char path[] = "listFilesTest";
    CommonFileStorage file(path);

    char result[] = "listFilesTest\testOne.txt";

    vector<char*> list = file.listFiles(path);
    ASSERT_EQ(strlen(list[1]),25);
    ASSERT_EQ(strlen(path),25);
    ASSERT_EQ(strcmp(list[1],result),0);
}


TEST(deleteFolderTestOne, dbTest) {
    char path[] = "listFilesTestTwo";
    CommonFileStorage file(path);
    ASSERT_TRUE(file.folderExists(path));
}

TEST(deleteFolderTestOneParTwo, dbTest) {
    char path[] = "listFilesTestTwo";
    CommonFileStorage file(path);

    file.deleteFolder(path);
    ASSERT_FALSE(file.folderExists(path));
}

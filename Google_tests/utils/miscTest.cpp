#include "gtest/gtest.h"
#include "misc.h"
#include <string>
#include <string.h>


TEST(zFillTest,miscTest) {
    char strTest[] = "test";
    char resulTest[] = "00000test";
    ASSERT_EQ(strcmp(resulTest, zfill(strTest,9)),0);
    ASSERT_EQ(strcmp(strTest, zfill(strTest,2)),0);
}

TEST(zPadTest,miscTest) {
    char strTest[] = "test";
    char resultTest[] = "test00000";
    ASSERT_EQ(strcmp(resultTest, zpad(strTest,9)),0);

}

TEST(replaceCharTest,miscTest) {
    char strTest[] = "1001111";
    char newChar[] = "1";
    char strResultTest[] = "1011111";

    char strTestTwo[] = "1001111";
    char strResultTestTwo[] = "10011111";

    ASSERT_EQ(strcmp(strResultTest, replaceChar(strTest,2,newChar)),0);
    ASSERT_EQ(strcmp(strResultTestTwo, replaceChar(strTestTwo,10,newChar)),0);

}

TEST(findTest,miscTest){
    char strTest[] = "1001011";
    char search[] = "1";
    vector<int> resultFind = find(strTest,search);
    vector<int> result = {0,3,5,6};

    ASSERT_EQ(result,resultFind);

}

TEST(isMonarch, miscTest) {
    char strTest[] = "1111111";
    char search[] = "1";
    char searchTwo[] = "0";
    char strTestTwo[] = "1111111";

    ASSERT_FALSE(is_monochar(strTest,searchTwo));
   /* ASSERT_TRUE(is_monochar(strTestTwo,search));*/
}

TEST(roundTONextMultiple,misc) {
    ASSERT_EQ(14, round_to_next_multiple(8,7));
    ASSERT_EQ(14, round_to_next_multiple(14,7));
    ASSERT_EQ(21, round_to_next_multiple(15,7));
    ASSERT_EQ(0, round_to_next_multiple(0,7));
    ASSERT_EQ(-14, round_to_next_multiple(-20,7));
}

TEST(invertDict, miscTest) {
    map<char,int> mapTest ={ {'a',1},{'b',2},{'c',3}};
    map<int,char> mapResult ={ {1,'a'},{2,'b'},{3,'c'}};
    ASSERT_EQ(mapResult, invert_dict(mapTest) );

}

TEST(invertDictCannotInverted, miscTest) {
    map<char,int> mapTest ={ {'a',1},{'b',1},{'c',3}};

    try {
        invert_dict(mapTest);
        FAIL();
    }
    catch (invalid_argument const & err){
        EXPECT_EQ(err.what(), string("Dictionary cannot be inverted"));
    }

}

TEST(sectionString, miscTest) {
    char charTest[] = "AAAABBCCCDDDDDD";
    vector<int> indices = {0,4,6,9};
    vector<char*> result = section_char(charTest,indices);
    ASSERT_EQ(strcmp(result[0],"AAAA"),0);
    ASSERT_EQ(strcmp(result[1],"BB"),0);
    ASSERT_EQ(strcmp(result[2],"CCC"),0);
    ASSERT_EQ(strcmp(result[3],"DDDDDD"),0);
}

/* the file is in the cmake-build-debug directory*/
TEST(geneneratePacket, miscTest){
    char strTest[] = "This is a test";
    char path[] = "packetTest.txt";

    generate_packet(strTest,path);

    int len = strlen(strTest);
    char readFile[len+1];

    ifstream myFile(path);
    myFile.read(readFile, len);
    myFile.close();

    ASSERT_EQ(strcmp(strTest,readFile),0);
}
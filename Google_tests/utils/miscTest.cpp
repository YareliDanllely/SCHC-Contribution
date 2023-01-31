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

TEST(findTestTest,miscTest){
    char strTest[] = "1001011";
    char search[] = "1";
    vector<int> resultFind = find(strTest,search);
    vector<int> result = {0,3,5,6};

    ASSERT_EQ(result,resultFind);

}

TEST(isMonarchTest, miscTest) {
    char strTest[] = "1111111";
    char searchTwo[] = "0";

    cout <<is_monochar(strTest,searchTwo)<<endl;

    char search[] = "1";
    ASSERT_TRUE(is_monochar(strTest,search));

    char strTestTwo[] = "101";
    ASSERT_FALSE(is_monochar(strTestTwo,search));

}

TEST(roundTONextMultipleTest,misc) {
    ASSERT_EQ(14, round_to_next_multiple(8,7));
    ASSERT_EQ(14, round_to_next_multiple(14,7));
    ASSERT_EQ(21, round_to_next_multiple(15,7));
    ASSERT_EQ(0, round_to_next_multiple(0,7));
    ASSERT_EQ(-14, round_to_next_multiple(-20,7));
}

TEST(invertDictTest, miscTest) {
    map<char,int> mapTest ={ {'a',1},{'b',2},{'c',3}};
    map<int,char> mapResult ={ {1,'a'},{2,'b'},{3,'c'}};
    ASSERT_EQ(mapResult, invert_dict(mapTest) );

}

TEST(invertDictCannotInvertedTest, miscTest) {
    map<char,int> mapTest ={ {'a',1},{'b',1},{'c',3}};

    try {
        invert_dict(mapTest);
        FAIL();
    }
    catch (invalid_argument const & err){
        EXPECT_EQ(err.what(), string("Dictionary cannot be inverted"));
    }

}

TEST(sectionStringTest, miscTest) {
    char charTest[] = "AAAABBCCCDDDDDD";
    vector<int> indices = {0,4,6,9};
    vector<char*> result = section_char(charTest,indices);
    ASSERT_EQ(strcmp(result[0],"AAAA"),0);
    ASSERT_EQ(strcmp(result[1],"BB"),0);
    ASSERT_EQ(strcmp(result[2],"CCC"),0);
    ASSERT_EQ(strcmp(result[3],"DDDDDD"),0);
}

TEST(geneneratePacketTest, miscTest){
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

TEST(cutCharTest, miscTes){
    char strTest[] = "1101010";
    char resultTest[] = "110";
    char resultTestTwo[] = "11010";
    char resultTestThree[] = "110";
    char resultTestFour[] = "10";

    ASSERT_EQ(strcmp(resultTest, cutChar(strTest,0,3)),0);
    ASSERT_EQ(strcmp(resultTestTwo, cutChar(strTest,0,5)),0);
    ASSERT_EQ(strcmp(resultTestThree, cutChar(strTest,0, strlen(strTest)-4)),0);
    ASSERT_EQ(strcmp(resultTestFour, cutChar(strTest, strlen(strTest)-2, strlen(strTest))),0);
}

TEST(severalCharTest, miscTest) {
    char charTest[] = "0";
    char result[] = "00000";
    ASSERT_EQ(strcmp(severalChar(5,charTest),result),0);

    char resultTwo[] = "111";
    char charTestTwo[] = "1";
    ASSERT_EQ(strcmp(severalChar(3,charTestTwo),resultTwo),0);
}

TEST(sumSeveralCharTest, miscTest) {
    char firstValue[] = "10101";
    char secondValue[] = "101";
    vector<char*> test = {firstValue,secondValue};
    ASSERT_EQ(8, sumSeveralChar(test));
}

TEST(joinBinariesTest, miscTest) {
    char firstValue[] = "10101";
    char secondValue[] = "101";
    char result[] = "10101101";
    vector<char*> test = {firstValue,secondValue};
    ASSERT_EQ(strcmp(joinBinaries(test),result),0);
}

TEST(getValueTest, miscTest) {
    char firstValue[] = "10";
    char secondValue[] = "101";
    char notValue[] = "1010";

    map<char*,int> test = {{firstValue,3},{secondValue,5}};
    ASSERT_EQ(getMapValue(test,firstValue,9),3);
    ASSERT_EQ(getMapValue(test,notValue,10),10);
}

TEST(itosTest, miscTest) {
    char firstValue[] = "65";
    char secondValue[] = "105";

    ASSERT_EQ(strcmp(firstValue,itos(65)),0);
    ASSERT_EQ(strcmp(secondValue,itos(105)),0);

}


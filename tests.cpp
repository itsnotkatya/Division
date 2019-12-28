//
// Created by Екатерина on 21/12/2019.
//
#include <stdexcept>
#include "gtest/gtest.h"
#include "lib.h"
#include <fstream>

TEST (Divide, divideByZero) {
    float n = 1;
    float m = 0;
    EXPECT_THROW(Divide(n,m), std::invalid_argument);
}

TEST (Divide,SuccsesfulDivision) {
    float n = 777;
    float m = 111;
    EXPECT_EQ(7,Divide(n, m));
}

TEST(readFile, NoneExistedFile) {
    float f[2];
    std::ifstream file ("../doesnt_exist.txt");
    EXPECT_THROW(readFile(file,f), std::runtime_error);
}

TEST(readFile, OnlyOneArgument) {
    float f[2];
    std::ifstream file("../file1.txt");
    EXPECT_THROW(readFile(file, f), std::domain_error);
}

TEST(readFile, NotEnoughArguments) {
    float f[2];
    std::ifstream file ("../file2.txt");
    EXPECT_THROW(readFile(file,f), std::domain_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

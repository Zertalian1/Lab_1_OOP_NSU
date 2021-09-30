#include "pch.h"
#include "../../Lab1/Lab1/Trit.h"
#include "../../Lab1/Lab1/Trit.cpp"
#include "../../Lab1/Lab1/TritSet.h"
#include "../../Lab1/Lab1/TritSet.cpp"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
}

TEST(tritset_tests, length) {
    Tritset set(10);
    ASSERT_EQ(set.length(), 10);
    set.shrink();
    ASSERT_EQ(set.length(), 0);
    set[0] = Trit(T);
    ASSERT_EQ(set.length(), 1);
}

TEST(tritset_tests, size) {
    Tritset set(20);
    size_t size = set.getsize();
    ASSERT_EQ(size, 0);
    set[0] = Trit(T);
    set.shrink();
    size = set.getsize();
    ASSERT_EQ(size, 1);
}
// как не выделять памяти( // топерь не выделяет

TEST(tritset_tests, logical) {
    Tritset set1(1), set2(1);
    set1[0] = Trit(T);
    set2[0] = Trit(F);
    ASSERT_EQ((set2 & set1).to_string(), "0???????????????");
    ASSERT_EQ((set2 | set1).to_string(), "1???????????????");
    ASSERT_EQ((~set2 | set1).to_string(), "1???????????????");
    set2[0] = Trit(U);
    ASSERT_EQ((set2 & set1).to_string(), "????????????????");
    ASSERT_EQ((set2 | set1).to_string(), "1???????????????");
    set1[0] = Trit(F);
    ASSERT_EQ((set2 & set1).to_string(), "0???????????????");
    ASSERT_EQ((set2 | set1).to_string(), "????????????????");
    set1[0] = Trit(U);
    ASSERT_EQ((set2 & set1).to_string(), "????????????????");
    ASSERT_EQ((set2 | set1).to_string(), "????????????????");
}
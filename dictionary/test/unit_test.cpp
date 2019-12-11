#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, add_0_103) {
    ArrayDictionary<int, int> hashTable(2);

    hashTable.add(0, 103);
    hashTable.add(1, 105);

    ASSERT_EQ(hashTable.size(), 2);
    int value;
    ASSERT_TRUE(hashTable.get(0, value));
    ASSERT_EQ(value, 103);

}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contains) {
    // homework
    ArrayDictionary<int, int> empty;
    ASSERT_FALSE(empty.contain(-1));
    ASSERT_FALSE(empty.contain(0));
    ASSERT_FALSE(empty.contain(1));
    ArrayDictionary<int, int> one(1);
    one.add(0, 103);
    ASSERT_FALSE(one.contain(2));
    ASSERT_TRUE(one.contain(0));
    ArrayDictionary<int, int> two(2);
    two.add(0, 103);
    two.add(1, 105);
    ASSERT_TRUE(two.contain(1));
    ASSERT_TRUE(two.contain(0));
    ASSERT_FALSE(two.contain(2));
    ASSERT_FALSE(two.contain(3));
    ArrayDictionary<int, int> three(3);
    three.add(1, 105);
    three.add(2, 206);
    three.add(4, 407);
    ASSERT_TRUE(three.contain(1));
    ASSERT_TRUE(three.contain(4));
    ASSERT_FALSE(three.contain(7));
    ASSERT_FALSE(three.contain(8));

    //ASSERT_TRUE(false); // placeholder
}

TEST(dict, remove) {
    // homework
    //remove from empty dictionary
    ArrayDictionary<int, int> empty;
    ASSERT_FALSE(empty.remove(3));
    //removes a present key in dictionary no collision
    empty.add(1, 70);
    ASSERT_TRUE(empty.remove(1));
    //removes a non present key in dictionary no collision
    ASSERT_FALSE(empty.remove(2));
    empty.add(11, 23);
    //remove a non present key in dictionary with collision
    ASSERT_FALSE(empty.remove(2));
    //remove key from collison in dictionary with collision
    ASSERT_TRUE(empty.remove(11));

   // ASSERT_TRUE(false); // placeholder
}

#include "LinkedList.h"
#include <gtest/gtest.h>

namespace{
    LinkedList<int> linkedListTest;
    TEST(AddTest, AddNoIndexInt){
        linkedListTest.add(-2);
        linkedListTest.add(-3);
        linkedListTest.add(-4);
        linkedListTest.add(-5);

        EXPECT_EQ(-2, linkedListTest.get(0));
        EXPECT_EQ(-3, linkedListTest.get(1));
        EXPECT_EQ(-4, linkedListTest.get(2));
        EXPECT_EQ(-5, linkedListTest.get(3));

        EXPECT_EQ(4, linkedListTest.size());
    }

    TEST(AddTest, AddIndexInt){
        linkedListTest.add(-2);
        linkedListTest.add(-3);
        linkedListTest.add(-4);
        linkedListTest.add(-5);
        linkedListTest.add(-6);

        linkedListTest.add(2, 4);
        EXPECT_EQ(2, linkedListTest.get(4));

        linkedListTest.add(3, 5);
        EXPECT_EQ(3, linkedListTest.get(5));

        linkedListTest.add(4, 1);
        EXPECT_EQ(4, linkedListTest.get(1));

        linkedListTest.add(5, 0);
        EXPECT_EQ(5, linkedListTest.get(0));      

        EXPECT_EQ(13, linkedListTest.size());  
    }

    TEST(RemoveTest, PopNoIndex){
        EXPECT_EQ(-6, linkedListTest.pop());
        EXPECT_EQ(12, linkedListTest.size());
    }

    // TEST(RemoveTest, PopIndex){

    // }

    TEST(RemoveTest, RemoveNoIndex){
        linkedListTest.remove(0);
        EXPECT_EQ(11, linkedListTest.size());
    }
}
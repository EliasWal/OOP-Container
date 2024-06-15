#include "gtest/gtest.h"
#include "Map.h"
#include "Vector.h" 
#include "ForwardList.h" 
#include "List.h"
#include "ListIterator.h"   


//Popa Maria-Eliza

// Test 1: Inserarea și accesarea elementelor
TEST(MapTest, InsertAndAccess) {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "Test";
    m[30] = "Poo";

    EXPECT_STREQ(m[10], "C++");
    EXPECT_STREQ(m[20], "Test");
    EXPECT_STREQ(m[30], "Poo");
}

// Test 2: Actualizarea unui element existent
TEST(MapTest, UpdateElement) {
    Map<int, const char*> m;
    m[10] = "C++";
    m[10] = "Updated";

    EXPECT_STREQ(m[10], "Updated");
}

// Test 3: Ștergerea unui element
TEST(MapTest, DeleteElement) {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "Test";
    EXPECT_TRUE(m.Delete(10));
    EXPECT_EQ(m.Count(), 1);
    const char* value;
    EXPECT_FALSE(m.Get(10, value));
    EXPECT_TRUE(m.Get(20, value));
    EXPECT_STREQ(value, "Test");
}

// Test 4: Curățarea containerului
TEST(MapTest, ClearContainer) {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "Test";
    m.Clear();
    EXPECT_EQ(m.Count(), 0);
    const char* value;
    EXPECT_FALSE(m.Get(10, value));
    EXPECT_FALSE(m.Get(20, value));
}

// Test 5: Includerea unui alt container
TEST(MapTest, IncludesContainer) {
    Map<int, const char*> m1;
    m1[10] = "C++";
    m1[20] = "Test";

    Map<int, const char*> m2;
    m2[10] = "C++";

    EXPECT_TRUE(m1.Includes(m2));
    m2[30] = "Poo";
    EXPECT_FALSE(m1.Includes(m2));
}

//Luca Stefan

TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.getCapacity(), 0);
    EXPECT_TRUE(vec.empty());
}

TEST(VectorTest, PushBackAndSize) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

TEST(VectorTest, FrontAndBack) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.front(), 1);
    EXPECT_EQ(vec.back(), 3);
}

TEST(VectorTest, InsertAndErase) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.insert(1, 2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 2);

    vec.erase(1);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[1], 3);
}

TEST(VectorTest, ResizeAndClear) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.resize(5);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[3], 0);  

    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_TRUE(vec.empty());
}

//Azoitei Paul

TEST(ForwardListTest, PushFrontTest) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 3);
}

TEST(ForwardListTest, PopFrontTest) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
}

TEST(ForwardListTest, FrontTest) {
    ForwardList<int> list;
    list.push_front(1);
    EXPECT_EQ(list.front(), 1);
    list.push_front(2);
    EXPECT_EQ(list.front(), 2);
}

TEST(ForwardListTest, SizeAndEmptyTest) {
    ForwardList<int> list;
    EXPECT_EQ(list.size(), 0);
    EXPECT_TRUE(list.empty());
    list.push_front(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_FALSE(list.empty());
}

TEST(ForwardListTest, ExceptionTest) {
    ForwardList<int> list;
    EXPECT_THROW(list.front(), std::out_of_range);
    EXPECT_THROW(list.pop_front(), std::out_of_range);
}

//Cristina Iftime

// Test pentru adăugarea elementelor la sfârșitul listei
TEST(ListTest, AddToTheEnd) {
    List<int> list;
    list.addToTheEnd(1);
    list.addToTheEnd(2);
    list.addToTheEnd(3);

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_FALSE(list.isEmpty());

    auto it = list.getHeadIterator();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

// Test pentru adăugarea elementelor la începutul listei
TEST(ListTest, AddToTheFront) {
    List<int> list;
    list.addToTheFront(1);
    list.addToTheFront(2);
    list.addToTheFront(3);

    EXPECT_EQ(list.GetSize(), 3);
    EXPECT_FALSE(list.isEmpty());

    auto it = list.getHeadIterator();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}

// Test pentru eliminarea elementului de la sfârșitul listei
TEST(ListTest, RemoveFromTheEnd) {
    List<int> list;
    list.addToTheEnd(1);
    list.addToTheEnd(2);
    list.addToTheEnd(3);
    list.removeFromTheEnd();

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_FALSE(list.isEmpty());

    auto it = list.getHeadIterator();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

// Test pentru eliminarea elementului de la începutul listei
TEST(ListTest, RemoveFromTheFront) {
    List<int> list;
    list.addToTheFront(1);
    list.addToTheFront(2);
    list.addToTheFront(3);
    list.removeFromTheFront();

    EXPECT_EQ(list.GetSize(), 2);
    EXPECT_FALSE(list.isEmpty());

    auto it = list.getHeadIterator();
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}

// Test pentru verificarea dacă lista este goală
TEST(ListTest, IsEmpty) {
    List<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.addToTheEnd(1);
    EXPECT_FALSE(list.isEmpty());

    list.removeFromTheEnd();
    EXPECT_TRUE(list.isEmpty());
}
 

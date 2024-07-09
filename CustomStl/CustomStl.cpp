#include <iostream>
#include "LinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "Unique_Pointer.cpp"
#include "Shared_Pointer.cpp"
#include "Weak_Pointer.cpp"

void TestList();
void TestDoublyLinkedList();
void TestUniquePointer();
void TestSharedPointer();
void TestSTLWeakPointer();
void TestWeakPointer();

int main()
{
    std::cout << "Hello World!\n";
    TestList();
    TestDoublyLinkedList();
    TestUniquePointer();
    TestSharedPointer();
    TestSTLWeakPointer();
    TestWeakPointer();
}

void TestList() {
    std::cout << "========================LinkedList=======================" << std::endl;
    LinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    std::cout << "l[1]: " << l[1] << std::endl; //2

    l.push_front(3);

    std::cout << "l[0]: " << l[0] << std::endl; //3

    l[0] = 5;

    std::cout << "l[0]: " << l[0] << std::endl; //5

    std::cout << "l.front(): " << l.front() << std::endl; //5
    std::cout << "l.back(): " << l.back() << std::endl; //2

    l.print();// 5 1 2

    std::cout << std::endl;
    std::cout << "count:  " << l.size() << std::endl; //0

    l.pop_front();
    l.pop_back();

    l.print();

    std::cout << std::endl;
    std::cout << "count:  " << l.size() << std::endl; //0

    std::cout << "Add 4s" << std::endl;
    l.push_front(4);
    l.push_back(4);
    l.print();
    std::cout << std::endl;
    std::cout << "size(): " << l.size() << std::endl; //0
    std::cout << "empty(): " << (l.empty() ? "true" : "false") << std::endl; //0

    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "========================LinkedList=======================" << std::endl << std::endl;
}


void TestDoublyLinkedList() {

    std::cout << "=====================DoublyLinkedList====================" << std::endl;
    DoublyLinkedList<int> dl;
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);
    dl.push_back(5);
    dl.push_back(6);
    dl.push_back(7);
    dl.push_back(0);
    dl.push_back(0);
    dl.push_back(0);
    dl.push_back(0);
    dl.push_back(0);
    dl.print();

    std::cout << "front(): " << dl.front() << std::endl;
    std::cout << "back(): " << dl.back() << std::endl;

    DoublyLinkedList<int>::Iterator it = dl.begin();
    DoublyLinkedList<int>::Iterator it2 = dl.begin();
    ++it;
    ++it;

    dl.advance(it2, 5);

    std::cout << "it(inclusive) : " << *it << std::endl;
    std::cout << "it2(exclusive): " << *it2 << std::endl;


    std::cout << "erase[it, it2)" << std::endl;
    dl.erase(it, it2);
    dl.print();


    std::cout << "remove(0)" << std::endl;
    dl.remove(0);
    dl.print();

    DoublyLinkedList<int>::Iterator it3 = dl.begin();
    DoublyLinkedList<int>::Iterator it4 = dl.end();
    ++it3;


    std::cout << "insert(begin+1, 100)" << std::endl;
    dl.insert(it3, 100);
    dl.print();
    std::cout << "insert(end, 1440)" << std::endl;
    dl.insert(it4, 1440);
    dl.print();
    std::cout << "=====================DoublyLinkedList====================" << std::endl << std::endl;
}

void TestUniquePointer() {
    std::cout << "======================Unique Pointer=====================" << std::endl;
    Unique_Pointer<int> p1(new int(5));

    std::cout << (p1.get() == nullptr) << std::endl;

    if (p1) {
        std::cout << "p1 is valid and its value is: " << *p1 << std::endl;
    }
    else {
        std::cout << "p1 is null" << std::endl;
    }

    p1.reset();

    if (!p1) {
        std::cout << "p1 is now null" << std::endl;
    }
}

void TestSharedPointer() {
    std::cout << "======================Shared Pointer=====================" << std::endl;
    Shared_Pointer<int> s1(new int(10));
    std::cout << *s1 << std::endl;
    if (s1) {
        std::cout << "s1 is valid :  " << *s1 << std::endl;
    } else {
        std::cout << "s1 is invalid" << std::endl;
    }

    Shared_Pointer<int> s2 = s1;
    if (s2) {
        std::cout << "s2 Valid" << std::endl;
    } else {
        std::cout << "s2 Invalid" << std::endl;
    }

    std::cout << s2.use_count() << std::endl;

    std::cout << s1.use_count() << std::endl;
    s2.reset();
    std::cout << s1.use_count() << std::endl;
}

void TestSTLWeakPointer() {
    std::cout << "=====================Weak STL Pointer====================" << std::endl;
    std::shared_ptr<int> s1(new int(10));
    std::shared_ptr<int> s2(s1);
    std::weak_ptr<int> wp(s1);
    std::cout << "wp ref count: " << wp.use_count() << std::endl;
    std::weak_ptr<int> wp2(wp);


    std::cout << "wp expired: " << (wp.expired() ? "true" : "false") << std::endl;
    std::cout << "wp locks: " << *wp.lock() << std::endl;

    s1.reset();
    std::cout << "s1 ref count: " << s1.use_count() << std::endl;
    std::cout << "wp ref count: " << wp.use_count() << std::endl;
    
    s2.reset();
    std::weak_ptr<int> wp3(wp);
    std::cout << "wp ref count: " << wp.use_count() << std::endl;

}

void TestWeakPointer() {
    std::cout << "=======================Weak Pointer======================" << std::endl;
    Shared_Pointer<int> s1(new int(10));

    //std::cout << w1.use_count() << std::endl;//1

    Shared_Pointer<int> s2(s1);
    Weak_Pointer<int> w1(s2);

    std::cout << *s2 << std::endl;
    std::cout << s2.use_count() << std::endl;//1


    std::cout << "wp lock" << *w1.lock() << std::endl;
    Shared_Pointer<int> s4;


    std::cout << "w1 use count: " << w1.use_count() << std::endl;
    std::cout << "s2 use count: " << s2.use_count() << std::endl;
    s1.reset();
    std::cout << "w1 use count: " << w1.use_count() << std::endl;
    std::cout << "s2 use count: " << s2.use_count() << std::endl;
    std::cout << "wp lock " << *w1.lock() << std::endl;

}
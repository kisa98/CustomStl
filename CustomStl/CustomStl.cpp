#include <iostream>
#include "LinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "Unique_Pointer.cpp"

void TestList();
void TestDoublyLinkedList();
void TestUniquePointer();

int main()
{
    std::cout << "Hello World!\n";
    TestList();
    TestDoublyLinkedList();
    TestUniquePointer();
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
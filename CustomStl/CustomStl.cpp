#include <iostream>
#include "LinkedList.cpp"

int main()
{
    std::cout << "Hello World!\n";
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
    l.clear();
    std::cout << "After clear() => empty(): " << (l.empty() ? "true" : "false") << std::endl; //0
}


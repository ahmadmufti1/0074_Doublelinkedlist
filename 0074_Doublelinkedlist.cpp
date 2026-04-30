#include <iostream>
#include <string>
using namespace std;

class Node { //Membuat class Node untuk menyimpan data mahasiswa
public:
    int noMhs;
    Node* prev;
    Node* next;
};

class DoubleLinkedList{ //Membuat class DoubleLinkedList untuk mengelola linked list
private:
    Node* START;

public:
    DoubleLinkedList()//untuk menginisialisasi linked list
    {
        START = NULL;
    }

};

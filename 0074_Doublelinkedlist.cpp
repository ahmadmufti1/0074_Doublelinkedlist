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

    void addNode() //untuk menambahkan node baru ke linked list
    {
        //cara kerja addNode adalah dengan meminta input dari pengguna untuk nomor mahasiswa, kemudian membuat node baru dengan nomor tersebut. Node baru akan ditempatkan pada posisi yang sesuai dalam linked list berdasarkan urutan nomor mahasiswa. Jika nomor mahasiswa sudah ada, maka akan ditampilkan pesan bahwa nomor duplikat tidak diperbolehkan. Setelah node baru ditambahkan, linked list akan tetap terurut berdasarkan nomor mahasiswa.
        int nim;
        cout << "Enter the roll number of the student: ";
        cin >> nim;

        Node* newNode = new Node();

        newNode->noMhs = nim;

        if(START == NULL || nim <= START->noMhs)
        {
            if(START != NULL && nim == START->noMhs)
            {
                cout << "Duplicate number not allowed." << endl;
                return;
            }

            newNode->next = START;

            if(START != NULL)
                START->prev = newNode;

            newNode->prev = NULL;

            START = newNode;
            return;
        }
        Node* current = START;
        while(current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if(current->next != NULL && nim == current->next->noMhs)
        {
            cout << "Duplicate roll numbers not allowed." << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if(current->next != NULL)
            current->next->prev = newNode;

            current->next = newNode;
    }

    void hapus() //void hapus adalah fungsi untuk menghapus node dari linked list
    {
        
    }

};

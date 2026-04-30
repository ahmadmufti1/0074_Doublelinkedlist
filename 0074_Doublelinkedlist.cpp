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
        //cara kerja hapus adalah dengan meminta input dari pengguna untuk nomor mahasiswa yang ingin dihapus. Fungsi akan mencari node dengan nomor tersebut dalam linked list. Jika node ditemukan, maka node tersebut akan dihapus dari linked list dan memori yang digunakan oleh node tersebut akan dibebaskan. Jika nomor mahasiswa tidak ditemukan, maka akan ditampilkan pesan bahwa nomor tidak ditemukan. Setelah node dihapus, linked list akan tetap terurut berdasarkan nomor mahasiswa.
        if(START == NULL)
        {
            cout << "\nList is empty." << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted : ";
        int rollNo;
        cin >> rollNo;

        Node* current = START;

        while(current != NULL && current->noMhs != rollNo)
        current = current->next;
        
        if(current == NULL)
        {
            cout << "Roll not found." << endl;
            return;
        }

        if(current == START)
        {
            START = current->next;
            if(START != NULL)
                START->prev = NULL;
        }
        else
        {
            current->prev->next = current->next;
            
            if(current->next != NULL)
                current->next->prev = current->prev;
        }
        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;           
    }

    void traverse() //void traverse adalah fungsi untuk menampilkan semua node dalam linked list
    {
        //cara kerja traverse adalah dengan memulai dari node pertama (START) dan menampilkan nomor mahasiswa dari setiap node secara berurutan hingga mencapai akhir linked list (NULL). Jika linked list kosong, maka akan ditampilkan pesan bahwa list kosong. Setelah menampilkan semua node, fungsi akan kembali ke menu utama.
        if(START == NULL)
        {
            cout << "\nList is empty." << endl;
            return;
        }

        Node* currentNode = START;

        cout << "\nRecords in ascending order of roll number are: \n" << endl;
        int i = 0;
        while(currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs<< " " << endl;
            currentNode = currentNode->next;
             i++;
        }
    }

    void revtraverse() //void revtraverse adalah fungsi untuk menampilkan semua node dalam linked list dalam urutan terbalik
    {
        
    }

};

#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
    int noMhs;
    Node *next;
};
class SingleLinklist {
    Node *START;

    public:
    SingleLinklist() {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;
    

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
            cout << "\nDuplikasi noMhs tidak di ijinkan\n";
            return;
            }
        nodeBaru->next = START;
        START = nodeBaru;
        return;
        }
    
        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        

            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

    
    }
    bool listempty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous, &current))
            return false;
        if (current == START)
            START = START->next;
        else
            previous->next = current->next;
        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData didalam list adalah: \n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

};

int main()
{
    SingleLinklist Mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
             << "Menu";
        cout << endl
             << "1. Menambahkan data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl
             << "Masukkan Pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
            case '1':
            {
                Mhs.addNode();
            }
            break;
            case '2':
            {
                if (Mhs.listempty())
                {
                    cout << endl
                        << "List Kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nMasukkan no mahasiswa yang akan di hapus : ";
                cin >> nim;
                if (Mhs.delNode(nim) == false)
                    cout << endl
                         << "Data tidak di temukkan" << endl;
                else
                cout << endl
                     << "Data dengan nomor mahasiswa " << nim << "Berhasil Di Hapus " << endl;
            }
        
            break;
            case '3':
            {
             Mhs.traverse();
            }
            break;

            case '4':
            {
                if (Mhs.listempty() == true)
                {
                    cout << "\nList Kosong\n";
                    break;
                }

                Node *previous, *current;

                cout << endl
                     << "Masukkan no mahasiswa yang ingin dicari : ";
                cin >> nim;
                if (Mhs.Search(nim, &previous, &current) == false)
                    cout << endl
                         << "Data tidak di temukan" << endl;
                else
                {
                    cout << endl
                         << "Data di temukkan" << endl;
                    cout << "\nNo Mahasiswa: " << current->noMhs << endl;
                    cout <<"\n";
                }
            }
            break;

            case '5':
            {
                exit(0);
            }
            break;
            default:
            {
                cout << "Pilihan Salah!!" << endl;
            }
            break;
        }
    }
}
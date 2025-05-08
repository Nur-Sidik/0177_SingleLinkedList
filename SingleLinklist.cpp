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
    

};
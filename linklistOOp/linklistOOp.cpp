#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int noMhs;
    char nama[20];
    Node* next;
};

class list {
    Node* START;
public:
    list();
    void addnode();
    bool Search(int nim, Node** current, Node** previous);
    bool listEmpty();
    bool delnode(int element);
    void traverse();
};

list::list() {
    START = NULL;
}

void list::addnode() /* Menambahkan Sebuah Node Kedalam List */
{
    int nim;
    char nm[20];
    cout << "\n Masukan Nomor Mahasiswa: ";
    cin >> nim;
    cout << "\n Masukan Nama";
    cin >> nm;

    Node* nodeBaru = new Node;
    nodeBaru->noMhs = nim;
    strcpy_s(nodeBaru->nama, nm);

    if (START == NULL || nim <= START->noMhs)
    {
        if ((START != NULL) && (nim == START->noMhs))
        {
            cout << "\n DUplikasi noMhs diijinkann\n";
            return;
        }
    }
    nodeBaru->next = START;
    START = nodeBaru;
    return;

    Node* previous, * current;

    current = START;
    previous = START;

    while ((current != NULL) && (nim >= current->noMhs))
    {
        if (nim == current->noMhs)
        {
            cout << "\nDuplikasi noMhs tidak diijikan\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    /*jika loop diatas dieksekusi, previous dan current akan menemapati posisi dimana */
        nodeBaru->next = current;
    previous->next = nodeBaru;
}

bool list::listEmpty()
{
    if (START == NULL)
        return true;
    else
        return false;
}
bool list::delnode(int nim)/* Menghapus node dari dalam list*/
{
    Node* current, * previous;
    if (Search(nim, &previous, &current) == false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = START->next;

    delete current;
    return true;
}

/* Chech apakah node yang dimaksud ada diddalam list atau tidak */
bool list::Search(int nim, Node * *previous, Node * *current)
{
    *previous = START;
    *current = START;
    while ((*current != NULL) && (nim != (*current)->noMhs)) {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void list::traverse() /* Mengunjungi dan membaca data dalam list */
{
    if (listEmpty())
        cout << "\n List Kosong\n";
    else
    {
        cout << endl << " Data didalam list adalah:" << endl;
        Node* currentNode;
        for (currentNode = START; currentNode != NULL; currentNode = currentNode->next) {
            cout << currentNode->noMhs << "  " << currentNode->nama << "/n";
        }
        cout << endl;
    }
}
int main()
{
    list mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl << "menu";
        cout << endl << " 1, menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list " << endl;
        cout << "3. menampilkan semua data didalam list " << endl;
        cout << " 4. mencari data dalam list" << endl;
        cout << " 5. keluar " << endl;
        cout << endl << " masukan pilihan (1-5):";
        cin >> ch;
      
#include <iostream>
#include <unordered_set>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menghapus duplikasi dalam linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        // Jika elemen telah ditemukan sebelumnya, hapus elemen tersebut
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            // Jika elemen belum ditemukan, tambahkan ke set
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama untuk menguji fungsi removeDuplicates
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 10);
    append(head, 12);
    append(head, 11);
    append(head, 11);
    append(head, 12);
    append(head, 11);
    append(head, 10);

    cout << "Linked list sebelum menghapus duplikasi: ";
    printList(head);

    // Menghapus duplikasi
    removeDuplicates(head);

    cout << "Linked list setelah menghapus duplikasi: ";
    printList(head);

    return 0;
}

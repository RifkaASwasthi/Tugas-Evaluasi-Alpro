#include <iostream>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddleNode(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        // Jika linked list kosong atau hanya memiliki satu elemen, tidak ada node tengah untuk dihapus
        return;
    }

    int length = getLength(head);
    int midIndex = length / 2;

    Node* current = head;
    Node* prev = nullptr;

    // Iterasi ke node sebelum node tengah
    for (int i = 0; i < midIndex; ++i) {
        prev = current;
        current = current->next;
    }

    // Hapus node tengah
    if (prev != nullptr) {
        prev->next = current->next;
        delete current;
    } else {
        // Jika prev tetap nullptr, itu berarti kita harus menghapus head
        head = head->next;
        delete current;
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

// Fungsi utama untuk menguji fungsi deleteMiddleNode
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Linked list sebelum menghapus node tengah: ";
    printList(head);

    // Menghapus node tengah
    deleteMiddleNode(head);

    cout << "Linked list setelah menghapus node tengah: ";
    printList(head);

    return 0;
}

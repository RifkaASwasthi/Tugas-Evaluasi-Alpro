#include <iostream>

using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk membalikkan linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Fungsi untuk mengecek apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // Linked list kosong atau hanya memiliki satu elemen, dianggap sebagai palindrom
        return true;
    }

    // Gunakan dua pointer untuk menemukan titik tengah linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Balikkan setengah kedua dari linked list
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;

    // Bandingkan setengah pertama dan setengah kedua untuk memastikan palindrom
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            // Linked list bukan palindrom
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Linked list adalah palindrom
    return true;
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

// Fungsi utama untuk menguji fungsi isPalindrome
int main() {
    Node* head = nullptr;

    // Menambahkan elemen-elemen ke linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);

    cout << "Linked list: ";
    printList(head);

    // Mengecek apakah linked list adalah palindrom
    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrom." << endl;
    } else {
        cout << "Linked list bukan palindrom." << endl;
    }

    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mensortir stack dengan nilai terkecil di atas
void sortStack(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        // Pindahkan item dari temporary stack ke stack asli yang lebih kecil dari temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Salin isi temporary stack ke stack asli
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Fungsi untuk mencetak stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;

    // Menambahkan elemen-elemen ke stack
    myStack.push(30);
    myStack.push(-5);
    myStack.push(18);
    myStack.push(10);
    myStack.push(2);

    cout << "Stack sebelum disorting: ";
    printStack(myStack);

    // Mensortir stack
    sortStack(myStack);

    cout << "Stack setelah disorting: ";
    printStack(myStack);

    return 0;
}

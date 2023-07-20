#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a new node at the end of the doubly linked list
void insertEnd(Node* &head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to search for an element in the doubly linked list
bool searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true; // Element found
        }
        temp = temp->next;
    }
    return false; // Element not found
}

// Function to display the doubly linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Doubly linked list: ";
    display(head);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    if (searchElement(head, key)) {
        cout << "Element found in the list." << endl;
    } else {
        cout << "Element not found in the list." << endl;
    }

    return 0;
}

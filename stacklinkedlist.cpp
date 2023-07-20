#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int getTop() {
        if (!isEmpty()) {
            return top->data;
        }
        return -1; // Return a default value for an empty stack (can be modified as per requirement)
    }

    void print() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory used by the linked list
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack S;
    S.push(10);
    S.push(45);
    S.push(1);
    S.push(50);

    std::cout << "Current stack: ";
    S.print();
    std::cout << "Top element: " << S.getTop() << std::endl;

    S.pop();
    S.pop();

    std::cout << "Current stack: ";
    S.print();
    std::cout << "Top element: " << S.getTop() << std::endl;

    return 0;
}

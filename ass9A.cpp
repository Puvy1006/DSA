#include <iostream>
#include <string>
using namespace std;

struct Node {
    int token;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!empty()) {
            dequeue();
        }
    }

    bool empty() {
        return (rear == nullptr);
    }

    void enqueue() {
        int token;
        cout << "Enter the token number: ";
        cin >> token;

        Node* newnode = new Node;
        newnode->token = token;
        newnode->next = nullptr;

        if (empty()) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        cout << "Token " << token << " added to the waitlist.\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "The waitlist is empty.\n";
            return;
        }

        Node* ptr = front;
        cout << "Seating token no.: " << ptr->token << endl;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        delete ptr;
    }

    void display() {
        if (empty()) {
            cout << "The waitlist is empty.\n";
            return;
        }

        cout << "Current Waitlist Tokens:\n";
        Node* ptr = front;
        while (ptr != nullptr) {
            cout << ptr->token << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\n--- Waitlist Menu ---\n";
        cout << "1. Add Party\n";
        cout << "2. Seat Party\n";
        cout << "3. Display Waitlist\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

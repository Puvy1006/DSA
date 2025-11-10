#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    char data;   // to store each character
    Node* next;  // pointer to the next node
};

// Linked list class
class LinkedList {
private:
    Node* head;  // start of the list

public:
    LinkedList() {
        head = nullptr;  // initially empty
    }

    // Function to insert a character at the end
    void insert(char ch) {
        Node* newNode = new Node;
        newNode->data = ch;
        newNode->next = nullptr;

        if (head == nullptr) {
            // if list is empty, new node becomes head
            head = newNode;
        } else {
            // otherwise, find the last node and attach new one
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all nodes
    void display() {
        Node* temp = head;
        cout << "Characters in linked list: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Insert each letter as a node
    for (char ch : str) {
        list.insert(ch);
    }

    // Display the linked list
    list.display();

    return 0;
}

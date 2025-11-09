#include<iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class TextEditor {
    Node* head;
    Node* tail;

public:
    TextEditor() {
        head = nullptr;
        tail = nullptr;
    }

    void insertText(string text) {
        Node* newNode = new Node(text);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted: " << text << endl;
    }

    void deleteText(string text) {
        if (head == nullptr) {
            cout << "No text to delete." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != text) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Text not found." << endl;
            return;
        }

        if (temp == head)
            head = head->next;
        if (temp == tail)
            tail = tail->prev;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Deleted text: " << text << endl;
    }

    void displayText() {
        if (head == nullptr) {
            cout << "No text to display." << endl;
            return;
        }

        Node* temp = head;
        cout << "Text Editor Content:\n";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void searchText(string text) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == text) {
                cout << "Text found: " << text << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Text not found." << endl;
    }

    void printReverse() {
        if (tail == nullptr) {
            cout << "No text to display in reverse." << endl;
            return;
        }

        Node* temp = tail;
        cout << "Text in Reverse:\n";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    string text;
    bool running = true;

    while (running) {
        cout << "\nSelect an option:\n";
        cout << "1. Insert text\n";
        cout << "2. Delete text\n";
        cout << "3. Display text\n";
        cout << "4. Search text\n";
        cout << "5. Print text in reverse\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter text to insert: ";
                cin >> text;
                editor.insertText(text);
                break;
            case 2:
                cout << "Enter text to delete: ";
                cin >> text;
                editor.deleteText(text);
                break;
            case 3:
                editor.displayText();
                break;
            case 4:
                cout << "Enter text to search: ";
                cin >> text;
                editor.searchText(text);
                break;
            case 5:
                editor.printReverse();
                break;
            case 6:
                cout << "Exiting Text Editor." << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

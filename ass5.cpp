#include<iostream>
using namespace std;

class Node {
public:
    string routeName;
    Node* next;

    Node(string name) {
        routeName = name;
        next = nullptr;
    }
};

class NavigationSystem {
    Node* head;

public:
    NavigationSystem() {
        head = nullptr;
    }

    void addRoute(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            head->next = head;  // Point to itself (circular)
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

        cout << "Route '" << name << "' added successfully." << endl;
    }

    void removeRoute(string name) {
        if (head == nullptr) {
            cout << "No routes to remove." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Case 1: Only one route
        if (head->next == head && head->routeName == name) {
            delete head;
            head = nullptr;
            cout << "Route '" << name << "' removed successfully." << endl;
            return;
        }

        // Traverse the circular list
        do {
            if (curr->routeName == name) {
                if (prev != nullptr)
                    prev->next = curr->next;
                else {
                    // Removing head node
                    Node* temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    temp->next = head->next;
                    head = head->next;
                }
                delete curr;
                cout << "Route '" << name << "' removed successfully." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Route not found." << endl;
    }

    void displayRoutes() {
        if (head == nullptr) {
            cout << "No routes available." << endl;
            return;
        }

        Node* temp = head;
        cout << "Delivery Routes:\n";
        do {
            cout << temp->routeName << " --> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to Start)" << endl;
    }
};

int main() {
    NavigationSystem nav;
    int choice;
    string name;
    bool running = true;

    while (running) {
        cout << "\nSelect an option:\n";
        cout << "1. Add Route\n";
        cout << "2. Remove Route\n";
        cout << "3. Display Routes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter route name: ";
                cin >> name;
                nav.addRoute(name);
                break;
            case 2:
                cout << "Enter route name to remove: ";
                cin >> name;
                nav.removeRoute(name);
                break;
            case 3:
                nav.displayRoutes();
                break;
            case 4:
                cout << "Exiting navigation system." << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

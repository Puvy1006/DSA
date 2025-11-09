#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;  // Hash table size

// Structure for each employee node
struct Employee {
    int id;
    string name;
    Employee* next;
};

// Hash function
int hashFunction(int id) {
    return id % SIZE;
}

// Insert employee into hash table (with collision handling using chaining)
void insert(Employee* hashTable[], int id, string name) {
    int index = hashFunction(id);
    Employee* newEmp = new Employee{id, name, nullptr};

    if (hashTable[index] == nullptr) {
        // No collision
        hashTable[index] = newEmp;
    } else {
        // Collision — add to the end of the chain
        Employee* temp = hashTable[index];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newEmp;
    }
}

// Search for employee by ID
void search(Employee* hashTable[], int id) {
    int index = hashFunction(id);
    Employee* temp = hashTable[index];

    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Employee Found: " << temp->name << " (ID: " << temp->id << ")\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Employee not found.\n";
}

// Display hash table contents
void display(Employee* hashTable[]) {
    cout << "\n--- Hash Table Contents ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << i << "] -> ";
        Employee* temp = hashTable[i];
        if (temp == nullptr)
            cout << "Empty";
        while (temp != nullptr) {
            cout << "(" << temp->id << ", " << temp->name << ")";
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

int main() {
    Employee* hashTable[SIZE] = {nullptr};
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        string name;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        insert(hashTable, id, name);
    }

    cout << "\nEmployee Database Created Successfully.\n";
    display(hashTable);

    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    search(hashTable, searchID);

    return 0;
}

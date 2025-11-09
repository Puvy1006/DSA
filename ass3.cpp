#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* next;
};

// Function to create a new node
Node* createNode(const string &data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

// Insert at start
void insertAtStart(Node*& head, const string &data) {
	Node* newNode = createNode(data);
	newNode->next = head;
	head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, const string &data) {
	Node* newNode = createNode(data);
	if (head == nullptr) {
    	head = newNode;
    	return;
	}
	Node* ptr = head;
	while (ptr->next != nullptr) {
    	ptr = ptr->next;
	}
	ptr->next = newNode;
}

// Insert at position
void insertAtPosition(Node*& head, const string &data, int position) {
	if (position == 1) {
    	insertAtStart(head, data);
    	return;
	}

	Node* newNode = createNode(data);
	Node* ptr = head;

	for (int i = 1; i < position - 1 && ptr != nullptr; i++) {
    	ptr = ptr->next;
	}

	if (ptr == nullptr) {
    	cout << "Position out of bounds, inserting at end instead.\n";
    	insertAtEnd(head, data);
    	return;
	}

	newNode->next = ptr->next;
	ptr->next = newNode;
}

// Search
void search_key(Node* head, const string &key) {
	Node* current = head;
	int pos = 1;

	while (current != nullptr) {
    	if (current->data == key) {
        	cout << "Key found, congratulations! At position " << pos << "." << endl;
        	return;
    	}
    	current = current->next;
    	pos++;
	}
	cout << "Key not found in the list." << endl;
}

// Delete at start
void deleteAtStart(Node*& head) {
	if (head == nullptr) {
    	cout << "List is empty.\n";
    	return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	cout << "Deleted node at start.\n";
}

// Delete at end
void deleteAtEnd(Node*& head) {
	if (head == nullptr) {
    	cout << "List is empty.\n";
    	return;
	}

	if (head->next == nullptr) {
    	delete head;
    	head = nullptr;
    	cout << "Deleted only node in list.\n";
    	return;
	}

	Node* ptr = head;
	while (ptr->next->next != nullptr) {
    	ptr = ptr->next;
	}

	delete ptr->next;
	ptr->next = nullptr;
	cout << "Deleted node at end.\n";
}

// Delete at position
void deleteAtPosition(Node*& head, int position) {
	if (head == nullptr) {
    	cout << "List is empty.\n";
    	return;
	}

	if (position == 1) {
    	deleteAtStart(head);
    	return;
	}

	Node* ptr = head;
	for (int i = 1; i < position - 1 && ptr != nullptr; i++) {
    	ptr = ptr->next;
	}

	if (ptr == nullptr || ptr->next == nullptr) {
    	cout << "Position out of bounds.\n";
    	return;
	}

	Node* temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
	cout << "Deleted node at position " << position << ".\n";
}

// Print list
void printList(Node* head) {
	Node* ptr = head;
	cout << "Linked List: ";
	while (ptr != nullptr) {
    	cout << ptr->data << " -> ";
    	ptr = ptr->next;
	}
	cout << "NULL\n";
}

int main() {
	Node* head = nullptr;
	int choice, position;
	string data;
           	cout<<"Welcome to Puvy's customisable playlist";
	while (true) {
    	cout << "\n1. Insert at start\n2. Insert at end\n3. Insert at position\n";
    	cout << "4. Delete at start\n5. Delete at end\n6. Delete at position\n";
    	cout << "7. Display\n8. Search element\n9. Exit\nEnter your choice: ";
    	cin >> choice;

    	if (choice == 1) {
        	cout << "Lets go!! Which song do u want to insert at start: ";
        	cin >> data;
        	insertAtStart(head, data);
    	}
    	else if (choice == 2) {
        	cout << "Which song would u like to end your playlist with<3: ";
        	cin >> data;
        	insertAtEnd(head, data);
    	}
    	else if (choice == 3) {
        	cout << "Umm..thinking of inserting a song in betweeen : ";
        	cin >> data;
        	cout << "Ur wish our command <3 Enter the position you want to insert the song at: ";
        	cin >> position;
        	insertAtPosition(head, data, position);
    	}
    	else if (choice == 4) {
        	cout << "Bored of the same songs , Wannna delete a song from start: ";
        	cin >> data;
        	deleteAtStart(head);
    	}
    	else if (choice == 5) {
         	cout << "Ooo wait did u wanted to delete the song from end: ";
        	cin >> data;
        	deleteAtEnd(head);
    	}
    	else if (choice == 6) {
        	cout << "Umm..sorry sorry deleting from any position : ";
        	cin >> data;
        	cout << "Enter position to delete (1-based): ";
        	cin >> position;
        	deleteAtPosition(head, position);
    	}
    	else if (choice == 7) {
        	cout << "Ohh we are ready , let see our playlist now : ";
        	cin >> data;
        	printList(head);
    	}
    	else if (choice == 8) {
        	string key;
        	cout << "Wanna search a song , enter the key: ";
        	cin >> key;
        	search_key(head, key);
    	}
    	else if (choice == 9) {
        	cout << "Thank you, see you never.\n";
        	break;
    	}
    	else {
        	cout << "Invalid choice! Try again.\n";
    	}
	}

	// Clean up
	while (head != nullptr) {
    	Node* ptr = head;
    	head = head->next;
    	delete ptr;
	}

	return 0;
}

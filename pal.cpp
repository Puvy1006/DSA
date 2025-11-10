#include <iostream>
#include <string>
using namespace std;

// Node structure for stack
struct Node {
    char data;
    Node* next;
};

// Stack class definition
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push a character onto the stack
    void push(char ch) {
        Node* newNode = new Node;
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    // Pop a character from the stack
    char pop() {
        if (top == nullptr) {
            return '\0'; // empty stack
        }
        char ch = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return ch;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check palindrome using stack
bool isPalindrome(string str) {
    Stack s;

    // Push all characters of the string into the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop from stack and compare with original string
    for (char ch : str) {
        if (ch != s.pop()) {
            return false; // mismatch → not a palindrome
        }
    }
    return true; // all matched → palindrome
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}

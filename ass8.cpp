#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    string exp;

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isempty()) {
            Pop();
        }
    }

    void Push(char c) {
        Node* newnode = new Node;
        newnode->data = c;
        newnode->next = top;
        top = newnode;
    }

    char Pop() {
        if (isempty()) return '\0';
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }

    bool isempty() {
        return (top == nullptr);
    }

    int priority(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    string reverseFlip(const string& expr) {
        string rev = "";
        for (int i = expr.length() - 1; i >= 0; i--) {
            char c = expr[i];
            if (c == '(') rev += ')';
            else if (c == ')') rev += '(';
            else if (c == '{') rev += '}';
            else if (c == '}') rev += '{';
            else if (c == '[') rev += ']';
            else if (c == ']') rev += '[';
            else rev += c;
        }
        return rev;
    }

    string reverseString(const string& expr) {
        string rev = "";
        for (int i = expr.length() - 1; i >= 0; i--)
            rev += expr[i];
        return rev;
    }

    string infixToPostfix(const string& expr) {
        string output = "";
        for (char c : expr) {
            if (isalnum(c)) {
                output += c;
            }
            else if (c == '(' || c == '{' || c == '[') {
                Push(c);
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!isempty() && priority(c) <= priority(top->data)) {
                    if (top->data == '(' || top->data == '{' || top->data == '[') break;
                    output += Pop();
                }
                Push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                while (!isempty() && !(top->data == '(' || top->data == '{' || top->data == '[')) {
                    output += Pop();
                }
                if (!isempty()) {
                    Pop(); // remove opening bracket
                }
                else {
                    cout << "\nError: Unbalanced expression.";
                }
            }
            else {
                cout << "\nInvalid character: " << c;
                return "";
            }
        }
        while (!isempty()) {
            if (top->data == '(' || top->data == '{' || top->data == '[') {
                cout << "\nError: Unbalanced expression.";
                return "";
            }
            output += Pop();
        }
        return output;
    }

    string infixToPrefix(const string& expr) {
        string result = reverseFlip(expr);
        result = infixToPostfix(result);
        result = reverseString(result);
        return result;
    }
};

int main() {
    Stack s;
    int choice;
    string infix;

    do {
        cout << "\n INFIX CONVERSION MENU ";
        cout << "\n1. Enter Expression";
        cout << "\n2. Convert Infix to Postfix";
        cout << "\n3. Convert Infix to Prefix";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the infix expression: ";
                cin >> s.exp;
                break;

            case 2:
                if (s.exp.empty())
                    cout << "Please enter an expression first!\n";
                else
                    cout << "Postfix Expression: " << s.infixToPostfix(s.exp) << endl;
                break;

            case 3:
                if (s.exp.empty())
                    cout << "Please enter an expression first!\n";
                else
                    cout << "Prefix Expression: " << s.infixToPrefix(s.exp) << endl;
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}


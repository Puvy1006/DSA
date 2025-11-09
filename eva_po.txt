#include <iostream>
#include <string>
using namespace std;

int stackArr[50];
int top = -1;

void push(int val) { stackArr[++top] = val; }
int pop() { return stackArr[top--]; }

int evaluatePostfix(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            push(ch - '0'); // convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return stackArr[top];
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}

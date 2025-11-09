#include <iostream>
#include <string>
using namespace std;

int stackArr[50];
int top = -1;

void push(int val) { stackArr[++top] = val; }
int pop() { return stackArr[top--]; }

int evaluatePrefix(string exp) {
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } else {
            int val1 = pop();
            int val2 = pop();

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
    cout << "Enter prefix expression: ";
    cin >> exp;

    cout << "Result: " << evaluatePrefix(exp) << endl;
    return 0;
}

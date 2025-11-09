#include<iostream>
using namespace std;


class Stack {
    string* stk;  
    int capacity; 
    int top;


    void resize() {
        int newCapacity=capacity*2;
        string* newStk=new string[newCapacity];
        for(int i=0;i<=top;i++) {
            newStk[i]=stk[i];
        }
        delete[] stk;
        stk=newStk;
        capacity=newCapacity;
    }


public:
    Stack() {
        capacity=2;
        stk=new string[capacity];
        top=-1;
    }


    ~Stack() {
        delete[] stk;
    }


    void addVisitedPage(const string& page) {
        if(top==capacity-1) {
            resize();
        }
        stk[++top]=page;
        cout<<"Visited: "<<page<<endl;
    }


    void navigateBack() {
        if(isEmpty()) {
            cout<<"No previous pages to go back to."<<endl;
        } else {
            cout<<"Navigating back from: "<<stk[top]<<endl;
            top--;
        }
    }


    void viewCurrentPage() {
        if(isEmpty()) {
            cout<<"No pages in history."<<endl;
        } else {
            cout<<"Current page: "<<stk[top]<<endl;
        }
    }


    bool isEmpty() {
        return top==-1;
    }


    void displayHistory() {
        if(isEmpty()) {
            cout<<"History is empty."<<endl;
        } else {
            cout<<"Browsing History:\n";
            for(int i=0;i<=top;i++) {
                cout<<stk[i]<<" --> ";
            }
            cout<<"END"<<endl;
        }
    }
};


int main() {
    Stack browserHistory;
    int choice;
    string page;
    bool running=true;


    while(running) {
        cout<<"\nSelect an option:\n";
        cout<<"1. Add visited page\n";
        cout<<"2. Navigate back\n";
        cout<<"3. View current page\n";
        cout<<"4. Check if history is empty\n";
        cout<<"5. Display full history\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;


        switch(choice) {
            case 1:
                cout<<"Enter page URL: ";
                cin>>page;
                browserHistory.addVisitedPage(page);
                break;
            case 2:
                browserHistory.navigateBack();
                break;
            case 3:
                browserHistory.viewCurrentPage();
                break;
            case 4:
                if(browserHistory.isEmpty()) {
                    cout<<"History is empty."<<endl;
                } else {
                    cout<<"History is not empty."<<endl;
                }
                break;
            case 5:
                browserHistory.displayHistory();
                break;
            case 6:
                cout<<"Exiting browser history manager."<<endl;
                running=false;
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}

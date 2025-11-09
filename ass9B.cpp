#include <iostream>
#include <string>
using namespace std;

class Queue{
	public:
	int coustomer[4];
	int F;
	int R;
	
	Queue(){
		F = -1;
		R = -1;
	}
	
	int empty(){
		if (R == -1){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	int full(){
		if ((R+1)%4 == F){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	void enqueue(){
		int token;
		cout << "Enter the token number: " ;
		cin >> token;
		
		if(full() == 1){
			cout << "The queue is full.\n ";
		}
		else if(empty() == 1){
			F = (F+1)%4;
			R = (R+1)%4;
			coustomer[R] = token;
		}
		else{
			R = (R+1)%4;
			coustomer[R] = token;
		}
	}
	
	void dequeue(){		
		if(empty() == 1){
			cout<<"The queue is empty."<<endl;
		}
		else if(F == R){
			cout << "Token no.: " << coustomer[F] << endl;
			F = -1;
			R = -1;
		}	
		else {
			cout << "Token no.: " << coustomer[F] << endl;
			F = (F+1)%4;
		}
	}
	
	void close(){
		cout << "Closing counter..." <<endl;
		while(!empty()){
			dequeue();
		}
		cout << "Counter closed.\n" ;
	}
	
	void display(){
		int ptr = F;
		while(ptr != -1){
			if(F == R){
				cout << "Token no.: " << coustomer[ptr] << endl;
				ptr=-1;
			}	
			else {
				cout << "Token no.: " << coustomer[ptr] << endl;
				if(ptr == R){
					ptr = -1;
				}
				else{	
					ptr = (ptr+1)%4;
				}
			}
		}
		if(empty() == 1){
			cout<<"The queue is empty."<<endl;
			ptr=-1;
		}
	}
};

int main(){
	Queue q;
	int choice;
	
	do {
        cout << "\nSupermarket Checkout Counter:\n";
        cout << "1. Customer arrival\n";
        cout << "2. Customer checkout\n";
        cout << "3. Close Checkout Counter\n";
        cout << "4. View Counter\n";
        cout << "0. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.close();
            break;
        case 4:
            q.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

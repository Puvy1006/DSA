#include <iostream>
#include <string>
using namespace std;

class Student {
	int rollNo;
	string name;
	float sgpa;

public:
	void input() {
    	cout << "Enter roll number: ";
    	cin >> rollNo;
    	cin.ignore();
    	cout << "Enter name: ";
    	getline(cin, name);
    	cout << "Enter SGPA: ";
    	cin >> sgpa;
    	cin.ignore();  
	}

	void display() const {
    	cout << "\nStudent Details:" << endl;
    	cout << "Roll No: " << rollNo << endl;
    	cout << "Name: " << name << endl;
    	cout << "SGPA: " << sgpa << endl;
	}

	string getName() const {
    	return name;
	}

	void searchStudents(Student* students, int n, const string& key) const {
    	int i = 0;
    	while (i < n) {
        	if (students[i].name == key) {
            	cout << "\nStudent found:";
            	students[i].display();
            	break;
        	}
        	i++;
    	}
    	if (i == n) {
        	cout << "\nNo student found with the name \"" << key << "\"." << endl;
    	}
	}

	void shell_sort(Student* students, int n) const {
    	for (int gap = n / 2; gap > 0; gap /= 2) {
        	for (int i = gap; i < n; i++) {
            	Student temp = students[i];
            	int j;
           	 
            	for (j = i; j >= gap && students[j - gap].name > temp.name; j -= gap) {
                	students[j] = students[j - gap];
            	}
       	 
            	students[j] = temp;
        	}
    	}
    	cout << "\nStudents sorted by name successfully.\n";
	}
};

int main() {
	int n, ch;
	cout << "Enter number of students: ";
	cin >> n;
	cin.ignore();  

	Student* students = new Student[n];
	Student temp;  
	do {
    	cout << "\n\t1. Create"
         	<< "\n\t2. Display"
         	<< "\n\t3. Search by Name"
         	<< "\n\t4. Sort by Name"
         	<< "\nEnter your choice: ";
    	cin >> ch;
    	cin.ignore();

    	switch (ch) {
        	case 1:
            	for (int i = 0; i < n; i++) {
                	cout << "\nEnter details for student " << i + 1 << ":" << endl;
                	students[i].input();
            	}
            	break;

        	case 2:
            	cout << "\nDisplaying student details:\n";
            	for (int i = 0; i < n; i++) {
                	students[i].display();
            	}
            	break;

        	case 3: {
            	string keyword;
            	cout << "\nEnter name to search: ";
            	getline(cin, keyword);
            	temp.searchStudents(students, n, keyword);
            	break;
        	}

        	case 4:
            	temp.shell_sort(students, n);
            	cout << "\nDisplaying sorted student details:\n";
            	for (int i = 0; i < n; i++) {
                	students[i].display();
            	}
            	break;

        	default:
            	cout << "\nInvalid choice. Please try again.\n";
            	break;
    	}
    	cout << "\nDo you want to continue? (Enter 1 for Yes): ";
    	cin >> ch;
    	cin.ignore();  

	} while (ch == 1);

	delete[] students;
	return 0;
}

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
    	for (; i < n; i++) {
        	if (students[i].name == key) {
            	cout << "\nStudent found:";
            	students[i].display();
            	break;
        	}
    	}
    	if (i == n) {
        	cout << "\nNo student found with the name \"" << key << "\"." << endl;
    	}
	}
	// Insertion sort
	void sortByName(Student* students, int n) {
    	for (int i = 1; i < n; ++i) {
        	Student key = students[i];
        	int j = i - 1;

        	while (j >= 0 && students[j].name > key.name) {
            	students[j + 1] = students[j];
            	j--;
        	}
        	students[j + 1] = key;
    	}

    	cout << "\nStudents sorted by name successfully.\n";
	}
};

int main() {
	int n, choice, continue1;

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
    	cin >> choice;
    	cin.ignore();

    	switch (choice) {
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
            	temp.sortByName(students, n);
            	cout << "\nSorted student list:\n";
            	for (int i = 0; i < n; i++) {
                	students[i].display();
            	}
            	break;
        	default:
            	cout << "\nInvalid choice. Please try again.\n";
            	break;
    	}
    	cout << "\nDo you want to continue? (Enter 1 for Yes): ";
    	cin >> continue1;
    	cin.ignore();

	} while (continue1 == 1);

	delete[] students;
return 0;
}

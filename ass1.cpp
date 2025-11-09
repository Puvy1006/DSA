//Shell, insertion,Radix sort
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
	int getRollNo() const {
    	return rollNo;
	}
	float getSGPA() const {
    	return sgpa;
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
	void insertion_sort(Student* students, int n) const {
    	for (int i = 1; i < n; i++) {
        	Student key = students[i];
        	int j = i - 1;
        	while (j >= 0 && students[j].sgpa > key.sgpa) {
            	students[j + 1] = students[j];
            	j--;
        	}
        	students[j + 1] = key;
    	}
    	cout << "\nStudents sorted by SGPA successfully.\n";
	}
	int getMaxRoll(Student* students, int n) const {
    	int max = students[0].rollNo;
    	for (int i = 1; i < n; i++) {
        	if (students[i].rollNo > max)
            	max = students[i].rollNo;
    	}
    	return max;
	}
	void countSort(Student* students, int n, int exp) const {
    	Student* output = new Student[n];
    	int count[10] = {0};
    	for (int i = 0; i < n; i++)
        	count[(students[i].rollNo / exp) % 10]++;
    	for (int i = 1; i < 10; i++)
        	count[i] += count[i - 1];
    	for (int i = n - 1; i >= 0; i--) {
        	output[count[(students[i].rollNo / exp) % 10] - 1] = students[i];
        	count[(students[i].rollNo / exp) % 10]--;
    	}
    	for (int i = 0; i < n; i++)
        	students[i] = output[i];
    	delete[] output;
	}
	void radix_sort(Student* students, int n) const {
    	int maxRoll = getMaxRoll(students, n);
    	for (int exp = 1; maxRoll / exp > 0; exp *= 10)
        	countSort(students, n, exp);
    	cout << "\nStudents sorted by Roll Number using Radix Sort.\n";
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
         	<< "\n\t4. Sort by Name (Shell Sort)"
         	<< "\n\t5. Sort by SGPA (Insertion Sort)"
         	<< "\n\t6. Sort by Roll Number (Radix Sort)"
         	<< "\nEnter your choice: ";
    	cin >> ch;
    	cin.ignore();
    	if (ch == 1) {
        	for (int i = 0; i < n; i++) {
            	cout << "\nEnter details for student " << i + 1 << ":\n";
            	students[i].input();
        	}
    	}
    	else if (ch == 2) {
        	cout << "\nDisplaying student details:\n";
        	for (int i = 0; i < n; i++) {
            	students[i].display();
        	}
    	}
    	else if (ch == 3) {
        	string keyword;
        	cout << "\nEnter name to search: ";
        	getline(cin, keyword);
        	temp.searchStudents(students, n, keyword);
    	}
    	else if (ch == 4) {
        	temp.shell_sort(students, n);
        	cout << "\nDisplaying sorted student details:\n";
        	for (int i = 0; i < n; i++) {
            	students[i].display();
        	}
    	}
    	else if (ch == 5) {
        	temp.insertion_sort(students, n);
        	cout << "\nDisplaying sorted student details:\n";
        	for (int i = 0; i < n; i++) {
            	students[i].display();
        	}
    	}
    	else if (ch == 6) {
        	temp.radix_sort(students, n);
        	cout << "\nDisplaying sorted student details:\n";
        	for (int i = 0; i < n; i++) {
            	students[i].display();
        	}
    	}
    	else {
        	cout << "\nInvalid choice. Please try again.\n";
    	}
    	cout << "\nDo you want to continue? (Enter 1 for Yes): ";
    	cin >> ch;
    	cin.ignore();
	} while (ch == 1);
	delete[] students;
	return 0;
}

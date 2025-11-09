#include <iostream>
using namespace std;
 class Student {
public:
	int rollNo;
	char name[50];
	float sgpa;
	void input() {
    	cout << "Enter Roll No: ";
    	cin >> rollNo;
    	cout << "Enter Name: ";
    	cin >> name;
    	cout << "Enter SGPA: ";
    	cin >> sgpa;
	}
	void display() {
    	cout << rollNo << "\t" << name << "\t" << sgpa << "\n";
	}
};
int getMax(Student s[], int n) {
	int max = (int)(s[0].sgpa * 100);
	int i = 1;
	while (i < n) {
    	int val = (int)(s[i].sgpa * 100);
    	if (val > max) {
        	max = val;
    	}
    	i = i + 1;
	}
	return max;
}
void countSort(Student s[], int n, int exp) {
	Student output[50];
	int count[10];
	int i = 0;
	while (i < 10) {
    	count[i] = 0;
    	i = i + 1;
	}
	i = 0;
	while (i < n) {
    	int val = (int)(s[i].sgpa * 100);
    	int index = (val / exp) % 10;
    	count[index] = count[index] + 1;
    	i = i + 1;
	}
	i = 1;
	while (i < 10) {
    	count[i] = count[i] + count[i - 1];
    	i = i + 1;
	}
	i = n - 1;
	while (i >= 0) {
    	int val = (int)(s[i].sgpa * 100);
    	int index = (val / exp) % 10;
    	output[count[index] - 1] = s[i];
    	count[index] = count[index] - 1;
    	i = i - 1;
	}
	i = 0;
	while (i < n) {
    	s[i] = output[i];
    	i = i + 1;
	}
}
 int main() {
	Student s[50];
	int n;
	cout << "Enter number of students (at least 15): ";
	cin >> n;
	if (n < 15) {
    	n = 15;
    	cout << "Setting number of students to 15.\n";
	}
	int i = 0;
	while (i < n) {
    	cout << "\nEnter details of student " << (i + 1) << ":\n";
    	s[i].input();
    	i = i + 1;
	}
	int max = getMax(s, n);
	int exp = 1;
	while (max / exp > 0) {
    	countSort(s, n, exp);
    	exp = exp * 10;
	}
	cout << "\nTop 10 Students by SGPA (Radix Sort):\n";
	cout << "RollNo\tName\tSGPA\n";
	i = n - 1;
	int count = 0;
	while (i >= 0 && count < 10) {
    	s[i].display();
    	i = i - 1;
    	count = count + 1;
	}
	return 0;
}

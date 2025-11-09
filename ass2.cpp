#include <iostream>
#include <string>
using namespace std;
class Employee 
{
private:
int emp_id;
string name;
float salary;
public:
void input() //function to take input from user
{
cout << "Enter Employee name: ";
cin >> name;
cout << "Enter Employee ID: ";
cin >> emp_id;
cout << "Enter Salary: ";
cin >> salary;
cout << endl<<endl;
}

void display() //function to display info 
{
cout << "Employee Name: " << name << endl;
cout << "Employee ID  : " << emp_id << endl;
cout << "Salary       : " << salary << endl << endl;
}

int partition(Employee emp[], int low, int high) //helping function for quick sort 
{
int pivot = emp[low].emp_id;
int i = low;
int j = high;

while (i < j) 
{
while (i <= high && emp[i].emp_id <= pivot)
{
i++;
}
while (j >= low && emp[j].emp_id > pivot)
{

j--;

}

if (i < j)

{

swap(emp[i], emp[j]);

}

}

swap(emp[low], emp[j]);

return j;


}



void quickSort(Employee emp[], int low, int high) //Quick sort wrt emp ID

{

if (low < high) 

{

int pi = partition(emp, low, high);

quickSort(emp, low, pi - 1);

quickSort(emp, pi + 1, high);

}

}


void merge(Employee emp[], int lb, int mid, int ub) //merge function for merge sort

{

int i = lb;

int j = mid + 1;

int k = 0;


Employee temp[20];


while (i <= mid && j <= ub) 

{

if (emp[i].name <= emp[j].name) 

{

temp[k] = emp[i];

k++;

i++;

} 

else 

{

temp[k] = emp[j];

k++;

j++;

}

}


while (i <= mid) 

{

temp[k] = emp[i];

k++;

i++;

}


while (j <= ub) 

{

temp[k] = emp[j];

k++;

j++;

}


for (int m = 0; m < k; m++) 

{

emp[lb + m] = temp[m];

}

}



void merge_sort(Employee emp[], int lb, int ub) //merge sort wrt emp name

{

if (lb < ub) 

{

int mid = (lb + ub) / 2;

merge_sort(emp, lb, mid);

merge_sort(emp, mid + 1, ub);

merge(emp, lb, mid, ub);

}

}


};



int main() 

{

const int MAX = 20;

Employee employees[MAX]; //Creating object array of class

int n;


cout << "Enter number of Employees: ";

cin >> n;


int choice;


do 

{

cout << "Menu:" << endl;

cout << "1. Input Employees" << endl;

cout << "2. Display Employees" << endl;

cout << "3. Sort Employees by ID (Quick Sort)" << endl;

cout << "4. Merge sort by name" << endl;

cout << "Enter choice: ";

cin >> choice;

cout << endl << endl;



switch (choice) 

{

case 1: //For taking input from user

for (int i = 0; i < n; ++i) 

{

cout << "Enter details for employee " << i + 1 << ": " << endl;

employees[i].input();

}

break;


case 2: //for displaying the info

cout << "Employee Details:" << endl << endl;

for (int i = 0; i < n; ++i)

{

employees[i].display();

}

break;


case 3: //For Quick sort wrt emp ID

employees[0].quickSort(employees, 0, n - 1);

cout << "Employees sorted by ID." << endl << endl;

for (int i = 0; i < n; ++i)

{

employees[i].display();

}

break;


case 4: //For Merge sort wrt emp name

employees[0].merge_sort(employees, 0, n - 1);

cout << "Merge sort: " << endl;

for (int i = 0; i < n; ++i)

{

employees[i].display();

}

break;
default:
cout << "Exiting menu."<<endl;
}
} 
while (choice == 1 || choice == 2 || choice == 3 || choice == 4);
return 0;

}


//Quick sort on employee’s data program
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int rollNo;
    string name;
    int empID;
    string empName;
    double empSalary;

    void input() {
        cout << "Enter employee ID: ";
        cin >> empID;
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, empName);
        cout << "Enter employee salary: ";
        cin >> empSalary;
        cin.ignore();  
    }

    void display() {
        cout << empID << "\t" << empName << "\t\t" << empSalary << "\n";
    }
};

void searchemployees(Employee* employees, int n, const string& key) {
    int i = 0;
    while (i < n) {
        if (employees[i].name == key) {
            cout << "\nEmployee found:";
            employees[i].display();
            return; 
        }
        i++;
    }
    cout << "\nNo employee found with the name \"" << key << "\"." << endl;
}

// Swap function
void swap(Employee &a, Employee &b) {
    Employee temp = a;
    a = b;
    b = temp;
}

// Partition function for QuickSort
int partition(Employee arr[], int low, int high) {
    int pivot = arr[high].empID;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].empID <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(Employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, ch;
    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();  

    Employee* employees = new Employee[n];
    do {
        cout << "\n\t1. Create"
             << "\n\t2. Display"
             << "\n\t3. Search by Name"
             << "\n\t4. Sort Employees"
             << "\nEnter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for employee " << i + 1 << ":" << endl;
                    employees[i].input();
                }
                break;

            case 2:
                cout << "\nDisplaying employee details:\n";
                for (int i = 0; i < n; i++) {
                    employees[i].display();
                }
                break;

            case 3: {
                string keyword;
                cout << "\nEnter name to search: ";
                getline(cin, keyword);
                searchemployees(employees, n, keyword);
                break;
            }

            case 4:
                quickSort(employees, 0, n - 1);
                cout << "\nDisplaying sorted employee details:\n";
                for (int i = 0; i < n; i++) {
                    employees[i].display();
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

    delete[] employees;
    return 0;
}


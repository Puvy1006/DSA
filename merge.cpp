//Merge sort on employee’s data program
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
        if (employees[i].name == key || employees[i].empName == key) {
            cout << "\nEmployee found:\n";
            employees[i].display();
            return;
        }
        i++;
    }
    cout << "\nNo employee found with the name \"" << key << "\"." << endl;
}

// Merge function
void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].empID <= R[j].empID) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

// Merge Sort function
void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
             << "\n\t4. Sort Employees by ID (Merge Sort)"
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
                mergeSort(employees, 0, n - 1);
                cout << "\nDisplaying sorted employee details by ID:\n";
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

#include <iostream>
using namespace std;

struct Job {
    int id;
    string name;
    int priority;
    Job *next, *prev;
};

class JobScheduler {
    Job *front, *rear;

public:
    JobScheduler() {
        front = rear = NULL;
    }

    void addJob() {
        Job *temp = new Job;
        cout << "\nEnter Job ID: ";
        cin >> temp->id;
        cout << "Enter Job Name: ";
        cin >> temp->name;
        cout << "Enter Priority (1=High, 2=Low): ";
        cin >> temp->priority;
        temp->next = temp->prev = NULL;

        if (front == NULL) {
            front = rear = temp;
        } 
        else if (temp->priority == 1) {   // High priority -> front
            temp->next = front;
            front->prev = temp;
            front = temp;
        } 
        else {                            // Low priority -> rear
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        cout << "Job Added!\n";
    }

    void removeJob() {
        if (front == NULL) {
            cout << "No jobs to remove!\n";
            return;
        }
        int ch;
        cout << "Remove from (1.Front / 2.Rear): ";
        cin >> ch;
        if (ch == 1) {
            Job *t = front;
            cout << "Removing Job ID: " << t->id << endl;
            front = front->next;
            if (front) front->prev = NULL;
            delete t;
        } else {
            Job *t = rear;
            cout << "Removing Job ID: " << t->id << endl;
            rear = rear->prev;
            if (rear) rear->next = NULL;
            delete t;
        }
    }

    void displayJobs() {
        if (front == NULL) {
            cout << "No jobs in queue!\n";
            return;
        }
        cout << "\nJobID\tName\tPriority\n";
        Job *temp = front;
        while (temp) {
            cout << temp->id << "\t" << temp->name << "\t" 
                 << (temp->priority == 1 ? "High" : "Low") << endl;
            temp = temp->next;
        }
    }

    void searchJob() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }
        int id; bool found = false;
        cout << "Enter Job ID to search: ";
        cin >> id;
        Job *temp = front;
        while (temp) {
            if (temp->id == id) {
                cout << "Job Found -> Name: " << temp->name 
                     << ", Priority: " << (temp->priority==1?"High":"Low") << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) cout << "Job not found!\n";
    }
};

int main() {
    JobScheduler js;
    int ch;
    do {
        cout << "\n1.Add Job\n2.Remove Job\n3.Display Jobs\n4.Search Job\n5.Exit\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: js.addJob(); break;
            case 2: js.removeJob(); break;
            case 3: js.displayJobs(); break;
            case 4: js.searchJob(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(ch != 5);
    return 0;
}

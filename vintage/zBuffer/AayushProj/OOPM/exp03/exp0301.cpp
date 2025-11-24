#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

class Student {
private:
    int rn;
    string name;
    float marks[3];
    float total, avg;
    char grade;
    static int count;

public:
    Student() {
        rn = 0;
        name = "";
        total = 0.0f;
        avg = 0.0f;
        grade = 'F';
        for (int i = 0; i < 3; i++) marks[i] = 0.0f;
        count++;
    }

    void input() {
        cout << "Roll no: ";
        cin >> rn;
        cout << "Name: ";
        getline(cin >> ws, name);
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }

    void calculate() {
        total = 0.0f;
        for (int i = 0; i < 3; i++) total += marks[i];
        avg = total / 3.0f;

        if (avg >= 90) grade = 'A';
        else if (avg >= 75) grade = 'B';
        else if (avg >= 50) grade = 'C';
        else grade = 'F';
    }

    void display() const {
        cout << "Roll number: " << rn << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) cout << marks[i] << " ";
        cout << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }

    float T() const { return total; }
    int   R() const { return rn; }

    static void showc() {
        cout << "\nTotal Student objects: " << count << endl;
    }
};

int Student::count = 0;

// sort by total marks (descending)
void sort(Student* s, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].T() < s[j].T()) {
                swap(s[i], s[j]);
            }
        }
    }
}

// linear search by roll number
void search(Student* s, int n, int roll) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].R() == roll) {
            cout << "\nStudent found:\n";
            s[i].display();
            found = true;
            break;
        }
    }
    if (!found) cout << "\nStudent with roll " << roll << " not found.\n";
}

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    Student* s = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nDetails of student " << i + 1 << endl;
        s[i].input();
        s[i].calculate();
    }

    cout << "\nRecord:\n";
    for (int i = 0; i < n; i++) s[i].display();

    cout << "\nSorted by marks:\n";
    sort(s, n);
    for (int i = 0; i < n; i++) s[i].display();

    int roll;
    cout << "\nEnter roll number to search: ";
    cin >> roll;
    search(s, n, roll);

    Student::showc();
    delete[] s;
    return 0;
}

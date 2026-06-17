#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    string email;

    Student() {}

    Student(int i, string n, string e) {
        id = i;
        name = n;
        email = e;
    }
};

class StudentManager {
private:
    vector<Student> students;
    string filename = "students.txt";

public:
    StudentManager() {
        loadFromFile();
    }

    void loadFromFile() {
        students.clear();
        ifstream file(filename);

        Student s;
        while (file >> s.id >> s.name >> s.email) {
            students.push_back(s);
        }

        file.close();
    }

    void saveToFile() {
        ofstream file(filename);

        for (auto &s : students) {
            file << s.id << " " << s.name << " " << s.email << endl;
        }

        file.close();
    }

    void addStudent() {
        int id;
        string name, email;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Email: ";
        cin >> email;

        students.push_back(Student(id, name, email));
        saveToFile();

        cout << "Student added successfully\n";
    }

    void viewStudents() {
        if (students.empty()) {
            cout << "No records found\n";
            return;
        }

        for (auto s : students) {
            cout << s.id << " | " << s.name << " | " << s.email << endl;
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (auto s : students) {
            if (s.id == id) {
                cout << "Found: " << s.id << " | " << s.name << " | " << s.email << endl;
                return;
            }
        }

        cout << "Not found\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); it++) {
            if (it->id == id) {
                students.erase(it);
                saveToFile();
                cout << "Deleted successfully\n";
                return;
            }
        }

        cout << "Not found\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (auto &s : students) {
            if (s.id == id) {
                cout << "Enter new name: ";
                cin >> s.name;
                cout << "Enter new email: ";
                cin >> s.email;

                saveToFile();
                cout << "Updated successfully\n";
                return;
            }
        }

        cout << "Not found\n";
    }
};

int main() {
    StudentManager sm;
    int choice;

    while (true) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.viewStudents(); break;
            case 3: sm.searchStudent(); break;
            case 4: sm.deleteStudent(); break;
            case 5: sm.updateStudent(); break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
using namespace std;

struct Subject {
    string name;
    int hours;
    string priority;
};

vector<Subject> subjects;

void saveToFile() {
    ofstream file("planner.txt");
    for (auto s : subjects) {
        file << s.name << "," << s.hours << "," << s.priority << endl;
    }
}

void loadFromFile() {
    ifstream file("planner.txt");
    string name, priority;
    int hours;

    while (getline(file, name, ',')) {
        file >> hours;
        file.ignore();
        getline(file, priority);
        subjects.push_back({name, hours, priority});
    }
}

void addSubject() {
    Subject s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter subject name: ";
    getline(cin, s.name);

    cout << "Enter study hours: ";
    cin >> s.hours;

    cout << "Enter priority (High/Medium/Low): ";
    cin >> s.priority;

    subjects.push_back(s);
    saveToFile();

    cout << "Added successfully\n";
}

void viewSubjects() {
    if (subjects.empty()) {
        cout << "No subjects added\n";
        return;
    }

    int i = 1;
    for (auto s : subjects) {
        cout << i++ << ". " << s.name << " | "
             << s.hours << " hrs | "
             << s.priority << endl;
    }
}

void searchSubject() {
    string findSub;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter subject to search: ";
    getline(cin, findSub);

    bool found = false;

    for (auto s : subjects) {
        if (s.name == findSub) {
            cout << s.name << " | " << s.hours << " hrs | " << s.priority << endl;
            found = true;
        }
    }

    if (!found) cout << "Not found\n";
}

void deleteSubject() {
    int index;
    cout << "Enter number to delete: ";
    cin >> index;

    if (index >= 1 && index <= subjects.size()) {
        subjects.erase(subjects.begin() + index - 1);
        saveToFile();
        cout << "Deleted\n";
    } else {
        cout << "Invalid index\n";
    }
}

void sortSubjects() {
    sort(subjects.begin(), subjects.end(), [](Subject a, Subject b) {
        return a.name < b.name;
    });
    cout << "Sorted A-Z\n";
}

int main() {
    loadFromFile();

    int choice;

    do {
        cout << "\n       Smart Study Planner     \n";
        cout << "1. Add Subject\n";
        cout << "2. View Subjects\n";
        cout << "3. Search Subject\n";
        cout << "4. Delete Subject\n";
        cout << "5. Sort Subjects\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addSubject();
        else if (choice == 2) viewSubjects();
        else if (choice == 3) searchSubject();
        else if (choice == 4) deleteSubject();
        else if (choice == 5) sortSubjects();
        else if (choice == 6) cout << "Exiting...\n";
        else cout << "Invalid choice\n";

    } while (choice != 6);

    return 0;
}
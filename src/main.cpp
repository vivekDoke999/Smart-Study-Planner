#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    cout << "Welcome to Smart Study Planner" << endl;

    int n;
    vector<string> newsubject;

    do {
        cout << "\n1. study plan" << endl;
        cout << "2. view study plan" << endl;
        cout << "3. search subject" << endl;
        cout << "4. exit" << endl;

        cout << "enter number 1 to 4: ";
        cin >> n;

        if(n == 1){
            cout << "Enter subject name: ";
            string subject;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, subject);

            newsubject.push_back(subject);
            cout << "Subject added!" << endl;
        }

        else if(n == 2){
            cout << "Total subjects: " << newsubject.size() << endl;

            int i = 1;
            for(string x : newsubject){
                cout << i++ << ". " << x << endl;
            }
        }

        else if(n == 3){
            string findSub;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter subject to search: ";
            getline(cin, findSub);

            bool found = false;

            for(string x : newsubject){
                if(x == findSub){
                    found = true;
                    break;
                }
            }

            if(found){
                cout << "Subject found!" << endl;
            } else {
                cout << "Subject not found" << endl;
            }
        }

        else if(n == 4){
            cout << "Exiting..." << endl;
        }

        else{
            cout << "Invalid input!" << endl;
        }

    } while(n != 4);

    cout << "Good Bye" << endl;
    return 0;
}
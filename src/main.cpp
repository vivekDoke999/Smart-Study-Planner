#include <iostream>
#include<limits>
#include<vector>
using namespace std;

int main() {
    cout << "Welcome to Smart Study Planner" << endl;
        int n;
         vector<string>newsubject;
   do{
    cout<<"1. ";
    cout<<" study plan"<<endl;
    cout<<"2. ";
    cout<<"view study plan"<<endl;
    cout<<"3. ";
    cout<<"exit"<<endl;
       cout<<"enter number 1 to 3 :";
    cin>>n;
    if(n==1){
        cout<<"study plan"<<endl;
    }
    else if(n==2){
        cout<<"view study plan"<<endl;
    }
    else if(n==3){
        cout<<"exit"<<endl;
    }
    else{
        cout<<"invalid";
    }
     if (n==1)
    {
    cout<<"subject name ?? "<<endl;
    string subject;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, subject);
     cout<<"subject confirm"<<endl;
    newsubject.push_back(subject);
}
else if(n==2){
    for(string x:newsubject){
        cout<<x<<endl;
    }
}
     
     
 }

    while(n!=3);
    cout<<"Good Bye";
    
   
    return 0;
}
